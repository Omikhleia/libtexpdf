#ifndef _LIBTEXPDF_H
#define _LIBTEXPDF_H
#define XETEX 1 /* We are all xetex now */

#ifdef BUILDING_LIBTEXPDF
#include <config.h>
#endif

#ifdef HAVE_STRING_H
#include <string.h>
#endif

#ifdef HAVE_STDINT_H
#include <stdint.h>
#endif

#include <sys/types.h>

extern int compat_mode;

/* Stolen from kpathsea, to avoid depending on it */
#ifndef FOPEN_A_MODE
#define FOPEN_A_MODE "ab"
#endif

#ifndef FOPEN_R_MODE
#define FOPEN_R_MODE "r"
#endif

#ifndef FOPEN_W_MODE
#define FOPEN_W_MODE "wb"
#endif

/* How to open a binary file for reading:  */
#ifndef FOPEN_RBIN_MODE
#define FOPEN_RBIN_MODE "rb"
#endif /* not FOPEN_RBIN_MODE */

/* How to open a binary file for writing:  */
#ifndef FOPEN_WBIN_MODE
#define FOPEN_WBIN_MODE "wb"
#endif /* not FOPEN_WBIN_MODE */

#if defined(WIN32) && !defined(__MINGW32__)
#define off64_t int64_t
#define ftello _ftelli64
#define fseeko _fseeki64
#include "win32/win32.h"
#elif defined(__MINGW32__)
#define ftello ftello64
#define fseeko fseeko64
#endif

#include "agl.h"
#include "bmpimage.h"
#include "cff.h"
#include "cff_dict.h"
#include "cff_limits.h"
#include "cff_types.h"
#include "cid.h"
#include "cidtype0.h"
#include "cidtype2.h"
#include "cmap.h"
#include "cmap_p.h"
#include "cmap_read.h"
#include "cmap_write.h"
#include "cs_type2.h"
#include "dpxcrypt.h"
#include "dpxfile.h"
#include "dpxutil.h"
#include "epdf.h"
#include "error.h"
#include "fontmap.h"
#include "jp2image.h"
#include "jpegimage.h"
#include "mem.h"
#include "mfileio.h"
#include "numbers.h"
#include "otl_opt.h"
#include "pdfcolor.h"
#include "pdfdev.h"
#include "pdfdoc.h"
#include "pdfdraw.h"
#include "pdfencoding.h"
#include "pdfencrypt.h"
#include "pdffont.h"
#include "pdflimits.h"
#include "pdfnames.h"
#include "pdfobj.h"
#include "pdfparse.h"
#include "pdfresource.h"
#include "pdfximage.h"
#include "pngimage.h"
#include "pst.h"
#include "pst_obj.h"
#include "sfnt.h"
#include "subfont.h"
#include "t1_char.h"
#include "t1_load.h"
#include "truetype.h"
#include "tt_aux.h"
#include "tt_cmap.h"
#include "tt_glyf.h"
#include "tt_gsub.h"
#include "tt_post.h"
#include "tt_table.h"
#include "type0.h"
#include "type1.h"
#include "type1c.h"
#include "unicode.h"

