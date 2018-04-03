   /* Make sure we don't allocate 0, for pre-ISO implementations.  */
   void *result = calloc (size ? size : 1, 1);
   if (result == 0)
-    fatal (NILF, _("virtual memory exhausted"));
+    OUT_OF_MEM();
   return result;
 }
 
