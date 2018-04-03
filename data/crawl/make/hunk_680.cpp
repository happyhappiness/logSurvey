 #undef xrealloc
 #undef xstrdup
 
-char *
+void *
 xmalloc (unsigned int size)
 {
   /* Make sure we don't allocate 0, for pre-ANSI libraries.  */
-  char *result = (char *) malloc (size ? size : 1);
+  void *result = malloc (size ? size : 1);
   if (result == 0)
     fatal (NILF, _("virtual memory exhausted"));
   return result;
 }
 
 
-char *
-xrealloc (char *ptr, unsigned int size)
+void *
+xrealloc (void *ptr, unsigned int size)
 {
-  char *result;
+  void *result;
 
   /* Some older implementations of realloc() don't conform to ANSI.  */
   if (! size)
