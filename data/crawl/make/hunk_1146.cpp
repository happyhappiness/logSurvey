 {
   char *result = (char *) malloc (size);
   if (result == 0)
-    fatal (NILF, "virtual memory exhausted");
+    fatal (NILF, _("virtual memory exhausted"));
   return result;
 }
 
