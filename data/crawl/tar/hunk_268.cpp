       {
 	off_t offset;
 
-	name_length = strlen (current_file_name) - 1;
-	if (current_file_name[name_length] == '/')
+	if (current_stat_info.had_trailing_slash)
 	  goto really_dir;
 
-	if (!get_stat_data (&stat_data))
+	if (!get_stat_data (current_stat_info.file_name, &stat_data))
 	  break;
 
 	if (!S_ISREG (stat_data.st_mode))
 	  {
-	    report_difference (_("Not a regular file"));
-	    skip_file ((long) current_stat.st_size);
+	    report_difference (_("File type differs"));
+	    skip_member ();
 	    break;
 	  }
 
-	stat_data.st_mode &= 07777;
-	offset = from_oct (1 + 12, current_header->oldgnu_header.offset);
-	if (stat_data.st_size != current_stat.st_size + offset)
+	offset = OFF_FROM_HEADER (current_header->oldgnu_header.offset);
+	if (stat_data.st_size != current_stat_info.stat.st_size + offset)
 	  {
 	    report_difference (_("Size differs"));
-	    skip_file ((long) current_stat.st_size);
+	    skip_member ();
 	    break;
 	  }
 
-	diff_handle = open (current_file_name, O_NDELAY | O_RDONLY | O_BINARY);
+	diff_handle = open (current_stat_info.file_name, O_RDONLY | O_BINARY);
 
 	if (diff_handle < 0)
 	  {
-	    WARN ((0, errno, _("Cannot open file %s"), current_file_name));
-	    report_difference (NULL);
-	    skip_file ((long) current_stat.st_size);
+	    open_error (current_stat_info.file_name);
+	    report_difference (0);
+	    skip_member ();
 	    break;
 	  }
 
-	status = lseek (diff_handle, offset, 0);
-	if (status != offset)
+	if (lseek (diff_handle, offset, SEEK_SET) < 0)
 	  {
-	    WARN ((0, errno, _("Cannot seek to %ld in file %s"),
-		   offset, current_file_name));
-	    report_difference (NULL);
+	    seek_error_details (current_stat_info.file_name, offset);
+	    report_difference (0);
 	    break;
 	  }
 
 	if (multi_volume_option)
 	  {
-	    assign_string (&save_name, current_file_name);
+	    assign_string (&save_name, current_stat_info.file_name);
 	    save_totsize = stat_data.st_size;
 	    /* save_sizeleft is set in read_and_process.  */
 	  }
 
-	read_and_process ((long) (current_stat.st_size), process_rawdata);
+	read_and_process (current_stat_info.stat.st_size, process_rawdata);
 
 	if (multi_volume_option)
-	  assign_string (&save_name, NULL);
+	  assign_string (&save_name, 0);
 
 	status = close (diff_handle);
-	if (status < 0)
-	  ERROR ((0, errno, _("Error while closing %s"), current_file_name));
+	if (status != 0)
+	  close_error (current_stat_info.file_name);
 
 	break;
       }
     }
 }
 
-/*---.
-| ?  |
-`---*/
-
 void
 verify_volume (void)
 {
