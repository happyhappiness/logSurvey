       /* Get back to the initial shift state.  */
       res = iconv (utf8_to_local, NULL, NULL, &outptr, &outbytesleft);
       if (res == (size_t)(-1))
-	return failure (code, callback_arg);
+	return failure (code, NULL, callback_arg);
 # endif
 
       return success (outbuf, outptr - outbuf, callback_arg);
-#else
-      errno = ENOTSUP;
-      return failure (code, callback_arg);
-#endif
     }
+#endif
+
+  /* At this point, is_utf8 is true, so no conversion is needed.  */
+  return success (inbuf, count, callback_arg);
 }
 
 /* Simple success callback that outputs the converted string.
    The STREAM is passed as callback_arg.  */
-int
-print_unicode_success (const char *buf, size_t buflen, void *callback_arg)
+long
+fwrite_success_callback (const char *buf, size_t buflen, void *callback_arg)
 {
   FILE *stream = (FILE *) callback_arg;
 
-  return fwrite (buf, 1, buflen, stream) == 0 ? -1 : 0;
+  fwrite (buf, 1, buflen, stream);
+  return 0;
 }
 
-/* Simple failure callback that prints an ASCII representation, using
-   the same notation as C99 strings.  */
-int
-print_unicode_failure (unsigned int code, void *callback_arg)
+/* Simple failure callback that displays an error and exits.  */
+static long
+exit_failure_callback (unsigned int code, const char *msg, void *callback_arg)
 {
-  int e = errno;
-  FILE *stream = callback_arg;
-  
-  fprintf (stream, code < 0x10000 ? "\\u%04X" : "\\U%08X", code);
-  errno = e;
+  if (msg == NULL)
+    error (1, 0, _("cannot convert U+%04X to local character set"), code);
+  else
+    error (1, 0, _("cannot convert U+%04X to local character set: %s"), code,
+	   gettext (msg));
+  return -1;
+}
+
+/* Simple failure callback that displays a fallback representation in plain
+   ASCII, using the same notation as ISO C99 strings.  */
+static long
+fallback_failure_callback (unsigned int code, const char *msg, void *callback_arg)
+{
+  FILE *stream = (FILE *) callback_arg;
+
+  if (code < 0x10000)
+    fprintf (stream, "\\u%04X", code);
+  else
+    fprintf (stream, "\\U%08X", code);
   return -1;
 }
 
 /* Outputs the Unicode character CODE to the output stream STREAM.
-   Returns zero if successful, -1 (setting errno) otherwise.
-   Assumes that the locale doesn't change between two calls.  */
-int
-print_unicode_char (FILE *stream, unsigned int code)
+   Upon failure, exit if exit_on_error is true, otherwise output a fallback
+   notation.  */
+void
+print_unicode_char (FILE *stream, unsigned int code, int exit_on_error)
 {
-  return unicode_to_mb (code, print_unicode_success, print_unicode_failure,
-			stream);
+  unicode_to_mb (code, fwrite_success_callback,
+		 exit_on_error
+		 ? exit_failure_callback
+		 : fallback_failure_callback,
+		 stream);
 }
