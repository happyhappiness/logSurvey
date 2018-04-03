     return o;
 
   if (!entry_p->func_ptr)
-    fatal (reading_file, _("Unimplemented on this platform: function `%s'"),
-           entry_p->name);
+    fatal (*expanding_var,
+           _("unimplemented on this platform: function `%s'"), entry_p->name);
 
   return entry_p->func_ptr (o, argv, entry_p->name);
 }
