/* BEGIN LIBTEXPDF PATCH */
/**
 * Recent versions of dvipdfmx rely on kpathsea for file searching.
 * For SILE, we assume resolved file paths and do not perform kpathsea searches.
 * This header provides minimal definitions and function prototypes to satisfy
 * the libtexpdf code that expects kpathsea functions, without actually linking
 * against kpathsea.
 */
#ifndef LIBTEXPDF_KPATHSEA_SHIM_H
#define LIBTEXPDF_KPATHSEA_SHIM_H

#include <stdio.h>
#include <stdbool.h>
#include <errno.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/stat.h>
#ifndef _MSC_VER
#include <dirent.h>
#endif

#define FOPEN_RBIN_MODE "rb"
#define FOPEN_WBIN_MODE "wb"
#if defined(WIN32) || defined(_WIN32)
#define IS_DIR_SEP(c) ((c) == '/' || (c) == '\\')
#else
#define IS_DIR_SEP(c) ((c) == '/')
#endif

typedef const char *const_string;
typedef char *string;
typedef void *address;
typedef int boolean;
typedef enum {
    kpse_cmap_format,
    kpse_enc_format,
    kpse_fontmap_format,
    kpse_opentype_format,
    kpse_program_binary_format,
    kpse_program_text_format,
    kpse_sfd_format,
    kpse_truetype_format,
    kpse_type1_format,
    kpse_last_format = 57
} kpse_file_format_type;

#define kpse_reset_program_name(program_name) ((void) (program_name))
string kpse_find_file (const_string filename, kpse_file_format_type format,
                       boolean must_exist);
string kpse_find_pict (const_string filename);
string xstrdup (const_string value);
address xcalloc (size_t count, size_t size);
string xgetcwd (void);
void xfseeko (FILE *file, off_t offset, int whence, const_string filename);
off_t xftello (FILE *file, const_string filename);

#endif
/* END LIBTEXPDF PATCH */