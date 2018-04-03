 {
   struct file_memory *fm;
   FILE               *fp;
-  char               *p;
+  const char         *p;
   downloaded_file_t  downloaded_file_return;
 
   logprintf (LOG_VERBOSE, _("Converting %s... "), file);
