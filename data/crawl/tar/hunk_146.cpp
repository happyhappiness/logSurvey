   errno = 0;
   len = strtoul (p, &len_lim, 10);
 
-  if (len_max < len || (len == ULONG_MAX && errno == ERANGE))
+  if (len_max < len)
     {
-      ERROR ((0, 0, _("Malformed extended header: length out of range")));
+      int len_len = len_lim - p;
+      ERROR ((0, 0, _("Extended header length %*s is out of range"),
+	      len_len, p));
       return false;
     }
 
