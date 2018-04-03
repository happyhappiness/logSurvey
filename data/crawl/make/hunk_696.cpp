       break;
 
   if (s <= end || end - beg < 0)
-    fatal (reading_file, "%s: '%s'", message, beg);
+    fatal (*expanding_var, "%s: '%s'", message, beg);
 }
 
 
