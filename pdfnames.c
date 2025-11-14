/* This is dvipdfmx, an eXtended version of dvipdfm by Mark A. Wicks.

    Copyright (C) 2002-2020 by Jin-Hwan Cho and Shunsaku Hirata,
    the dvipdfmx project team.
    
    Copyright (C) 1998, 1999 by Mark A. Wicks <mwicks@kettering.edu>

    Copyright (C) 2014-2025 by The SILE Typesetter (as libtexpdf).

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.
    
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    
    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA.
*/

#include "libtexpdf.h"

#include <ctype.h>
#include <math.h>
#include <string.h>

#include "system.h"
#include "mem.h"
#include "error.h"
#include "numbers.h"

/* Hash */
#include "dpxutil.h"

#include "pdfobj.h"

#include "pdfnames.h"

#include "dvipdfmx.h"

struct obj_data
{
  pdf_obj *reference;
  pdf_obj *object;
  int closed;            /* 1 if object is closed */
};

static char *
printable_key (const char *key, int keylen)
{
#define MAX_KEY 32
  static char pkey[MAX_KEY+4];
  int    i, len;
  unsigned char hi, lo;

  for (i = 0, len = 0;
       i < keylen && len < MAX_KEY; i++) {
    if (isprint((unsigned char)key[i])) {
      pkey[len++] = key[i];
    } else {
      hi = (key[i] >> 4) & 0xff;
      lo =  key[i] & 0xff;
      pkey[len++] = '#';
      pkey[len++] = (hi < 10) ? hi + '0' : (hi - 10) + 'A';
      pkey[len++] = (lo < 10) ? lo + '0' : (lo - 10) + 'A';
    }
  }
  pkey[len] = '\0';

  return (char *) pkey;
}

static inline void
hval_free (void *hval)
{
  struct obj_data *value;

  value = (struct obj_data *) hval;

  if (value->reference) {
    texpdf_release_obj(value->reference);
    value->reference = NULL;
  }
  if (value->object) {
    texpdf_release_obj(value->object);
    value->object    = NULL;
  }

  RELEASE(value);

  return;
}

struct ht_table *
texpdf_new_name_tree (void)
{
  struct ht_table *names;

  names = NEW(1, struct ht_table);
  texpdf_ht_init_table(names, hval_free);

  return names;
}

static void
check_objects_defined (struct ht_table *ht_tab)
{
  struct ht_iter iter;

  if (ht_set_iter(ht_tab, &iter) >= 0) {
    do {
      char  *key;
      int    keylen;
      struct obj_data *value;

      key   = ht_iter_getkey(&iter, &keylen);
      value = ht_iter_getval(&iter);
      if (PDF_OBJ_UNDEFINED(value->object)) {
        texpdf_names_add_object(ht_tab, key, keylen, texpdf_new_null());
        WARN("Object @%s used, but not defined. Replaced by null.",
        printable_key(key, keylen));
      }
    } while (ht_iter_next(&iter) >= 0);
    ht_clear_iter(&iter);
  }
}

void
texpdf_delete_name_tree (struct ht_table **names)
{
  ASSERT(names && *names);

  check_objects_defined (*names);

  texpdf_ht_clear_table(*names);
  RELEASE(*names);
  *names = NULL;
}

int
texpdf_names_add_object (struct ht_table *names, const void *key, int keylen, pdf_obj *object)
{
  struct obj_data *value;

  ASSERT(names && object);

  if (!key || keylen < 1) {
    WARN("Null string used for name tree key.");
    return -1;
  }

  value = texpdf_ht_lookup_table(names, key, keylen);
  if (!value) {
    value = NEW(1, struct obj_data);
    value->object     = object;
    value->reference  = NULL;
    value->closed     = 0;
    texpdf_ht_append_table(names, key, keylen, value);
  } else {
    if (value->object && PDF_OBJ_UNDEFINED(value->object)) {
      pdf_transfer_label(object, value->object);
      texpdf_release_obj(value->object);
      value->object = object;
    } else {
      WARN("Object @%s already defined.", printable_key(key, keylen));
      texpdf_release_obj(object);
      return -1;
    }
  }

  return 0;
}

