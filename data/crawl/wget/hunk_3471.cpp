 void
 logputs (enum log_options o, const char *s)
 {
-  CHECK_VERBOSE (o);
-  CANONICALIZE_LOGFP_OR_RETURN;
+  FILE *fp;
 
-  fputs (s, logfp);
-  if (save_log_p)
-    saved_append (s);
+  check_redirect_output ();
+  if (!(fp = get_log_fp ()))
+    return;
 
+  fputs (s, fp);
+  if (save_context_p)
+    saved_append (s);
   if (flush_log_p)
     logflush ();
   else