#ifndef BUILDING_LIBTEXPDF
void texpdf_skip_white_spaces(unsigned char ** argument_0, unsigned char * argument_1);
void texpdf_skip_white(const char ** argument_0, const char * argument_1);
char * texpdf_parse_number(const char ** argument_0, const char * argument_1);
char * texpdf_parse_unsigned(const char ** argument_0, const char * argument_1);
char * texpdf_parse_ident(const char ** argument_0, const char * argument_1);
char * texpdf_parse_val_ident(const char ** argument_0, const char * argument_1);
char * texpdf_parse_opt_ident(const char ** argument_0, const char * argument_1);
pdf_obj * texpdf_parse_pdf_number(const char ** argument_0, const char * argument_1);
pdf_obj * texpdf_parse_pdf_name(const char ** argument_0, const char * argument_1);
pdf_obj * texpdf_parse_pdf_string(const char ** argument_0, const char * argument_1);
pdf_obj * texpdf_parse_pdf_boolean(const char ** argument_0, const char * argument_1);
pdf_obj * texpdf_parse_pdf_null(const char ** argument_0, const char * argument_1);
pdf_obj * texpdf_parse_pdf_array(const char ** argument_0, const char * argument_1, pdf_file * argument_2);
pdf_obj * texpdf_parse_pdf_dict(const char ** argument_0, const char * argument_1, pdf_file * argument_2);
pdf_obj * texpdf_parse_pdf_object(const char ** argument_0, const char * argument_1, pdf_file * argument_2);
pdf_obj * texpdf_parse_pdf_tainted_dict(const char ** argument_0, const char * argument_1, pdf_obj *(*argument_2)(const char **, const char *, void *), void * argument_3);
pdf_obj * texpdf_parse_pdf_object_extended(const char ** argument_0, const char * argument_1, pdf_file * argument_2, pdf_obj *(*argument_3)(const char **, const char *, void *), void * argument_4);
pdf_obj * texpdf_new_array(void);
pdf_obj * texpdf_new_dict(void);
pdf_obj * texpdf_new_stream(int argument_0);
pdf_obj * texpdf_new_name(const char * argument_0);
pdf_obj * texpdf_new_number(double argument_0);
pdf_obj * texpdf_new_boolean(char argument_0);
pdf_obj * texpdf_new_string(const void * argument_0, unsigned int argument_1);
pdf_obj * texpdf_new_indirect(pdf_file * argument_0, uint32_t argument_1, uint16_t argument_2);
pdf_obj * texpdf_new_undefined(void);
pdf_obj * texpdf_new_null(void);
void texpdf_add_array(pdf_obj * argument_0, pdf_obj * argument_1);
int texpdf_add_dict(pdf_obj * argument_0, pdf_obj * argument_1, pdf_obj * argument_2);
void texpdf_add_stream(pdf_obj * argument_0, const void * argument_1, int argument_2);
void texpdf_set_root(pdf_obj * argument_0);
void texpdf_set_info(pdf_obj * argument_0);
void texpdf_set_number(pdf_obj * argument_0, double argument_1);
void texpdf_set_string(pdf_obj * argument_0, unsigned char * argument_1, unsigned int argument_2);
char * texpdf_name_value(pdf_obj * argument_0);
double texpdf_number_value(pdf_obj * argument_0);
void * texpdf_string_value(pdf_obj * argument_0);
unsigned int texpdf_string_length(pdf_obj * argument_0);
pdf_obj * texpdf_get_array(pdf_obj * argument_0, int argument_1);
unsigned int texpdf_array_length(pdf_obj * argument_0);
void texpdf_release_obj(pdf_obj * argument_0);
void texpdf_error_cleanup(void);
int texpdf_obj_typeof(pdf_obj * argument_0);
pdf_obj * texpdf_ref_obj(pdf_obj * argument_0);
pdf_obj * texpdf_link_obj(pdf_obj * argument_0);
void texpdf_remove_dict(pdf_obj * argument_0, const char * argument_1);
void texpdf_merge_dict(pdf_obj * argument_0, pdf_obj * argument_1);
pdf_obj * texpdf_lookup_dict(pdf_obj * argument_0, const char * argument_1);
pdf_obj * texpdf_stream_dict(pdf_obj * argument_0);
int texpdf_foreach_dict(pdf_obj * argument_0, int (*argument_1)(pdf_obj *, pdf_obj *, void *), void * argument_2);
pdf_obj * texpdf_ximage_get_reference(int argument_0);
void texpdf_ximage_init_image_info(ximage_info * argument_0);
void texpdf_ximage_set_image(pdf_ximage * argument_0, void * argument_1, pdf_obj * argument_2);
void texpdf_ximage_init_form_info(xform_info * argument_0);
int texpdf_ximage_scale_image(int argument_0, pdf_tmatrix * argument_1, pdf_rect * argument_2, transform_info * argument_3);
void texpdf_ximage_set_attr(int argument_0, int argument_1, int argument_2, double argument_3, double argument_4, double argument_5, double argument_6, double argument_7, double argument_8);
int texpdf_ximage_get_subtype(int argument_0);
void texpdf_ximage_set_form(pdf_ximage * argument_0, void * argument_1, pdf_obj * argument_2);
int texpdf_ximage_get_page(pdf_ximage * argument_0);
int texpdf_check_version(int argument_0, int argument_1);
fontmap_rec * texpdf_insert_native_fontmap_record(const char * argument_0, uint32_t argument_1, int argument_2, int argument_3, int argument_4, int argument_5);
void texpdf_init_fontmaps(void);
void texpdf_close_fontmaps(void);
void texpdf_init_fontmap_record(fontmap_rec * argument_0);
void texpdf_clear_fontmap_record(fontmap_rec * argument_0);
int texpdf_remove_fontmap_record(const char * argument_0);
fontmap_rec * texpdf_insert_fontmap_record(const char * argument_0, const fontmap_rec * argument_1);
fontmap_rec * texpdf_lookup_fontmap_record(const char * argument_0);
int texpdf_color_type(const pdf_color * argument_0);
int texpdf_color_rgbcolor(pdf_color * argument_0, double argument_1, double argument_2, double argument_3);
int texpdf_color_cmykcolor(pdf_color * argument_0, double argument_1, double argument_2, double argument_3, double argument_4);
int texpdf_color_graycolor(pdf_color * argument_0, double argument_1);
int texpdf_color_spotcolor(pdf_color * argument_0, char * argument_1, double argument_2);
void texpdf_color_copycolor(pdf_color * argument_0, const pdf_color * argument_1);
void texpdf_color_brighten_color(pdf_color * argument_0, const pdf_color * argument_1, double argument_2);
int texpdf_color_is_white(const pdf_color * argument_0);
int texpdf_color_compare(const pdf_color * argument_0, const pdf_color * argument_1);
pdf_obj * texpdf_get_colorspace_reference(int argument_0);
void texpdf_init_colors(void);
void texpdf_close_colors(void);
void texpdf_color_set(pdf_color * argument_0, pdf_color * argument_1);
void texpdf_color_push(pdf_color * argument_0, pdf_color * argument_1);
void texpdf_color_pop(void);
void texpdf_color_clear_stack(void);
void texpdf_color_get_current(pdf_color ** argument_0, pdf_color ** argument_1);
void texpdf_dev_init_gstates(void);
void texpdf_dev_clear_gstates(void);
int texpdf_dev_currentmatrix(pdf_tmatrix * argument_0);
int texpdf_dev_currentpoint(pdf_coord * argument_0);
int texpdf_dev_setlinewidth(double argument_0);
int texpdf_dev_setmiterlimit(double argument_0);
int texpdf_dev_setlinecap(int argument_0);
int texpdf_dev_setlinejoin(int argument_0);
int texpdf_dev_setdash(int argument_0, double * argument_1, double argument_2);
int texpdf_dev_moveto(double argument_0, double argument_1);
int texpdf_dev_rmoveto(double argument_0, double argument_1);
int texpdf_dev_closepath(void);
int texpdf_dev_lineto(double argument_0, double argument_1);
int texpdf_dev_rlineto(double argument_0, double argument_1);
int texpdf_dev_curveto(double argument_0, double argument_1, double argument_2, double argument_3, double argument_4, double argument_5);
int texpdf_dev_rcurveto(double argument_0, double argument_1, double argument_2, double argument_3, double argument_4, double argument_5);
int texpdf_dev_arc(double argument_0, double argument_1, double argument_2, double argument_3, double argument_4);
int texpdf_dev_arcn(double argument_0, double argument_1, double argument_2, double argument_3, double argument_4);
int texpdf_dev_newpath(void);
int texpdf_dev_clip(void);
int texpdf_dev_eoclip(void);
int texpdf_dev_rectstroke(double argument_0, double argument_1, double argument_2, double argument_3, const pdf_tmatrix * argument_4);
int texpdf_dev_rectfill(double argument_0, double argument_1, double argument_2, double argument_3);
int texpdf_dev_rectclip(double argument_0, double argument_1, double argument_2, double argument_3);
int texpdf_dev_flushpath(char argument_0, int argument_1);
int texpdf_dev_locate_font(const char *font_name, spt_t ptsize);
int texpdf_dev_load_native_font(const char *filename, uint32_t index, spt_t ptsize, int layout_dir, int extend, int slant, int embolden);
void texpdf_dev_set_string(spt_t xpos, spt_t ypos, const void *input, int input_length, spt_t text_width, int font_id);
void texpdf_dev_set_glyphs(spt_t xpos, spt_t ypos, const uint16_t *glyph_ids, int glyph_count, spt_t text_width, int font_id);
void texpdf_init_device(double argument_0, int argument_1, int argument_2);
void texpdf_close_device(void);
void texpdf_open_document(const char * argument_0, const char * argument_1, const unsigned char * argument_2, const unsigned char * argument_3, struct pdf_setting argument_4);
void texpdf_close_document(void);
void texpdf_doc_begin_page(double scale, double x_origin, double y_origin);
void texpdf_doc_end_page(void);
void texpdf_doc_set_mediabox(unsigned page_no, const pdf_rect *mediabox);
pdf_obj * texpdf_doc_get_dictionary(const char * argument_0);
pdf_obj * texpdf_doc_get_reference(const char * argument_0);
void texpdf_init_resources(void);
void texpdf_close_resources(void);
pdf_obj * texpdf_get_resource_reference(int argument_0);
int texpdf_check_for_pdf(FILE * argument_0);
void texpdf_init_images(void);
void texpdf_close_images(void);
char * texpdf_ximage_get_resname(int argument_0);
void texpdf_set_distiller_template(char * argument_0);
char * texpdf_get_distiller_template(void);
struct ht_table * texpdf_new_name_tree(void);
void texpdf_delete_name_tree(struct ht_table ** argument_0);
int texpdf_names_add_object(struct ht_table * argument_0, const void * argument_1, int argument_2, pdf_obj * argument_3);
pdf_obj * texpdf_names_lookup_reference(struct ht_table * argument_0, const void * argument_1, int argument_2);
pdf_obj * texpdf_names_lookup_object(struct ht_table * argument_0, const void * argument_1, int argument_2);
int texpdf_names_close_object(struct ht_table * argument_0, const void * argument_1, int argument_2);
pdf_obj * texpdf_names_create_tree(struct ht_table * argument_0, int * argument_1, struct ht_table * argument_2);
int texpdf_get_version(void);
pdf_file * texpdf_open(const char * argument_0, FILE * argument_1);
void texpdf_close(pdf_file * argument_0);
int texpdf_file_get_version(pdf_file * argument_0);
void texpdf_files_init(void);
void texpdf_files_close(void);
void texpdf_init_encodings(void);
void texpdf_close_encodings(void);
pdf_obj * texpdf_get_encoding_obj(int argument_0);
int texpdf_check_for_bmp(FILE * argument_0);
int texpdf_bmp_get_bbox(FILE * argument_0, int * argument_1, int * argument_2, double * argument_3, double * argument_4);
int texpdf_check_for_jp2(FILE * argument_0);
int texpdf_jp2_get_bbox(FILE * argument_0, int * argument_1, int * argument_2, double * argument_3, double * argument_4);
int texpdf_check_for_jpeg(FILE * argument_0);
int texpdf_jpeg_get_bbox(FILE * argument_0, int * argument_1, int * argument_2, double * argument_3, double * argument_4);
int texpdf_check_for_png(FILE * argument_0);
int texpdf_png_get_bbox(FILE * argument_0, uint32_t * argument_1, uint32_t * argument_2, double * argument_3, double * argument_4);
void texpdf_ht_init_table(struct ht_table * argument_0, hval_free_func argument_1);
void texpdf_ht_clear_table(struct ht_table * argument_0);
void * texpdf_ht_lookup_table(struct ht_table * argument_0, const void * argument_1, int argument_2);
void texpdf_ht_append_table(struct ht_table * argument_0, const void * argument_1, int argument_2, void * argument_3);
char * texpdf_parse_float_decimal(const char ** argument_0, const char * argument_1);
char * texpdf_parse_c_string(const char ** argument_0, const char * argument_1);
char * texpdf_parse_c_ident(const char ** argument_0, const char * argument_1);
void texpdf_debug_level(int argument_0);
int texpdf_dev_concat(const pdf_tmatrix * argument_0);

#define texpdf_color_white(c) texpdf_color_graycolor(c, 1.0);
#define texpdf_color_black(c) texpdf_color_graycolor(c, 0.0);
#endif

#endif
