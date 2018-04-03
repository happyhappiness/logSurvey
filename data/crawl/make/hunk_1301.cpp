 {
   char *result = (char *) malloc (size);
   if (result == 0)
-    fatal ("virtual memory exhausted");
+    fatal (NILF, "virtual memory exhausted");
   return result;
 }
 
