     }
 
   errno = 0;
-  len = strtoul (p, &len_lim, 10);
-
+  len = u = strtoumax (p, &len_lim, 10);
+  if (len != u || errno == ERANGE)
+    {
+      ERROR ((0, 0, _("Extended header length is out of allowed range")));
+      return false;
+    }
+  
   if (len_max < len)
     {
       int len_len = len_lim - p;
