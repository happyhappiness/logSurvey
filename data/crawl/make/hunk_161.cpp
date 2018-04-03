       break;
 
   if (s <= end || end - beg < 0)
-    fatal (*expanding_var, "%s: '%s'", msg, beg);
+    OSS (fatal, *expanding_var, "%s: '%s'", msg, beg);
 }
 
 
