 	{
 	  open_error (current_stat_info.file_name);
 	  skip_member ();
-	  report_difference (0);
+	  report_difference (NULL);
 	  goto quit;
 	}
 
