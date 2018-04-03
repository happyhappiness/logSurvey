       break;
 
   if (count >= 0)
-    fatal (reading_file,
+    fatal (*expanding_var,
 	   _("unterminated call to function `%s': missing `%c'"),
 	   entry_p->name, closeparen);
 
