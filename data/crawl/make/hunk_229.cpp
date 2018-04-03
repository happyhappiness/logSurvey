 #endif
 
   if (result == 0)
-    fatal (NILF, _("virtual memory exhausted"));
+    OUT_OF_MEM();
 
 #ifdef HAVE_STRDUP
   return result;
