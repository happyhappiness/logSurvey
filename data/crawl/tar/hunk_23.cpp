       return false;
     }
 
-  errno = 0;
-  len = u = strtoumax (p, &len_lim, 10);
-  if (len != u || errno == ERANGE)
-    {
-      ERROR ((0, 0, _("Extended header length is out of allowed range")));
-      return false;
-    }
+  len = strtoumax (p, &len_lim, 10);
 
   if (len_max < len)
     {
