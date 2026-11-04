ACLOCAL_AMFLAGS = -I build-aux

AM_CPPFLAGS = $(LIBPNG_INCLUDES) $(ZLIB_INCLUDES) $(LIBPAPER_INCLUDES) -I$(top_srcdir) -I$(top_srcdir)/dvipdfm-x -I$(top_builddir)

licensedir = $(datarootdir)/licenses/$(PACKAGE_NAME)
dist_license_DATA = LICENSE

lib_LTLIBRARIES = libtexpdf.la

libtexpdf_la_CPPFLAGS = -DXETEX -DBUILDING_LIBTEXPDF $(AM_CPPFLAGS)
libtexpdf_la_LDFLAGS = -no-undefined -export-symbols-regex '^texpdf_'

AM_CFLAGS = $(WARNING_CFLAGS)

libtexpdf_la_SOURCES = \
	kpathsea_shim.c \
	kpathsea_shim.h \
	libtexpdf.c \
	dvipdfm-x/agl.c \
	dvipdfm-x/agl.h \
	dvipdfm-x/bmpimage.c \
	dvipdfm-x/bmpimage.h \
	dvipdfm-x/cff.c \
	dvipdfm-x/cff.h \
	dvipdfm-x/cff_dict.c \
	dvipdfm-x/cff_dict.h \
	dvipdfm-x/cff_limits.h \
	dvipdfm-x/cff_stdstr.h \
	dvipdfm-x/cff_types.h \
	dvipdfm-x/cid_basefont.h \
	dvipdfm-x/cid.c \
	dvipdfm-x/cid.h \
	dvipdfm-x/cidtype0.c \
	dvipdfm-x/cidtype0.h \
	dvipdfm-x/cidtype2.c \
	dvipdfm-x/cidtype2.h \
	dvipdfm-x/cmap.c \
	dvipdfm-x/cmap.h \
	dvipdfm-x/cmap_p.h \
	dvipdfm-x/cmap_read.c \
	dvipdfm-x/cmap_read.h \
	dvipdfm-x/cmap_write.c \
	dvipdfm-x/cmap_write.h \
	dvipdfm-x/cs_type2.c \
	dvipdfm-x/cs_type2.h \
	dvipdfm-x/dpxconf.c \
	dvipdfm-x/dpxconf.h \
	dvipdfm-x/dpxcrypt.c \
	dvipdfm-x/dpxcrypt.h \
	dvipdfm-x/dpxfile.c \
	dvipdfm-x/dpxfile.h \
	dvipdfm-x/dpxutil.c \
	dvipdfm-x/dpxutil.h \
	dvipdfm-x/epdf.c \
	dvipdfm-x/epdf.h \
	dvipdfm-x/error.c \
	dvipdfm-x/error.h \
	dvipdfm-x/fontmap.c \
	dvipdfm-x/fontmap.h \
	dvipdfm-x/jp2image.c \
	dvipdfm-x/jp2image.h \
	dvipdfm-x/jpegimage.c \
	dvipdfm-x/jpegimage.h \
	dvipdfm-x/mem.c \
	dvipdfm-x/mem.h \
	dvipdfm-x/mfileio.c \
	dvipdfm-x/mfileio.h \
	dvipdfm-x/mt19937ar.c \
	dvipdfm-x/numbers.c \
	dvipdfm-x/numbers.h \
	dvipdfm-x/otl_opt.c \
	dvipdfm-x/otl_opt.h \
	dvipdfm-x/pdfcolor.c \
	dvipdfm-x/pdfcolor.h \
	dvipdfm-x/pdfdev.c \
	dvipdfm-x/pdfdev.h \
	dvipdfm-x/pdfdoc.c \
	dvipdfm-x/pdfdoc.h \
	dvipdfm-x/pdfdraw.c \
	dvipdfm-x/pdfdraw.h \
	dvipdfm-x/pdfencrypt.c \
	dvipdfm-x/pdfencrypt.h \
	dvipdfm-x/pdfencoding.c \
	dvipdfm-x/pdfencoding.h \
	dvipdfm-x/pdffont.c \
	dvipdfm-x/pdffont.h \
	dvipdfm-x/pdflimits.h \
	dvipdfm-x/pdfnames.c \
	dvipdfm-x/pdfnames.h \
	dvipdfm-x/pdfobj.c \
	dvipdfm-x/pdfobj.h \
	dvipdfm-x/pdfparse.c \
	dvipdfm-x/pdfparse.h \
	dvipdfm-x/pdfresource.c \
	dvipdfm-x/pdfresource.h \
	dvipdfm-x/pdfximage.c \
	dvipdfm-x/pdfximage.h \
	dvipdfm-x/pngimage.c \
	dvipdfm-x/pngimage.h \
	dvipdfm-x/pst.c \
	dvipdfm-x/pst.h \
	dvipdfm-x/pst_obj.c \
	dvipdfm-x/pst_obj.h \
	dvipdfm-x/sfnt.c \
	dvipdfm-x/sfnt.h \
	dvipdfm-x/subfont.c \
	dvipdfm-x/subfont.h \
	dvipdfm-x/system.h \
	dvipdfm-x/t1_char.c \
	dvipdfm-x/t1_char.h \
	dvipdfm-x/t1_load.c \
	dvipdfm-x/t1_load.h \
	dvipdfm-x/truetype.c \
	dvipdfm-x/truetype.h \
	dvipdfm-x/tt_aux.c \
	dvipdfm-x/tt_aux.h \
	dvipdfm-x/tt_cmap.c \
	dvipdfm-x/tt_cmap.h \
	dvipdfm-x/tt_glyf.c \
	dvipdfm-x/tt_glyf.h \
	dvipdfm-x/tt_gsub.c \
	dvipdfm-x/tt_gsub.h \
	dvipdfm-x/tt_post.c \
	dvipdfm-x/tt_post.h \
	dvipdfm-x/tt_table.c \
	dvipdfm-x/tt_table.h \
	dvipdfm-x/type0.c \
	dvipdfm-x/type0.h \
	dvipdfm-x/type1.c \
	dvipdfm-x/type1.h \
	dvipdfm-x/type1c.c \
	dvipdfm-x/type1c.h \
	dvipdfm-x/unicode.c \
	dvipdfm-x/unicode.h

