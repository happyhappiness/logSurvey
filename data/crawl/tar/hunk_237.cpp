 	stat_warn (file_name);
       else
 	stat_error (file_name);
-      report_difference (0);
+      report_difference (NULL);
       return 0;
     }
 
