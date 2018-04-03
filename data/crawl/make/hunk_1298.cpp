 	  else
 	    printf ("%s[%u]: ", program, makelevel);
 	}
-      printf (s1, s2, s3, s4, s5, s6);
+      VA_START (args, fmt);
+      VA_PRINTF (stdout, fmt, args);
+      VA_END (args);
       putchar ('\n');
     }
 
   fflush (stdout);
 }
 
-/* Print an error message and exit.  */
+/* Print an error message.  */
 
-/* VARARGS1 */
 void
-fatal (s1, s2, s3, s4, s5, s6)
-     char *s1, *s2, *s3, *s4, *s5, *s6;
+#if __STDC__ && HAVE_STDVARARGS
+error (const struct floc *flocp, const char *fmt, ...)
+#else
+error (flocp, fmt, va_alist)
+     const struct floc *flocp;
+     const char *fmt;
+     va_dcl
+#endif
 {
-  log_working_directory (1);
-
-  if (makelevel == 0)
-    fprintf (stderr, "%s: *** ", program);
-  else
-    fprintf (stderr, "%s[%u]: *** ", program, makelevel);
-  fprintf (stderr, s1, s2, s3, s4, s5, s6);
-  fputs (".  Stop.\n", stderr);
-
-  die (2);
-}
-
-/* Print error message.  `s1' is printf control string, `s2' is arg for it. */
-
-/* VARARGS1 */
+#if HAVE_STDVARARGS
+  va_list args;
+#endif
 
-void
-error (s1, s2, s3, s4, s5, s6)
-     char *s1, *s2, *s3, *s4, *s5, *s6;
-{
   log_working_directory (1);
 
-  if (makelevel == 0)
+  if (flocp && flocp->filenm)
+    fprintf (stderr, "%s:%lu: ", flocp->filenm, flocp->lineno);
+  else if (makelevel == 0)
     fprintf (stderr, "%s: ", program);
   else
     fprintf (stderr, "%s[%u]: ", program, makelevel);
-  fprintf (stderr, s1, s2, s3, s4, s5, s6);
-  putc ('\n', stderr);
-  fflush (stderr);
-}
 
-void
-makefile_error (file, lineno, s1, s2, s3, s4, s5, s6)
-     char *file;
-     unsigned int lineno;
-     char *s1, *s2, *s3, *s4, *s5, *s6;
-{
-  log_working_directory (1);
+  VA_START(args, fmt);
+  VA_PRINTF (stderr, fmt, args);
+  VA_END (args);
 
-  fprintf (stderr, "%s:%u: ", file, lineno);
-  fprintf (stderr, s1, s2, s3, s4, s5, s6);
   putc ('\n', stderr);
   fflush (stderr);
 }
 
+/* Print an error message and exit.  */
+
 void
-makefile_fatal (file, lineno, s1, s2, s3, s4, s5, s6)
-     char *file;
-     unsigned int lineno;
-     char *s1, *s2, *s3, *s4, *s5, *s6;
+#if __STDC__ && HAVE_STDVARARGS
+fatal (const struct floc *flocp, const char *fmt, ...)
+#else
+fatal (flocp, fmt, va_alist)
+     const struct floc *flocp;
+     const char *fmt;
+     va_dcl
+#endif
 {
-  if (!file)
-    fatal(s1, s2, s3, s4, s5, s6);
+#if HAVE_STDVARARGS
+  va_list args;
+#endif
 
   log_working_directory (1);
 
-  fprintf (stderr, "%s:%u: *** ", file, lineno);
-  fprintf (stderr, s1, s2, s3, s4, s5, s6);
+  if (flocp && flocp->filenm)
+    fprintf (stderr, "%s:%lu: *** ", flocp->filenm, flocp->lineno);
+  else if (makelevel == 0)
+    fprintf (stderr, "%s: *** ", program);
+  else
+    fprintf (stderr, "%s[%u]: *** ", program, makelevel);
+
+  VA_START(args, fmt);
+  VA_PRINTF (stderr, fmt, args);
+  VA_END (args);
+
   fputs (".  Stop.\n", stderr);
 
   die (2);
