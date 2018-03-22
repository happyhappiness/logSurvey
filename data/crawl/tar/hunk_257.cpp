   return NULL;
 }
 
-static int
+static bool
 decode_record (char **p, struct tar_stat_info *st)
 {
   size_t len;
-  char *keyword, *eqp;
+  char const *keyword;
+  char *eqp;
   char *start = *p;
-  struct xhdr_tab *t;
+  struct xhdr_tab const *t;
 
   if (**p == 0)
-    return 1;
-  
+    return true;
+
   len = strtoul (*p, p, 10);
   if (**p != ' ')
     {
-      ERROR ((0, 0, _("Malformed extended headed")));
-      return 1;
+      ERROR ((0, 0, _("Malformed extended header")));
+      return true;
     }
-  
+
   keyword = ++*p;
   for (;*p < start + len; ++*p)
     if (**p == '=')
