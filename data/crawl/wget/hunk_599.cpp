 
 ## end   gnulib module c-ctype
 
+## begin gnulib module configmake
+
+# Retrieve values of the variables through 'configure' followed by
+# 'make', not directly through 'configure', so that a user who
+# sets some of these variables consistently on the 'make' command
+# line gets correct results.
+#
+# One advantage of this approach, compared to the classical
+# approach of adding -DLIBDIR=\"$(libdir)\" etc. to AM_CPPFLAGS,
+# is that it protects against the use of undefined variables.
+# If, say, $(libdir) is not set in the Makefile, LIBDIR is not
+# defined by this module, and code using LIBDIR gives a
+# compilation error.
+#
+# Another advantage is that 'make' output is shorter.
+#
+# Listed in the same order as the GNU makefile conventions.
+# The Automake-defined pkg* macros are appended, in the order
+# listed in the Automake 1.10a+ documentation.
+configmake.h: Makefile
+	rm -f $@-t
+	{ echo '/* DO NOT EDIT! GENERATED AUTOMATICALLY! */'; \
+	  echo '#define PREFIX "$(prefix)"'; \
+	  echo '#define EXEC_PREFIX "$(exec_prefix)"'; \
+	  echo '#define BINDIR "$(bindir)"'; \
+	  echo '#define SBINDIR "$(sbindir)"'; \
+	  echo '#define LIBEXECDIR "$(libexecdir)"'; \
+	  echo '#define DATAROOTDIR "$(datarootdir)"'; \
+	  echo '#define DATADIR "$(datadir)"'; \
+	  echo '#define SYSCONFDIR "$(sysconfdir)"'; \
+	  echo '#define SHAREDSTATEDIR "$(sharedstatedir)"'; \
+	  echo '#define LOCALSTATEDIR "$(localstatedir)"'; \
+	  echo '#define INCLUDEDIR "$(includedir)"'; \
+	  echo '#define OLDINCLUDEDIR "$(oldincludedir)"'; \
+	  echo '#define DOCDIR "$(docdir)"'; \
+	  echo '#define INFODIR "$(infodir)"'; \
+	  echo '#define HTMLDIR "$(htmldir)"'; \
+	  echo '#define DVIDIR "$(dvidir)"'; \
+	  echo '#define PDFDIR "$(pdfdir)"'; \
+	  echo '#define PSDIR "$(psdir)"'; \
+	  echo '#define LIBDIR "$(libdir)"'; \
+	  echo '#define LISPDIR "$(lispdir)"'; \
+	  echo '#define LOCALEDIR "$(localedir)"'; \
+	  echo '#define MANDIR "$(mandir)"'; \
+	  echo '#define MANEXT "$(manext)"'; \
+	  echo '#define PKGDATADIR "$(pkgdatadir)"'; \
+	  echo '#define PKGINCLUDEDIR "$(pkgincludedir)"'; \
+	  echo '#define PKGLIBDIR "$(pkglibdir)"'; \
+	  echo '#define PKGLIBEXECDIR "$(pkglibexecdir)"'; \
+	} | sed '/""/d' > $@-t
+	if test -f $@ && cmp $@-t $@ > /dev/null; then \
+	  rm -f $@-t; \
+	else \
+	  rm -f $@; mv $@-t $@; \
+	fi
+
+BUILT_SOURCES += configmake.h
+CLEANFILES += configmake.h configmake.h-t
+
+## end   gnulib module configmake
+
+## begin gnulib module errno
+
+BUILT_SOURCES += $(ERRNO_H)
+
+# We need the following in order to create <errno.h> when the system
+# doesn't have one that is POSIX compliant.
+errno.h: errno.in.h
+	rm -f $@-t $@
+	{ echo '/* DO NOT EDIT! GENERATED AUTOMATICALLY! */' && \
+	  sed -e 's|@''INCLUDE_NEXT''@|$(INCLUDE_NEXT)|g' \
+	      -e 's|@''PRAGMA_SYSTEM_HEADER''@|@PRAGMA_SYSTEM_HEADER@|g' \
+	      -e 's|@''NEXT_ERRNO_H''@|$(NEXT_ERRNO_H)|g' \
+	      -e 's|@''EMULTIHOP_HIDDEN''@|$(EMULTIHOP_HIDDEN)|g' \
+	      -e 's|@''EMULTIHOP_VALUE''@|$(EMULTIHOP_VALUE)|g' \
+	      -e 's|@''ENOLINK_HIDDEN''@|$(ENOLINK_HIDDEN)|g' \
+	      -e 's|@''ENOLINK_VALUE''@|$(ENOLINK_VALUE)|g' \
+	      -e 's|@''EOVERFLOW_HIDDEN''@|$(EOVERFLOW_HIDDEN)|g' \
+	      -e 's|@''EOVERFLOW_VALUE''@|$(EOVERFLOW_VALUE)|g' \
+	      < $(srcdir)/errno.in.h; \
+	} > $@-t
+	mv $@-t $@
+MOSTLYCLEANFILES += errno.h errno.h-t
+
+EXTRA_DIST += errno.in.h
+
+## end   gnulib module errno
+
 ## begin gnulib module error
 
 
