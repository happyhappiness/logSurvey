           sh_found = 1;
       }
 
-      if (debug_flag && sh_found)
-        printf(_("find_and_set_shell path search set default_shell = %s\n"), default_shell);
+      if (sh_found)
+        DB (DB_EXTRA,
+            (_("find_and_set_shell path search set default_shell = %s\n"),
+             default_shell));
     }
   }
 
