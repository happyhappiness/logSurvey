      char *ptr;
      unsigned int size;
 {
-  char *result = (char *) realloc (ptr, size);
+  char *result;
+
+  /* Some older implementations of realloc() don't conform to ANSI.  */
+  result = ptr ? realloc (ptr, size) : malloc (size);
   if (result == 0)
     fatal (NILF, "virtual memory exhausted");
   return result;
