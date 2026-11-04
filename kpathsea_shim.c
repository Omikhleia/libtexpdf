/* BEGIN LIBTEXPDF PATCH */
/* SILE supplies resolved paths; this shim deliberately skips TeX tree search. */
#include "kpathsea_shim.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

string
kpse_find_file (const_string filename, kpse_file_format_type format,
                boolean must_exist)
{
  FILE *file;
  size_t length;
  char *path;

  (void) format;
  (void) must_exist;

  if (!filename || !*filename)
    return NULL;

  file = fopen(filename, "rb");
  if (!file)
    return NULL;
  fclose(file);

  length = strlen(filename) + 1;
  path = malloc(length);
  if (path)
    memcpy(path, filename, length);

  return path;
}

string
xstrdup (const_string value)
{
  size_t length;
  char *copy;

  if (!value)
    return NULL;
  length = strlen(value) + 1;
  copy = malloc(length);
  if (copy)
    memcpy(copy, value, length);
  return copy;
}

string
kpse_find_pict (const_string filename)
{
  return xstrdup(filename);
}

address
xcalloc (size_t count, size_t size)
{
  return calloc(count, size);
}

string
xgetcwd (void)
{
  return getcwd(NULL, 0);
}

void
xfseeko (FILE *file, off_t offset, int whence, const_string filename)
{
  if (fseeko(file, offset, whence) != 0) {
    perror(filename);
    abort();
  }
}

off_t
xftello (FILE *file, const_string filename)
{
  off_t offset = ftello(file);
  if (offset == (off_t) -1) {
    perror(filename);
    abort();
  }
  return offset;
}
/* END LIBTEXPDF PATCH */