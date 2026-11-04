/* Minimal global-state API example: embed a native font and draw HIJKLMNO.
 * Input is font-specific glyph IDs, not UTF-8 text.
 */

#include <stdio.h>
#include <stdint.h>
#include "libtexpdf.h"

static int load_font (const char *filename)
{
  uint32_t index = 0;
  int layout_dir = 0;
  int extend = 65536;
  int slant = 0;
  int embolden = 0;
  double ptsize = 12.0 * 1.5;

  return texpdf_dev_load_native_font(filename, index, ptsize, layout_dir, extend, slant, embolden);
}

int main (int argc, char **argv)
{
  /* The current API requires two 16-byte PDF trailer IDs; use fixed POC values. */
  static const unsigned char id1[16] = { 0 };
  static const unsigned char id2[16] = { 0 };
  struct pdf_setting settings = {
    .ver_major = 1,
    .ver_minor = 7,
    .media_width = 595.275597,
    .media_height = 841.889773,
    .check_gotos = 1,
    .device = {
      .dvi2pts = 1.0,
      .precision = 3
    },
    .object = {
      .enable_objstm = 1,
      .enable_predictor = 1,
      .compression_level = 9
    }
  };
  pdf_rect mediabox;
  /* These DejaVu Sans glyph IDs produce HIJKLMNO; IDs vary by font. */
  static const uint16_t glyphs[] = { 43, 44, 45, 46, 47, 48, 49, 50 };
  int font_id;

  /* Require one font-file argument for this example. */
  if (argc != 2) {
    /* Show the required invocation. */
    fprintf(stderr, "Usage: %s FONTFILE\n", argv[0]);
    /* Report invalid command-line arguments. */
    return 2;
  }

  /* Initialize global font-map state before registering a font. */
  texpdf_init_fontmaps();
  /* Open the global PDF document; the API does not return a document pointer. */
  texpdf_open_document("test.pdf", "libtexpdf POC", id1, id2, settings);

  mediabox.llx = 0.0;
  mediabox.lly = 0.0;
  mediabox.urx = 595.275597;
  /* Use the rounded A4 height matching the document defaults. */
  mediabox.ury = 841.889773;
  /* Set the root page box through the global document API. */
  texpdf_doc_set_mediabox(0, &mediabox);
  /* Begin a page with the standard one-inch origin. */
  texpdf_doc_begin_page(1.0, 72.0, 770.0);

  /* Load the native font and resolve its map key. */
  font_id = load_font(argv[1]);
  /* Stop if the low-level font lookup fails. */
  if (font_id < 0) {
    /* Identify the font that failed to load. */
    fprintf(stderr, "Could not load font: %s\n", argv[1]);
    /* Close the active document on this error path. */
    texpdf_close_document();
    /* Release font-map state before returning. */
    texpdf_close_fontmaps();
    /* Report the font-loading failure to the caller. */
    return 1;
  }
  /* Draw the selected glyphs using the resolved font ID. */
  texpdf_dev_set_glyphs(92.0, -10.0, glyphs, (int) (sizeof(glyphs) / sizeof(glyphs[0])), 0, font_id);
  /* Finish the page before closing the document. */
  texpdf_doc_end_page();
  /* Finalize and close the global PDF document. */
  texpdf_close_document();
  /* Release font-map records after document output. */
  texpdf_close_fontmaps();

  return 0;
}
