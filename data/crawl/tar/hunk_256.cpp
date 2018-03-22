 
   if (**p != '=')
     {
-      ERROR ((0, 0, _("Malformed extended header")));
-      return true;
+      ERROR ((0, 0, _("Malformed extended header: missing equal sign")));
+      return false;
     }
 
   eqp = *p;