pdf_obj *
pdf_names_reserve (struct ht_table *names, const void *key, int keylen)
{
  pdf_obj         *obj_ref = NULL;
  struct obj_data *value;

  ASSERT(names);

  if (!key || keylen < 1) {
    WARN("Null string used for name tree key.");
    return NULL;
  }

  value = texpdf_ht_lookup_table(names, key, keylen);
  if (!value) {
    value = NEW(1, struct obj_data);
    value->object     = texpdf_new_undefined();
    value->reference  = NULL;
    value->closed     = 0;
    texpdf_ht_append_table(names, key, keylen, value);
    obj_ref = texpdf_ref_obj(value->object);
  } else {
    if (value->object && PDF_OBJ_UNDEFINED(value->object)) {
      if (!value->reference)
        value->reference = texpdf_ref_obj(value->object);
      obj_ref = texpdf_link_obj(value->reference);
    } else {
      WARN("Object @%s already defined.", printable_key(key, keylen));
      obj_ref = NULL;
    }
  }

  return obj_ref;
}

/*
 * The following routine returns copies, not the original object.
 */
pdf_obj *
texpdf_names_lookup_reference (struct ht_table *names, const void *key, int keylen)
{
  struct obj_data *value;
  pdf_obj         *obj_ref;

  ASSERT(names);

  value = texpdf_ht_lookup_table(names, key, keylen);

  if (value) {
    if (!value->reference) {
      if (value->object) {
        value->reference = texpdf_ref_obj(value->object);
      } else {
        WARN("Can't create object ref for already released object: %s", printable_key(key, keylen));
      }
    }
    obj_ref = texpdf_link_obj(value->reference);
  } else {
    /* A null object as dummy would create problems because as value
     * of a dictionary entry, a null object is be equivalent to no entry
     * at all. This matters for optimization of PDF destinations.
     */
    obj_ref = pdf_names_reserve(names, key, keylen);
  }

  return obj_ref;
}

pdf_obj *
texpdf_names_lookup_object (struct ht_table *names, const void *key, int keylen)
{
  struct obj_data *value;

  ASSERT(names);

  value = texpdf_ht_lookup_table(names, key, keylen);
  if (!value || PDF_OBJ_UNDEFINED(value->object))
    return NULL;
  if (value->closed)
    WARN("Object \"%s\" already closed.", printable_key(key, keylen));

  return value->object;
}

int
texpdf_names_close_object (struct ht_table *names, const void *key, int keylen)
{
  struct obj_data *value;

  ASSERT(names);

  value = texpdf_ht_lookup_table(names, key, keylen);
  if (!value ||PDF_OBJ_UNDEFINED(value->object) ) {
    WARN("Cannot close undefined object @%s.", printable_key(key, keylen));
    return -1;
  }
  ASSERT(value->object);

  if (value->closed) {
    WARN("Object @%s already closed.", printable_key(key, keylen));
    return -1;
  }

  if (value->reference) {
    texpdf_release_obj(value->object);
    value->object = NULL;
  }
  value->closed = 1;

  return 0;
}

struct named_object
{
  char    *key;
  int      keylen;
  pdf_obj *value;
};

static inline int
cmp_key (const void *d1, const void *d2)
{
  const struct named_object *sd1, *sd2;
  int    keylen, cmp;

  sd1 = (const struct named_object *) d1;
  sd2 = (const struct named_object *) d2;

  if (!sd1->key)
    cmp = -1;
  else if (!sd2->key)
    cmp =  1;
  else {
    keylen = MIN(sd1->keylen, sd2->keylen);
    cmp    = memcmp(sd1->key, sd2->key, keylen);
    if (!cmp) {
      cmp = sd1->keylen - sd2->keylen;
    }
  }

  return cmp;
}

