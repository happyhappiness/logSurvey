       break;
 
   if (count >= 0)
-    fatal (*expanding_var,
+    fatal (*expanding_var, strlen (entry_p->name),
            _("unterminated call to function '%s': missing '%c'"),
            entry_p->name, closeparen);
 
