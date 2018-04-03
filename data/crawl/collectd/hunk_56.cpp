   }
 
   if (ds->ds_num != values_num) {
-    ERROR("ds[%s]->ds_num = %zu, "
-          "but uc_get_rate_by_name returned %zu values.",
+    ERROR("ds[%s]->ds_num = %" PRIsz ", "
+          "but uc_get_rate_by_name returned %" PRIsz " values.",
           ds->type, ds->ds_num, values_num);
     cmd_error(CMD_ERROR, &err, "Error reading value from cache.");
     sfree(values);
     cmd_destroy(&cmd);
     return CMD_ERROR;
   }
 
-  print_to_socket(fh, "%zu Value%s found\n", values_num,
+  print_to_socket(fh, "%" PRIsz " Value%s found\n", values_num,
                   (values_num == 1) ? "" : "s");
   for (size_t i = 0; i < values_num; i++) {
     print_to_socket(fh, "%s=", ds->ds[i].name);
