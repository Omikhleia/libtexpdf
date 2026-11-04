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
void texpdf_skip_white_spaces(unsigned char **cursor, unsigned char *end);
void texpdf_skip_white(const char **cursor, const char *end);
char * texpdf_parse_number(const char **cursor, const char *end);
char * texpdf_parse_unsigned(const char **cursor, const char *end);
char * texpdf_parse_ident(const char **cursor, const char *end);
char * texpdf_parse_val_ident(const char **cursor, const char *end);
char * texpdf_parse_opt_ident(const char **cursor, const char *end);
pdf_obj * texpdf_parse_pdf_number(const char **cursor, const char *end);
pdf_obj * texpdf_parse_pdf_name(const char **cursor, const char *end);
pdf_obj * texpdf_parse_pdf_string(const char **cursor, const char *end);
pdf_obj * texpdf_parse_pdf_boolean(const char **cursor, const char *end);
pdf_obj * texpdf_parse_pdf_null(const char **cursor, const char *end);
pdf_obj * texpdf_parse_pdf_array(const char **cursor, const char *end, pdf_file *file);
pdf_obj * texpdf_parse_pdf_dict(const char **cursor, const char *end, pdf_file *file);
pdf_obj * texpdf_parse_pdf_object(const char **cursor, const char *end, pdf_file *file);
pdf_obj * texpdf_parse_pdf_tainted_dict(const char **cursor, const char *end, pdf_obj *(*unknown_handler)(const char **, const char *, void *), void *user_data);
pdf_obj * texpdf_parse_pdf_object_extended(const char **cursor, const char *end, pdf_file *file, pdf_obj *(*unknown_handler)(const char **, const char *, void *), void *user_data);
pdf_obj * texpdf_new_array(void);
pdf_obj * texpdf_new_dict(void);
pdf_obj * texpdf_new_stream(int flags);
pdf_obj * texpdf_new_name(const char *name);
pdf_obj * texpdf_new_number(double value);
pdf_obj * texpdf_new_boolean(char value);
pdf_obj * texpdf_new_string(const void *bytes, unsigned int length);
pdf_obj * texpdf_new_indirect(pdf_file *file, uint32_t object_number, uint16_t generation);
pdf_obj * texpdf_new_undefined(void);
pdf_obj * texpdf_new_null(void);
void texpdf_add_array(pdf_obj *array, pdf_obj *value);
int texpdf_add_dict(pdf_obj *dictionary, pdf_obj *key, pdf_obj *value);
void texpdf_add_stream(pdf_obj *stream, const void *data, int length);
void texpdf_set_root(pdf_obj *root);
void texpdf_set_info(pdf_obj *info);
void texpdf_set_number(pdf_obj *object, double value);
void texpdf_set_string(pdf_obj *object, unsigned char *bytes, unsigned int length);
char * texpdf_name_value(pdf_obj *name);
double texpdf_number_value(pdf_obj *number);
void * texpdf_string_value(pdf_obj *string);
unsigned int texpdf_string_length(pdf_obj *string);
pdf_obj * texpdf_get_array(pdf_obj *array, int index);
unsigned int texpdf_array_length(pdf_obj *array);
void texpdf_release_obj(pdf_obj *object);
void texpdf_error_cleanup(void);
int texpdf_obj_typeof(pdf_obj *object);
pdf_obj * texpdf_ref_obj(pdf_obj *object);
pdf_obj * texpdf_link_obj(pdf_obj *object);
void texpdf_remove_dict(pdf_obj *dictionary, const char *key);
void texpdf_merge_dict(pdf_obj *dictionary, pdf_obj *source);
pdf_obj * texpdf_lookup_dict(pdf_obj *dictionary, const char *key);
pdf_obj * texpdf_stream_dict(pdf_obj *stream);
int texpdf_foreach_dict(pdf_obj *dictionary, int (*callback)(pdf_obj *, pdf_obj *, void *), void *user_data);
pdf_obj * texpdf_ximage_get_reference(int xobj_id);
void texpdf_ximage_init_image_info(ximage_info *info);
void texpdf_ximage_set_image(pdf_ximage *image, void *info, pdf_obj *resource);
void texpdf_ximage_init_form_info(xform_info *info);
int texpdf_ximage_scale_image(int xobj_id, pdf_tmatrix *matrix, pdf_rect *bbox, transform_info *transform);
void texpdf_ximage_set_attr(int xobj_id, int width, int height, double xdensity, double ydensity, double llx, double lly, double urx, double ury);
int texpdf_ximage_get_subtype(int xobj_id);
void texpdf_ximage_set_form(pdf_ximage *image, void *info, pdf_obj *resource);
int texpdf_ximage_get_page(pdf_ximage *image);
int texpdf_check_version(int major, int minor);
const char *texpdf_library_version(void);
fontmap_rec * texpdf_insert_native_fontmap_record(const char *filename, uint32_t index, int layout_dir, int extend, int slant, int embolden);
void texpdf_init_fontmaps(void);
void texpdf_close_fontmaps(void);
void texpdf_init_fontmap_record(fontmap_rec *record);
void texpdf_clear_fontmap_record(fontmap_rec *record);
int texpdf_remove_fontmap_record(const char *key);
fontmap_rec * texpdf_insert_fontmap_record(const char *key, const fontmap_rec *record);
fontmap_rec * texpdf_lookup_fontmap_record(const char *key);
int texpdf_color_type(const pdf_color *color);
int texpdf_color_rgbcolor(pdf_color *color, double red, double green, double blue);
int texpdf_color_cmykcolor(pdf_color *color, double cyan, double magenta, double yellow, double black);
int texpdf_color_graycolor(pdf_color *color, double gray);
int texpdf_color_spotcolor(pdf_color *color, char *color_name, double tint);
void texpdf_color_copycolor(pdf_color *destination, const pdf_color *source);
void texpdf_color_brighten_color(pdf_color *destination, const pdf_color *source, double factor);
int texpdf_color_is_white(const pdf_color *color);
int texpdf_color_compare(const pdf_color *color1, const pdf_color *color2);
pdf_obj * texpdf_get_colorspace_reference(int colorspace_id);
void texpdf_init_colors(void);
void texpdf_close_colors(void);
void texpdf_color_set(pdf_color *stroke_color, pdf_color *fill_color);
void texpdf_color_push(pdf_color *stroke_color, pdf_color *fill_color);
void texpdf_color_pop(void);
void texpdf_color_clear_stack(void);
void texpdf_color_get_current(pdf_color **stroke_color, pdf_color **fill_color);
void texpdf_dev_init_gstates(void);
void texpdf_dev_clear_gstates(void);
int texpdf_dev_currentmatrix(pdf_tmatrix *matrix);
int texpdf_dev_currentpoint(pdf_coord *point);
int texpdf_dev_setlinewidth(double width);
int texpdf_dev_setmiterlimit(double limit);
int texpdf_dev_setlinecap(int line_cap);
int texpdf_dev_setlinejoin(int line_join);
int texpdf_dev_setdash(int dash_count, double *dash_array, double dash_offset);
int texpdf_dev_moveto(double x, double y);
int texpdf_dev_rmoveto(double delta_x, double delta_y);
int texpdf_dev_closepath(void);
int texpdf_dev_lineto(double x, double y);
int texpdf_dev_rlineto(double delta_x, double delta_y);
int texpdf_dev_curveto(double x1, double y1, double x2, double y2, double x3, double y3);
int texpdf_dev_rcurveto(double delta_x1, double delta_y1, double delta_x2, double delta_y2, double delta_x3, double delta_y3);
int texpdf_dev_arc(double center_x, double center_y, double radius, double start_angle, double end_angle);
int texpdf_dev_arcn(double center_x, double center_y, double radius, double start_angle, double end_angle);
int texpdf_dev_newpath(void);
int texpdf_dev_clip(void);
int texpdf_dev_eoclip(void);
int texpdf_dev_rectstroke(double x, double y, double width, double height, const pdf_tmatrix *matrix);
int texpdf_dev_rectfill(double x, double y, double width, double height);
int texpdf_dev_rectclip(double x, double y, double width, double height);
int texpdf_dev_flushpath(char path_type, int force);
int texpdf_dev_locate_font(const char *font_name, spt_t ptsize);
int texpdf_dev_load_native_font(const char *filename, uint32_t index, spt_t ptsize, int layout_dir, int extend, int slant, int embolden);
void texpdf_dev_set_rule(spt_t xpos, spt_t ypos, spt_t width, spt_t height);
void texpdf_dev_set_dirmode(int dir_mode);
int texpdf_dev_gsave(void);
int texpdf_dev_grestore(void);
int texpdf_dev_put_image(int xobj_id, transform_info *info, double ref_x, double ref_y, pdf_rect *rect);
void texpdf_graphics_mode(void);
void texpdf_setmatrix(pdf_tmatrix *matrix, double a, double b, double c, double d, double e, double f);
void texpdf_transform_info_clear(transform_info *info);
void texpdf_dev_set_string(spt_t xpos, spt_t ypos, const void *input, int input_length, spt_t text_width, int font_id);
void texpdf_dev_set_glyphs(spt_t xpos, spt_t ypos, const uint16_t *glyph_ids, int glyph_count, spt_t text_width, int font_id);
int texpdf_ximage_load_image(const char *ident, const char *filename, load_options options);
void texpdf_doc_add_page_content(const char *buffer, unsigned length);
void texpdf_doc_add_page_resource(const char *category, const char *resource_name, pdf_obj *resource);
pdf_obj * texpdf_doc_current_page_resources(void);
int texpdf_doc_current_page_number(void);
int texpdf_doc_add_names(const char *category, const void *key, int key_length, pdf_obj *value);
int texpdf_doc_bookmarks_up(void);
int texpdf_doc_bookmarks_down(void);
int texpdf_doc_bookmarks_depth(void);
void texpdf_doc_bookmarks_add(pdf_obj *dictionary, int is_open);
void texpdf_doc_add_annot(unsigned page_no, const pdf_rect *rect, pdf_obj *annot, int new_annot);
int texpdf_doc_add_page_annotation(pdf_obj *annot_ref);
void texpdf_tt_aux_set_always_embed(void);
void texpdf_init_device(double unit_conversion, int precision, int ignore_colors);
void texpdf_close_device(void);
void texpdf_open_document(const char *filename, const char *creator, const unsigned char *id1, const unsigned char *id2, struct pdf_setting settings);
void texpdf_close_document(void);
void texpdf_doc_begin_page(double scale, double x_origin, double y_origin);
void texpdf_doc_end_page(void);
void texpdf_doc_set_mediabox(unsigned page_no, const pdf_rect *mediabox);
pdf_obj * texpdf_doc_get_dictionary(const char *category);
pdf_obj * texpdf_doc_get_reference(const char *category);
void texpdf_init_resources(void);
void texpdf_close_resources(void);
pdf_obj * texpdf_get_resource_reference(int resource_id);
int texpdf_check_for_pdf(FILE *file);
void texpdf_init_images(void);
void texpdf_close_images(void);
char * texpdf_ximage_get_resname(int xobj_id);
void texpdf_set_distiller_template(char *command_template);
char * texpdf_get_distiller_template(void);
struct ht_table * texpdf_new_name_tree(void);
void texpdf_delete_name_tree(struct ht_table **names);
int texpdf_names_add_object(struct ht_table *names, const void *key, int key_length, pdf_obj *object);
pdf_obj * texpdf_names_lookup_reference(struct ht_table *names, const void *key, int key_length);
pdf_obj * texpdf_names_lookup_object(struct ht_table *names, const void *key, int key_length);
int texpdf_names_close_object(struct ht_table *names, const void *key, int key_length);
pdf_obj * texpdf_names_create_tree(struct ht_table *names, int *count, struct ht_table *filter);
int texpdf_get_version(void);
pdf_file * texpdf_open(const char *filename, FILE *file);
void texpdf_close(pdf_file *file);
int texpdf_file_get_version(pdf_file *file);
void texpdf_files_init(void);
void texpdf_files_close(void);
void texpdf_init_encodings(void);
void texpdf_close_encodings(void);
pdf_obj * texpdf_get_encoding_obj(int encoding_id);
int texpdf_check_for_bmp(FILE *file);
int texpdf_bmp_get_bbox(FILE *file, int *x, int *y, double *width, double *height);
int texpdf_check_for_jp2(FILE *file);
int texpdf_jp2_get_bbox(FILE *file, int *x, int *y, double *width, double *height);
int texpdf_check_for_jpeg(FILE *file);
int texpdf_jpeg_get_bbox(FILE *file, int *x, int *y, double *width, double *height);
int texpdf_check_for_png(FILE *file);
int texpdf_png_get_bbox(FILE *file, uint32_t *x, uint32_t *y, double *width, double *height);
void texpdf_ht_init_table(struct ht_table *table, hval_free_func free_value);
void texpdf_ht_clear_table(struct ht_table *table);
void * texpdf_ht_lookup_table(struct ht_table *table, const void *key, int key_length);
void texpdf_ht_append_table(struct ht_table *table, const void *key, int key_length, void *value);
char * texpdf_parse_float_decimal(const char **cursor, const char *end);
char * texpdf_parse_c_string(const char **cursor, const char *end);
char * texpdf_parse_c_ident(const char **cursor, const char *end);
void texpdf_debug_level(int quietness);
int texpdf_dev_concat(const pdf_tmatrix *matrix);

#define texpdf_color_white(c) texpdf_color_graycolor(c, 1.0);
#define texpdf_color_black(c) texpdf_color_graycolor(c, 0.0);
#endif

#endif
