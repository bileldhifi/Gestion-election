## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = projetfinal

projetfinal_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h \
	bv.c bv.h \
	list.c list.h \
	statrin.c statrin.h \
	Election.c Election.h \
	utilisateur.c utilisateur.h \
	fct.c fct.h 

projetfinal_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)

