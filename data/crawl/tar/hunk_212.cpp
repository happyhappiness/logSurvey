 	stat_warn (file_name);
       else
 	stat_error (file_name);
-      report_difference (NULL);
+      report_difference (&current_stat_info, NULL);
       return 0;
     }
 
