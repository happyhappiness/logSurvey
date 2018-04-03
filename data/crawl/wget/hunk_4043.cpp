 void
 convert_links (const char *file, urlpos *l)
 {
-  FILE           *fp;
-  char           *buf, *p, *p2;
-  long           size;
-  static slist*  converted_files = NULL;
+  FILE *fp;
+  char *buf, *p, *p2;
+  long size;
 
   logprintf (LOG_VERBOSE, _("Converting %s... "), file);
   /* Read from the file....  */
