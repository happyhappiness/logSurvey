 	if (lseek (diff_handle, offset, SEEK_SET) < 0)
 	  {
 	    seek_error_details (current_stat_info.file_name, offset);
-	    report_difference (NULL);
+	    report_difference (&current_stat_info, NULL);
 	    break;
 	  }
 
