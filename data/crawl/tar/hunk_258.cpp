 
   if (**p != '=')
     {
-      ERROR ((0, 0, _("Malformed extended headed")));
-      return 1;
+      ERROR ((0, 0, _("Malformed extended header")));
+      return true;
     }
 
   eqp = *p;