#define NAME_CLUSTER 4
static pdf_obj *
build_name_tree (struct named_object *first, int num_leaves, int is_root)
{
  pdf_obj *result;
  int      i;

  result = texpdf_new_dict();
  /*
   * According to PDF Refrence, Third Edition (p.101-102), a name tree
   * always has exactly one root node, which contains a SINGLE entry:
   * either Kids or Names but not both. If the root node has a Names
   * entry, it is the only node in the tree. If it has a Kids entry,
   * then each of the remaining nodes is either an intermediate node,
   * containing a Limits entry and a Kids entry, or a leaf node,
   * containing a Limits entry and a Names entry.
   */
  if (!is_root) {
    struct named_object *last;
    pdf_obj *limits;

    limits = texpdf_new_array();
    last   = &first[num_leaves - 1];
    texpdf_add_array(limits, texpdf_new_string(first->key, first->keylen));
    texpdf_add_array(limits, texpdf_new_string(last->key , last->keylen ));
    texpdf_add_dict (result, texpdf_new_name("Limits"),    limits);
  }

  if (num_leaves > 0 &&
      num_leaves <= 2 * NAME_CLUSTER) {
    pdf_obj *names;

    /* Create leaf nodes. */
    names = texpdf_new_array();
    for (i = 0; i < num_leaves; i++) {
      struct named_object *cur;

      cur = &first[i];
      texpdf_add_array(names, texpdf_new_string(cur->key, cur->keylen));
      switch (PDF_OBJ_TYPEOF(cur->value)) {
      case PDF_ARRAY:
      case PDF_DICT:
      case PDF_STREAM:
      case PDF_STRING:
	texpdf_add_array(names, texpdf_ref_obj(cur->value));
	break;
      case PDF_OBJ_INVALID:
	ERROR("Invalid object...: %s", printable_key(cur->key, cur->keylen));
      default:
	texpdf_add_array(names, texpdf_link_obj(cur->value));
	break;
      }
      texpdf_release_obj(cur->value);
      cur->value = NULL;
    }
    texpdf_add_dict(result, texpdf_new_name("Names"), names);
  } else if (num_leaves > 0) {
    pdf_obj *kids;

    /* Intermediate node */
    kids = texpdf_new_array();
    for (i = 0; i < NAME_CLUSTER; i++) {
      pdf_obj *subtree;
      int      start, end;

      start = (i*num_leaves) / NAME_CLUSTER;
      end   = ((i+1)*num_leaves) / NAME_CLUSTER;
      subtree = build_name_tree(&first[start], (end - start), 0);
      texpdf_add_array  (kids, texpdf_ref_obj(subtree));
      texpdf_release_obj(subtree);
    }
    texpdf_add_dict(result, texpdf_new_name("Kids"), kids);
  }

  return result;
}

static struct named_object *
flat_table (struct ht_table *ht_tab, int *num_entries,
	    struct ht_table *filter)
{
  struct named_object *objects;
  struct ht_iter       iter;
  int    count;

  ASSERT(ht_tab);

  objects = NEW(ht_tab->count, struct named_object);
  count = 0;
  if (ht_set_iter(ht_tab, &iter) >= 0) {
    do {
      char  *key;
      int    keylen;
      struct obj_data *value;

      key   = ht_iter_getkey(&iter, &keylen);

      if (filter) {
	pdf_obj *new_obj = texpdf_ht_lookup_table(filter, key, keylen);

	if (!new_obj)
	  continue;

	key = texpdf_string_value(new_obj);
	keylen = texpdf_string_length(new_obj);
      }

      value = ht_iter_getval(&iter);
      ASSERT(value->object);
      if (PDF_OBJ_UNDEFINED(value->object)) {
	WARN("Object @%s\" not defined. Replaced by null.",
	     printable_key(key, keylen));
	objects[count].key    = (char *) key;
	objects[count].keylen = keylen;
	objects[count].value  = texpdf_new_null();
      } else if (value->object) {
	objects[count].key    = (char *) key;
	objects[count].keylen = keylen;
	objects[count].value  = texpdf_link_obj(value->object);
      }
      count++;
    } while (ht_iter_next(&iter) >= 0);
    ht_clear_iter(&iter);
  }

  *num_entries = count;
  objects = RENEW(objects, count, struct named_object);

  return objects;
}

pdf_obj *
texpdf_names_create_tree (struct ht_table *names, int *count,
		       struct ht_table *filter)
{
  pdf_obj *name_tree;
  struct   named_object *flat;

  flat = flat_table(names, count, filter);
  if (!flat)
    name_tree = NULL;
  else {
    qsort(flat, *count, sizeof(struct named_object), cmp_key);
    name_tree = build_name_tree(flat, *count, 1);
    RELEASE(flat);
  }

  return name_tree;
}