pkginclude_HEADERS = \
	libtexpdf.h \
	kpathsea_shim.h \
	dvipdfm-x/agl.h \
	dvipdfm-x/bmpimage.h \
	dvipdfm-x/cff.h \
	dvipdfm-x/cff_dict.h \
	dvipdfm-x/cff_limits.h \
	dvipdfm-x/cff_stdstr.h \
	dvipdfm-x/cff_types.h \
	dvipdfm-x/cid_basefont.h \
	dvipdfm-x/cid.h \
	dvipdfm-x/cidtype0.h \
	dvipdfm-x/cidtype2.h \
	dvipdfm-x/cmap.h \
	dvipdfm-x/cmap_p.h \
	dvipdfm-x/cmap_read.h \
	dvipdfm-x/cmap_write.h \
	dvipdfm-x/cs_type2.h \
	dvipdfm-x/dpxcrypt.h \
	dvipdfm-x/dpxfile.h \
	dvipdfm-x/dpxutil.h \
	dvipdfm-x/epdf.h \
	dvipdfm-x/error.h \
	dvipdfm-x/fontmap.h \
	dvipdfm-x/jp2image.h \
	dvipdfm-x/jpegimage.h \
	dvipdfm-x/mem.h \
	dvipdfm-x/mfileio.h \
	dvipdfm-x/numbers.h \
	dvipdfm-x/otl_opt.h \
	dvipdfm-x/pdfcolor.h \
	dvipdfm-x/pdfdev.h \
	dvipdfm-x/pdfdoc.h \
	dvipdfm-x/pdfdraw.h \
	dvipdfm-x/pdfencrypt.h \
	dvipdfm-x/pdfencoding.h \
	dvipdfm-x/pdffont.h \
	dvipdfm-x/pdflimits.h \
	dvipdfm-x/pdfnames.h \
	dvipdfm-x/pdfobj.h \
	dvipdfm-x/pdfparse.h \
	dvipdfm-x/pdfresource.h \
	dvipdfm-x/pdftypes.h \
	dvipdfm-x/pdfximage.h \
	dvipdfm-x/pngimage.h \
	dvipdfm-x/pst.h \
	dvipdfm-x/pst_obj.h \
	dvipdfm-x/sfnt.h \
	dvipdfm-x/subfont.h \
	dvipdfm-x/system.h \
	dvipdfm-x/t1_char.h \
	dvipdfm-x/t1_load.h \
	dvipdfm-x/truetype.h \
	dvipdfm-x/tt_aux.h \
	dvipdfm-x/tt_cmap.h \
	dvipdfm-x/tt_glyf.h \
	dvipdfm-x/tt_gsub.h \
	dvipdfm-x/tt_post.h \
	dvipdfm-x/tt_table.h \
	dvipdfm-x/type0.h \
	dvipdfm-x/type1.h \
	dvipdfm-x/type1c.h \
	dvipdfm-x/unicode.h

libtexpdf_la_LIBADD = $(LIBPNG_LIBS) $(ZLIB_LIBS) $(LIBPAPER_LIBS)
