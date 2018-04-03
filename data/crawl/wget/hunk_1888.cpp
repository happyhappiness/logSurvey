     return;
   CHECK_VERBOSE (o);
 
-  fputs (s, fp);
+  FPUTS (s, fp);
   if (save_context_p)
     saved_append (s);
   if (flush_log_p)
