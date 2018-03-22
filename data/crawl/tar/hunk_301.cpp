       /* Get back to the initial shift state.  */
       res = iconv (utf8_to_local, NULL, NULL, &outptr, &outbytesleft);
       if (res == (size_t)(-1))
-	error (1, errno, _("cannot convert U+%04X to local character set"),
-	       code);
+	return failure (code, callback_arg);
 # endif
 
-      callback (outbuf, outptr - outbuf, callback_arg);
+      return success (outbuf, outptr - outbuf, callback_arg);
 #else
-      error (1, 0,
-	     _("cannot convert U+%04X to local character set: iconv function not available"),
-	     code);
+      errno = ENOTSUP;
+      return failure (code, callback_arg);
 #endif
     }
 }
 
-/* Simple callback that outputs the converted string.
+/* Simple success callback that outputs the converted string.
    The STREAM is passed as callback_arg.  */
-static void
-fprintf_callback (const char *buf, size_t buflen, void *callback_arg)
+int
+print_unicode_success (const char *buf, size_t buflen, void *callback_arg)
 {
   FILE *stream = (FILE *) callback_arg;
 
-  fwrite (buf, 1, buflen, stream);
+  return fwrite (buf, 1, buflen, stream) == 0 ? -1 : 0;
+}
+
+/* Simple failure callback that prints an ASCII representation, using
+   the same notation as C99 strings.  */
+int
+print_unicode_failure (unsigned int code, void *callback_arg)
+{
+  int e = errno;
+  FILE *stream = callback_arg;
+  
+  fprintf (stream, code < 0x10000 ? "\\u%04X" : "\\U%08X", code);
+  errno = e;
+  return -1;
 }
 
 /* Outputs the Unicode character CODE to the output stream STREAM.
+   Returns zero if successful, -1 (setting errno) otherwise.
    Assumes that the locale doesn't change between two calls.  */
-void
+int
 print_unicode_char (FILE *stream, unsigned int code)
 {
-  unicode_to_mb (code, fprintf_callback, stream);
+  return unicode_to_mb (code, print_unicode_success, print_unicode_failure,
+			stream);
 }
