   return 1;
 
  invalid_member:
-  ERROR ((0, 0, "%s: invalid sparse archive member", current_file_name));
+  ERROR ((0, 0, _("%s: invalid sparse archive member"),
+	  current_stat_info.file_name));
   return 0;
 }
 
