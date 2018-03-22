 	{
 	  open_error (current_stat_info.file_name);
 	  skip_member ();
-	  report_difference (NULL);
+	  report_difference (&current_stat_info, NULL);
 	  goto quit;
 	}
 
