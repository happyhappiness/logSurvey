 
     case GNUTYPE_DUMPDIR:
       {
-	char *dumpdir_buffer = get_directory_contents (current_file_name, 0);
+	char *dumpdir_buffer = get_directory_contents (current_stat_info.file_name, 0);
 
 	if (multi_volume_option)
 	  {
-	    assign_string (&save_name, current_file_name);
-	    save_totsize = current_stat.st_size;
+	    assign_string (&save_name, current_stat_info.file_name);
+	    save_totsize = current_stat_info.stat.st_size;
 	    /* save_sizeleft is set in read_and_process.  */
 	  }
 
 	if (dumpdir_buffer)
 	  {
 	    dumpdir_cursor = dumpdir_buffer;
-	    read_and_process ((long) (current_stat.st_size), process_dumpdir);
+	    read_and_process (current_stat_info.stat.st_size, process_dumpdir);
 	    free (dumpdir_buffer);
 	  }
 	else
-	  read_and_process ((long) (current_stat.st_size), process_noop);
+	  read_and_process (current_stat_info.stat.st_size, process_noop);
 
 	if (multi_volume_option)
-	  assign_string (&save_name, NULL);
+	  assign_string (&save_name, 0);
 	/* Fall through.  */
       }
 
     case DIRTYPE:
-      /* Check for trailing /.  */
-
-      name_length = strlen (current_file_name) - 1;
-
     really_dir:
-      while (name_length && current_file_name[name_length] == '/')
-	current_file_name[name_length--] = '\0';	/* zap / */
-
-      if (!get_stat_data (&stat_data))
+      if (!get_stat_data (current_stat_info.file_name, &stat_data))
 	break;
 
       if (!S_ISDIR (stat_data.st_mode))
 	{
-	  report_difference (_("No longer a directory"));
+	  report_difference (_("File type differs"));
+	  break;
+	}
+
+      if ((current_stat_info.stat.st_mode & MODE_ALL) != (stat_data.st_mode & MODE_ALL))
+	{
+	  report_difference (_("Mode differs"));
 	  break;
 	}
 
-      if ((stat_data.st_mode & 07777) != (current_stat.st_mode & 07777))
-	report_difference (_("Mode differs"));
       break;
 
     case GNUTYPE_VOLHDR:
