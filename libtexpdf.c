#include "libtexpdf.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// EXPORTED API WRAPPERS (DIRECT MAPPINGS TO DVIPDFMX FUNCTIONS)

void texpdf_skip_white_spaces(unsigned char **cursor, unsigned char *end)
{
  skip_white_spaces(cursor, end);
}

void texpdf_skip_white(const char **cursor, const char *end)
{
  skip_white(cursor, end);
}

char * texpdf_parse_number(const char **cursor, const char *end)
{
  return parse_number(cursor, end);
}

char * texpdf_parse_unsigned(const char **cursor, const char *end)
{
  return parse_unsigned(cursor, end);
}

char * texpdf_parse_ident(const char **cursor, const char *end)
{
  return parse_ident(cursor, end);
}

char * texpdf_parse_val_ident(const char **cursor, const char *end)
{
  return parse_val_ident(cursor, end);
}

char * texpdf_parse_opt_ident(const char **cursor, const char *end)
{
  return parse_opt_ident(cursor, end);
}

pdf_obj * texpdf_parse_pdf_number(const char **cursor, const char *end)
{
  return parse_pdf_number(cursor, end);
}

pdf_obj * texpdf_parse_pdf_name(const char **cursor, const char *end)
{
  return parse_pdf_name(cursor, end);
}

pdf_obj * texpdf_parse_pdf_string(const char **cursor, const char *end)
{
  return parse_pdf_string(cursor, end);
}

pdf_obj * texpdf_parse_pdf_boolean(const char **cursor, const char *end)
{
  return parse_pdf_boolean(cursor, end);
}

pdf_obj * texpdf_parse_pdf_null(const char **cursor, const char *end)
{
  return parse_pdf_null(cursor, end);
}

pdf_obj * texpdf_parse_pdf_array(const char **cursor, const char *end, pdf_file *file)
{
  return parse_pdf_array(cursor, end, file);
}

pdf_obj * texpdf_parse_pdf_dict(const char **cursor, const char *end, pdf_file *file)
{
  return parse_pdf_dict(cursor, end, file);
}

pdf_obj * texpdf_parse_pdf_object(const char **cursor, const char *end, pdf_file *file)
{
  return parse_pdf_object(cursor, end, file);
}

pdf_obj * texpdf_parse_pdf_tainted_dict(const char **cursor, const char *end, pdf_obj *(*unknown_handler)(const char **, const char *, void *), void *user_data)
{
  return parse_pdf_tainted_dict(cursor, end, unknown_handler, user_data);
}

pdf_obj * texpdf_parse_pdf_object_extended(const char **cursor, const char *end, pdf_file *file, pdf_obj *(*unknown_handler)(const char **, const char *, void *), void *user_data)
{
  return parse_pdf_object_extended(cursor, end, file, unknown_handler, user_data);
}

pdf_obj * texpdf_new_array(void)
{
  return pdf_new_array();
}

pdf_obj * texpdf_new_dict(void)
{
  return pdf_new_dict();
}

pdf_obj * texpdf_new_stream(int flags)
{
  return pdf_new_stream(flags);
}

pdf_obj * texpdf_new_name(const char *name)
{
  return pdf_new_name(name);
}

pdf_obj * texpdf_new_number(double value)
{
  return pdf_new_number(value);
}

pdf_obj * texpdf_new_boolean(char value)
{
  return pdf_new_boolean(value);
}

pdf_obj * texpdf_new_string(const void *bytes, unsigned int length)
{
  return pdf_new_string(bytes, length);
}

pdf_obj * texpdf_new_indirect(pdf_file *file, uint32_t object_number, uint16_t generation)
{
  return pdf_new_indirect(file, object_number, generation);
}

pdf_obj * texpdf_new_undefined(void)
{
  return pdf_new_undefined();
}

pdf_obj * texpdf_new_null(void)
{
  return pdf_new_null();
}

void texpdf_add_array(pdf_obj *array, pdf_obj *object)
{
  pdf_add_array(array, object);
}

int texpdf_add_dict(pdf_obj *dictionary, pdf_obj *key, pdf_obj *value)
{
  return pdf_add_dict(dictionary, key, value);
}

void texpdf_add_stream(pdf_obj *stream, const void *data, int length)
{
  pdf_add_stream(stream, data, length);
}

void texpdf_set_root(pdf_obj *object)
{
  pdf_set_root(object);
}

void texpdf_set_info(pdf_obj *object)
{
  pdf_set_info(object);
}

void texpdf_set_number(pdf_obj *object, double value)
{
  pdf_set_number(object, value);
}

void texpdf_set_string(pdf_obj *object, unsigned char *bytes, unsigned int length)
{
  pdf_set_string(object, bytes, length);
}

char * texpdf_name_value(pdf_obj *object)
{
  return pdf_name_value(object);
}

double texpdf_number_value(pdf_obj *object)
{
  return pdf_number_value(object);
}

void * texpdf_string_value(pdf_obj *object)
{
  return pdf_string_value(object);
}

unsigned int texpdf_string_length(pdf_obj *object)
{
  return pdf_string_length(object);
}

pdf_obj * texpdf_get_array(pdf_obj *array, int index)
{
  return pdf_get_array(array, index);
}

unsigned int texpdf_array_length(pdf_obj *array)
{
  return pdf_array_length(array);
}

void texpdf_release_obj(pdf_obj *object)
{
  pdf_release_obj(object);
}

void texpdf_error_cleanup(void)
{
  pdf_error_cleanup();
}

int texpdf_obj_typeof(pdf_obj *object)
{
  return pdf_obj_typeof(object);
}

pdf_obj * texpdf_ref_obj(pdf_obj *object)
{
  return pdf_ref_obj(object);
}

pdf_obj * texpdf_link_obj(pdf_obj *object)
{
  return pdf_link_obj(object);
}

void texpdf_remove_dict(pdf_obj *dictionary, const char *key)
{
  pdf_remove_dict(dictionary, key);
}

void texpdf_merge_dict(pdf_obj *dictionary, pdf_obj *source)
{
  pdf_merge_dict(dictionary, source);
}

pdf_obj * texpdf_lookup_dict(pdf_obj *dictionary, const char *key)
{
  return pdf_lookup_dict(dictionary, key);
}

pdf_obj * texpdf_stream_dict(pdf_obj *stream)
{
  return pdf_stream_dict(stream);
}

int texpdf_foreach_dict(pdf_obj *dictionary, int (*callback)(pdf_obj *, pdf_obj *, void *), void *user_data)
{
  return pdf_foreach_dict(dictionary, callback, user_data);
}

pdf_obj * texpdf_ximage_get_reference(int xobj_id)
{
  return pdf_ximage_get_reference(xobj_id);
}

void texpdf_ximage_init_image_info(ximage_info *info)
{
  pdf_ximage_init_image_info(info);
}

void texpdf_ximage_set_image(pdf_ximage *image, void *info, pdf_obj *resource)
{
  pdf_ximage_set_image(image, info, resource);
}

void texpdf_ximage_init_form_info(xform_info *info)
{
  pdf_ximage_init_form_info(info);
}

int texpdf_ximage_scale_image(int xobj_id, pdf_tmatrix *matrix, pdf_rect *bbox, transform_info *transform)
{
  return pdf_ximage_scale_image(xobj_id, matrix, bbox, transform);
}

void texpdf_ximage_set_attr(int xobj_id, int width, int height, double xdensity, double ydensity, double llx, double lly, double urx, double ury)
{
  pdf_ximage_set_attr(xobj_id, width, height, xdensity, ydensity, llx, lly, urx, ury);
}

int texpdf_ximage_get_subtype(int xobj_id)
{
  return pdf_ximage_get_subtype(xobj_id);
}

void texpdf_ximage_set_form(pdf_ximage *image, void *info, pdf_obj *resource)
{
  pdf_ximage_set_form(image, info, resource);
}

int texpdf_ximage_get_page(pdf_ximage *image)
{
  return pdf_ximage_get_page(image);
}

int texpdf_check_version(int major, int minor)
{
  return pdf_check_version(major, minor);
}

fontmap_rec * texpdf_insert_native_fontmap_record(const char *filename, uint32_t index, int layout_dir, int extend, int slant, int embolden)
{
  return pdf_insert_native_fontmap_record(filename, index, layout_dir, extend, slant, embolden);
}

void texpdf_init_fontmaps(void)
{
  pdf_init_fontmaps();
}

void texpdf_close_fontmaps(void)
{
  pdf_close_fontmaps();
}

void texpdf_init_fontmap_record(fontmap_rec *record)
{
  pdf_init_fontmap_record(record);
}

void texpdf_clear_fontmap_record(fontmap_rec *record)
{
  pdf_clear_fontmap_record(record);
}

int texpdf_remove_fontmap_record(const char *key)
{
  return pdf_remove_fontmap_record(key);
}

fontmap_rec * texpdf_insert_fontmap_record(const char *key, const fontmap_rec *record)
{
  return pdf_insert_fontmap_record(key, record);
}

fontmap_rec * texpdf_lookup_fontmap_record(const char *key)
{
  return pdf_lookup_fontmap_record(key);
}

int texpdf_color_type(const pdf_color *color)
{
  return pdf_color_type(color);
}

int texpdf_color_rgbcolor(pdf_color *color, double red, double green, double blue)
{
  return pdf_color_rgbcolor(color, red, green, blue);
}

int texpdf_color_cmykcolor(pdf_color *color, double cyan, double magenta, double yellow, double black)
{
  return pdf_color_cmykcolor(color, cyan, magenta, yellow, black);
}

int texpdf_color_graycolor(pdf_color *color, double gray)
{
  return pdf_color_graycolor(color, gray);
}

int texpdf_color_spotcolor(pdf_color *color, char *color_name, double tint)
{
  return pdf_color_spotcolor(color, color_name, tint);
}

void texpdf_color_copycolor(pdf_color *destination, const pdf_color *source)
{
  pdf_color_copycolor(destination, source);
}

void texpdf_color_brighten_color(pdf_color *destination, const pdf_color *source, double factor)
{
  pdf_color_brighten_color(destination, source, factor);
}

int texpdf_color_is_white(const pdf_color *color)
{
  return pdf_color_is_white(color);
}

int texpdf_color_compare(const pdf_color *color1, const pdf_color *color2)
{
  return pdf_color_compare(color1, color2);
}

pdf_obj * texpdf_get_colorspace_reference(int colorspace_id)
{
  return pdf_get_colorspace_reference(colorspace_id);
}

void texpdf_init_colors(void)
{
  pdf_init_colors();
}

void texpdf_close_colors(void)
{
  pdf_close_colors();
}

void texpdf_color_set(pdf_color *stroke_color, pdf_color *fill_color)
{
  pdf_color_set(stroke_color, fill_color);
}

void texpdf_color_push(pdf_color *stroke_color, pdf_color *fill_color)
{
  pdf_color_push(stroke_color, fill_color);
}

void texpdf_color_pop(void)
{
  pdf_color_pop();
}

void texpdf_color_clear_stack(void)
{
  pdf_color_clear_stack();
}

void texpdf_color_get_current(pdf_color **stroke_color, pdf_color **fill_color)
{
  pdf_color_get_current(stroke_color, fill_color);
}

void texpdf_dev_init_gstates(void)
{
  pdf_dev_init_gstates();
}

void texpdf_dev_clear_gstates(void)
{
  pdf_dev_clear_gstates();
}

int texpdf_dev_currentmatrix(pdf_tmatrix *matrix)
{
  return pdf_dev_currentmatrix(matrix);
}

int texpdf_dev_currentpoint(pdf_coord *point)
{
  return pdf_dev_currentpoint(point);
}

int texpdf_dev_setlinewidth(double width)
{
  return pdf_dev_setlinewidth(width);
}

int texpdf_dev_setmiterlimit(double limit)
{
  return pdf_dev_setmiterlimit(limit);
}

int texpdf_dev_setlinecap(int line_cap)
{
  return pdf_dev_setlinecap(line_cap);
}

int texpdf_dev_setlinejoin(int line_join)
{
  return pdf_dev_setlinejoin(line_join);
}

int texpdf_dev_setdash(int dash_count, double *dash_array, double dash_offset)
{
  return pdf_dev_setdash(dash_count, dash_array, dash_offset);
}

int texpdf_dev_moveto(double x, double y)
{
  return pdf_dev_moveto(x, y);
}

int texpdf_dev_rmoveto(double delta_x, double delta_y)
{
  return pdf_dev_rmoveto(delta_x, delta_y);
}

int texpdf_dev_closepath(void)
{
  return pdf_dev_closepath();
}

int texpdf_dev_lineto(double x, double y)
{
  return pdf_dev_lineto(x, y);
}

int texpdf_dev_rlineto(double delta_x, double delta_y)
{
  return pdf_dev_rlineto(delta_x, delta_y);
}

int texpdf_dev_curveto(double x1, double y1, double x2, double y2, double x3, double y3)
{
  return pdf_dev_curveto(x1, y1, x2, y2, x3, y3);
}

int texpdf_dev_rcurveto(double delta_x1, double delta_y1, double delta_x2, double delta_y2, double delta_x3, double delta_y3)
{
  return pdf_dev_rcurveto(delta_x1, delta_y1, delta_x2, delta_y2, delta_x3, delta_y3);
}

int texpdf_dev_arc(double center_x, double center_y, double radius, double start_angle, double end_angle)
{
  return pdf_dev_arc(center_x, center_y, radius, start_angle, end_angle);
}

int texpdf_dev_arcn(double center_x, double center_y, double radius, double start_angle, double end_angle)
{
  return pdf_dev_arcn(center_x, center_y, radius, start_angle, end_angle);
}

int texpdf_dev_newpath(void)
{
  return pdf_dev_newpath();
}

int texpdf_dev_clip(void)
{
  return pdf_dev_clip();
}

int texpdf_dev_eoclip(void)
{
  return pdf_dev_eoclip();
}

int texpdf_dev_rectstroke(double x, double y, double width, double height, const pdf_tmatrix *matrix)
{
  return pdf_dev_rectstroke(x, y, width, height, matrix);
}

int texpdf_dev_rectfill(double x, double y, double width, double height)
{
  return pdf_dev_rectfill(x, y, width, height);
}

int texpdf_dev_rectclip(double x, double y, double width, double height)
{
  return pdf_dev_rectclip(x, y, width, height);
}

int texpdf_dev_flushpath(char path_type, int force)
{
  return pdf_dev_flushpath(path_type, force);
}

int texpdf_dev_locate_font(const char *font_name, spt_t ptsize)
{
  return pdf_dev_locate_font(font_name, ptsize);
}

void texpdf_dev_set_string(spt_t xpos, spt_t ypos, const void *input, int input_length, spt_t text_width, int font_id)
{
  pdf_dev_set_string(xpos, ypos, input, input_length, text_width, font_id);
}

void texpdf_init_device(double unit_conversion, int precision, int ignore_colors)
{
  pdf_init_device(unit_conversion, precision, ignore_colors);
}

void texpdf_close_device(void)
{
  pdf_close_device();
}

void texpdf_open_document(const char *filename, const char *creator, const unsigned char *id1, const unsigned char *id2, struct pdf_setting settings)
{
  pdf_open_document(filename, creator, id1, id2, settings);
}

void texpdf_close_document(void)
{
  pdf_close_document();
}

void texpdf_doc_begin_page(double scale, double x_origin, double y_origin)
{
  pdf_doc_begin_page(scale, x_origin, y_origin);
}

void texpdf_doc_end_page(void)
{
  pdf_doc_end_page();
}

void texpdf_doc_set_mediabox(unsigned page_no, const pdf_rect *mediabox)
{
  pdf_doc_set_mediabox(page_no, mediabox);
}

pdf_obj * texpdf_doc_get_dictionary(const char *category)
{
  return pdf_doc_get_dictionary(category);
}

pdf_obj * texpdf_doc_get_reference(const char *category)
{
  return pdf_doc_get_reference(category);
}

void texpdf_init_resources(void)
{
  pdf_init_resources();
}

void texpdf_close_resources(void)
{
  pdf_close_resources();
}

pdf_obj * texpdf_get_resource_reference(int resource_id)
{
  return pdf_get_resource_reference(resource_id);
}

int texpdf_check_for_pdf(FILE *file)
{
  return check_for_pdf(file);
}

void texpdf_init_images(void)
{
  pdf_init_images();
}

void texpdf_close_images(void)
{
  pdf_close_images();
}

char * texpdf_ximage_get_resname(int xobj_id)
{
  return pdf_ximage_get_resname(xobj_id);
}

void texpdf_set_distiller_template(char *command_template)
{
  set_distiller_template(command_template);
}

char * texpdf_get_distiller_template(void)
{
  return get_distiller_template();
}

struct ht_table * texpdf_new_name_tree(void)
{
  return pdf_new_name_tree();
}

void texpdf_delete_name_tree(struct ht_table **names)
{
  pdf_delete_name_tree(names);
}

int texpdf_names_add_object(struct ht_table *names, const void *key, int key_length, pdf_obj *object)
{
  return pdf_names_add_object(names, key, key_length, object);
}

pdf_obj * texpdf_names_lookup_reference(struct ht_table *names, const void *key, int key_length)
{
  return pdf_names_lookup_reference(names, key, key_length);
}

pdf_obj * texpdf_names_lookup_object(struct ht_table *names, const void *key, int key_length)
{
  return pdf_names_lookup_object(names, key, key_length);
}

int texpdf_names_close_object(struct ht_table *names, const void *key, int key_length)
{
  return pdf_names_close_object(names, key, key_length);
}

pdf_obj * texpdf_names_create_tree(struct ht_table *names, int *count, struct ht_table *filter)
{
  return pdf_names_create_tree(names, count, filter);
}

int texpdf_get_version(void)
{
  return pdf_get_version();
}

pdf_file * texpdf_open(const char *filename, FILE *file)
{
  return pdf_open(filename, file);
}

void texpdf_close(pdf_file *file)
{
  pdf_close(file);
}

int texpdf_file_get_version(pdf_file *file)
{
  return pdf_file_get_version(file);
}

void texpdf_files_init(void)
{
  pdf_files_init();
}

void texpdf_files_close(void)
{
  pdf_files_close();
}

void texpdf_init_encodings(void)
{
  pdf_init_encodings();
}

void texpdf_close_encodings(void)
{
  pdf_close_encodings();
}

pdf_obj * texpdf_get_encoding_obj(int encoding_id)
{
  return pdf_get_encoding_obj(encoding_id);
}

int texpdf_check_for_bmp(FILE *file)
{
  return check_for_bmp(file);
}

int texpdf_bmp_get_bbox(FILE *file, int *x, int *y, double *width, double *height)
{
  return bmp_get_bbox(file, x, y, width, height);
}

int texpdf_check_for_jp2(FILE *file)
{
  return check_for_jp2(file);
}

int texpdf_jp2_get_bbox(FILE *file, int *x, int *y, double *width, double *height)
{
  return jp2_get_bbox(file, x, y, width, height);
}

int texpdf_check_for_jpeg(FILE *file)
{
  return check_for_jpeg(file);
}

