 
       /* Appears to be a file.  See if it's really a directory.  */
 
-      name_length = strlen (current_file_name) - 1;
-      if (current_file_name[name_length] == '/')
+      if (current_stat_info.had_trailing_slash)
 	goto really_dir;
 
-      if (!get_stat_data (&stat_data))
+      if (!get_stat_data (current_stat_info.file_name, &stat_data))
 	{
-	  if (current_header->oldgnu_header.isextended)
-	    skip_extended_headers ();
-	  skip_file ((long) current_stat.st_size);
+	  skip_member ();
 	  goto quit;
 	}
 
       if (!S_ISREG (stat_data.st_mode))
 	{
-	  report_difference (_("Not a regular file"));
-	  skip_file ((long) current_stat.st_size);
+	  report_difference (_("File type differs"));
+	  skip_member ();
 	  goto quit;
 	}
 
-      stat_data.st_mode &= 07777;
-      if (stat_data.st_mode != current_stat.st_mode)
+      if ((current_stat_info.stat.st_mode & MODE_ALL) != (stat_data.st_mode & MODE_ALL))
 	report_difference (_("Mode differs"));
 
 #if !MSDOS
       /* stat() in djgpp's C library gives a constant number of 42 as the
 	 uid and gid of a file.  So, comparing an FTP'ed archive just after
 	 unpack would fail on MSDOS.  */
-      if (stat_data.st_uid != current_stat.st_uid)
+      if (stat_data.st_uid != current_stat_info.stat.st_uid)
 	report_difference (_("Uid differs"));
-      if (stat_data.st_gid != current_stat.st_gid)
+      if (stat_data.st_gid != current_stat_info.stat.st_gid)
 	report_difference (_("Gid differs"));
 #endif
 
-      if (stat_data.st_mtime != current_stat.st_mtime)
+      if (stat_data.st_mtime != current_stat_info.stat.st_mtime)
 	report_difference (_("Mod time differs"));
       if (current_header->header.typeflag != GNUTYPE_SPARSE &&
-	  stat_data.st_size != current_stat.st_size)
+	  stat_data.st_size != current_stat_info.stat.st_size)
 	{
 	  report_difference (_("Size differs"));
-	  skip_file ((long) current_stat.st_size);
+	  skip_member ();
 	  goto quit;
 	}
 
-      diff_handle = open (current_file_name, O_NDELAY | O_RDONLY | O_BINARY);
+      diff_handle = open (current_stat_info.file_name, O_RDONLY | O_BINARY);
 
-      if (diff_handle < 0 && !absolute_names_option)
-	{
-	  char *tmpbuf = xmalloc (strlen (current_file_name) + 2);
-
-	  *tmpbuf = '/';
-	  strcpy (tmpbuf + 1, current_file_name);
-	  diff_handle = open (tmpbuf, O_NDELAY | O_RDONLY);
-	  free (tmpbuf);
-	}
       if (diff_handle < 0)
 	{
-	  ERROR ((0, errno, _("Cannot open %s"), current_file_name));
-	  if (current_header->oldgnu_header.isextended)
-	    skip_extended_headers ();
-	  skip_file ((long) current_stat.st_size);
-	  report_difference (NULL);
+	  open_error (current_stat_info.file_name);
+	  skip_member ();
+	  report_difference (0);
 	  goto quit;
 	}
 
+      restore_times.actime = stat_data.st_atime;
+      restore_times.modtime = stat_data.st_mtime;
+
       /* Need to treat sparse files completely differently here.  */
 
       if (current_header->header.typeflag == GNUTYPE_SPARSE)
-	diff_sparse_files (current_stat.st_size);
+	diff_sparse_files ();
       else
 	{
 	  if (multi_volume_option)
 	    {
-	      assign_string (&save_name, current_file_name);
-	      save_totsize = current_stat.st_size;
+	      assign_string (&save_name, current_stat_info.file_name);
+	      save_totsize = current_stat_info.stat.st_size;
 	      /* save_sizeleft is set in read_and_process.  */
 	    }
 
-	  read_and_process ((long) (current_stat.st_size), process_rawdata);
+	  read_and_process (current_stat_info.stat.st_size, process_rawdata);
 
 	  if (multi_volume_option)
-	    assign_string (&save_name, NULL);
+	    assign_string (&save_name, 0);
 	}
 
       status = close (diff_handle);
-      if (status < 0)
-	ERROR ((0, errno, _("Error while closing %s"), current_file_name));
+      if (status != 0)
+	close_error (current_stat_info.file_name);
+
+      if (atime_preserve_option)
+	utime (current_stat_info.file_name, &restore_times);
 
     quit:
       break;
