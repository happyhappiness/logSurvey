+2000-11-04  Hrvoje Niksic  <hniksic@arsdigita.com>
+
+	* snprintf.c: New file.
+
+2000-11-03  Hrvoje Niksic  <hniksic@arsdigita.com>
+
+	* wget.h: If HAVE_STDARG_H is not defined, don't declare argument
+	types to logprintf() and debug_logprintf().
+
 2000-11-02  Hrvoje Niksic  <hniksic@arsdigita.com>
 
 	* ftp.c (ftp_loop_internal): Hide the password from the URL when