int texpdf_jpeg_get_bbox(FILE *file, int *x, int *y, double *width, double *height)
{
  return jpeg_get_bbox(file, x, y, width, height);
}

int texpdf_check_for_png(FILE *file)
{
  return check_for_png(file);
}

int texpdf_png_get_bbox(FILE *file, uint32_t *x, uint32_t *y, double *width, double *height)
{
  return png_get_bbox(file, x, y, width, height);
}

void texpdf_ht_init_table(struct ht_table *table, hval_free_func free_value)
{
  ht_init_table(table, free_value);
}

void texpdf_ht_clear_table(struct ht_table *table)
{
  ht_clear_table(table);
}

void * texpdf_ht_lookup_table(struct ht_table *table, const void *key, int key_length)
{
  return ht_lookup_table(table, key, key_length);
}

void texpdf_ht_append_table(struct ht_table *table, const void *key, int key_length, void *value)
{
  ht_append_table(table, key, key_length, value);
}

char * texpdf_parse_float_decimal(const char **cursor, const char *end)
{
  return parse_float_decimal(cursor, end);
}

char * texpdf_parse_c_string(const char **cursor, const char *end)
{
  return parse_c_string(cursor, end);
}

char * texpdf_parse_c_ident(const char **cursor, const char *end)
{
  return parse_c_ident(cursor, end);
}

void texpdf_debug_level(int quietness)
{
  shut_up(quietness);
}

int texpdf_dev_concat(const pdf_tmatrix *matrix)
{
  return pdf_dev_concat(matrix);
}

// CONVENIENCE API - COMPOSE MULTIPLE DVIPDFMX OPERATIONS

/* Serialize each GID as a big-endian pair before using the existing renderer. */
void texpdf_dev_set_glyphs(spt_t xpos, spt_t ypos, const uint16_t *glyph_ids, int glyph_count, spt_t text_width, int font_id)
{
  unsigned char *encoded_glyphs;
  int i;

  if (glyph_count < 0 || glyph_count > INT_MAX / 2 || (!glyph_ids && glyph_count > 0)) {
    fprintf(stderr, "Invalid glyph array.\n");
    return;
  }
  if (glyph_count == 0) {
    pdf_dev_set_string(xpos, ypos, "", 0, text_width, font_id);
    return;
  }

  encoded_glyphs = malloc((size_t) glyph_count * 2);
  if (!encoded_glyphs) {
    fprintf(stderr, "Unable to allocate glyph buffer.\n");
    return;
  }
  for (i = 0; i < glyph_count; i++) {
    encoded_glyphs[2 * i] = (unsigned char) (glyph_ids[i] >> 8);
    encoded_glyphs[2 * i + 1] = (unsigned char) glyph_ids[i];
  }

  pdf_dev_set_string(xpos, ypos, encoded_glyphs, glyph_count * 2, text_width, font_id);
  free(encoded_glyphs);
}

int texpdf_dev_load_native_font(const char *filename, uint32_t index, spt_t ptsize, int layout_dir, int extend, int slant, int embolden)
{
  char *fontmap_key;
  int key_length;
  int font_id;

  if (!pdf_insert_native_fontmap_record(filename, index, layout_dir, extend, slant, embolden))
    return -1;

  key_length = snprintf(NULL, 0, "%s/%d/%c/%d/%d/%d", filename, (int) index,
                        layout_dir == 0 ? 'H' : 'V', extend, slant, embolden);
  if (key_length < 0)
    return -1;

  fontmap_key = malloc((size_t) key_length + 1);
  if (!fontmap_key)
    return -1;

  snprintf(fontmap_key, (size_t) key_length + 1, "%s/%d/%c/%d/%d/%d",
           filename, (int) index, layout_dir == 0 ? 'H' : 'V', extend, slant, embolden);
  font_id = pdf_dev_locate_font(fontmap_key, ptsize);
  free(fontmap_key);
  return font_id;
}
