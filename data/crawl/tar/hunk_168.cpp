 	{
 	  report_difference (&current_stat_info, _("Size differs"));
 	  skip_member ();
-	  goto quit;
 	}
-
-      diff_handle = open (current_stat_info.file_name, O_RDONLY | O_BINARY);
-
-      if (diff_handle < 0)
-	{
-	  open_error (current_stat_info.file_name);
-	  skip_member ();
-	  report_difference (&current_stat_info, NULL);
-	  goto quit;
-	}
-
-      restore_times.actime = stat_data.st_atime;
-      restore_times.modtime = stat_data.st_mtime;
-
-      /* Need to treat sparse files completely differently here.  */
-
-      if (current_stat_info.is_sparse)
-	sparse_diff_file (diff_handle, &current_stat_info);
       else
 	{
-	  if (multi_volume_option)
+	  int fd = open (current_stat_info.file_name, O_RDONLY | O_BINARY);
+
+	  if (fd < 0)
 	    {
-	      assign_string (&save_name, current_stat_info.file_name);
-	      save_totsize = current_stat_info.stat.st_size;
-	      /* save_sizeleft is set in read_and_process.  */
+	      open_error (current_stat_info.file_name);
+	      skip_member ();
+	      report_difference (&current_stat_info, NULL);
+	    }
+	  else
+	    {
+	      int status;
+	      struct utimbuf restore_times;
+	      
+	      restore_times.actime = stat_data.st_atime;
+	      restore_times.modtime = stat_data.st_mtime;
+
+	      if (current_stat_info.is_sparse)
+		sparse_diff_file (diff_handle, &current_stat_info);
+	      else
+		{
+		  if (multi_volume_option)
+		    {
+		      assign_string (&save_name, current_stat_info.file_name);
+		      save_totsize = current_stat_info.stat.st_size;
+		      /* save_sizeleft is set in read_and_process.  */
+		    }
+
+		  read_and_process (current_stat_info.stat.st_size,
+				    process_rawdata);
+
+		  if (multi_volume_option)
+		    assign_string (&save_name, 0);
+		}
+
+	      status = close (fd);
+	      if (status != 0)
+		close_error (current_stat_info.file_name);
+
+	      if (atime_preserve_option)
+		utime (current_stat_info.file_name, &restore_times);
 	    }
-
-	  read_and_process (current_stat_info.stat.st_size, process_rawdata);
-
-	  if (multi_volume_option)
-	    assign_string (&save_name, 0);
 	}
+    }
+}
 
-      status = close (diff_handle);
-      if (status != 0)
-	close_error (current_stat_info.file_name);
-
-      if (atime_preserve_option)
-	utime (current_stat_info.file_name, &restore_times);
+static void
+diff_link ()
+{
+  struct stat file_data;
+  struct stat link_data;
+
+  if (get_stat_data (current_stat_info.file_name, &file_data)
+      && get_stat_data (current_stat_info.link_name, &link_data)
+      && !sys_compare_links (&file_data, &link_data))
+    report_difference (&current_stat_info,
+		       _("Not linked to %s"),
+		       quote (current_stat_info.link_name));
+}
 
-    quit:
-      break;
+#ifdef HAVE_READLINK
+static void
+diff_symlink ()
+{
+  size_t len = strlen (current_stat_info.link_name);
+  char *linkbuf = alloca (len + 1);
 
-    case LNKTYPE:
-      {
-	struct stat file_data;
-	struct stat link_data;
-
-	if (!get_stat_data (current_stat_info.file_name, &file_data))
-	  break;
-	if (!get_stat_data (current_stat_info.link_name, &link_data))
-	  break;
-	if (!sys_compare_links (&file_data, &link_data))
-	  report_difference (&current_stat_info,
-			     _("Not linked to %s"),
-			     quote (current_stat_info.link_name));
-      }
-      break;
+  int status = readlink (current_stat_info.file_name, linkbuf, len + 1);
 
-#ifdef HAVE_READLINK
-    case SYMTYPE:
-      {
-	size_t len = strlen (current_stat_info.link_name);
-	char *linkbuf = alloca (len + 1);
+  if (status < 0)
+    {
+      if (errno == ENOENT)
+	readlink_warn (current_stat_info.file_name);
+      else
+	readlink_error (current_stat_info.file_name);
+      report_difference (&current_stat_info, NULL);
+    }
+  else if (status != len
+	   || strncmp (current_stat_info.link_name, linkbuf, len) != 0)
+    report_difference (&current_stat_info, _("Symlink differs"));
+}
+#endif
 
-	status = readlink (current_stat_info.file_name, linkbuf, len + 1);
+static void
+diff_special ()
+{
+  struct stat stat_data;
 
-	if (status < 0)
-	  {
-	    if (errno == ENOENT)
-	      readlink_warn (current_stat_info.file_name);
-	    else
-	      readlink_error (current_stat_info.file_name);
-	    report_difference (&current_stat_info, NULL);
-	  }
-	else if (status != len
-		 || strncmp (current_stat_info.link_name, linkbuf, len) != 0)
-	  report_difference (&current_stat_info, _("Symlink differs"));
+  /* FIXME: deal with umask.  */
 
-	break;
-      }
-#endif
+  if (!get_stat_data (current_stat_info.file_name, &stat_data))
+    return;
 
-    case CHRTYPE:
-    case BLKTYPE:
-    case FIFOTYPE:
+  if (current_header->header.typeflag == CHRTYPE
+      ? !S_ISCHR (stat_data.st_mode)
+      : current_header->header.typeflag == BLKTYPE
+      ? !S_ISBLK (stat_data.st_mode)
+      : /* current_header->header.typeflag == FIFOTYPE */
+      !S_ISFIFO (stat_data.st_mode))
+    {
+      report_difference (&current_stat_info, _("File type differs"));
+      return;
+    }
 
-      /* FIXME: deal with umask.  */
+  if ((current_header->header.typeflag == CHRTYPE
+       || current_header->header.typeflag == BLKTYPE)
+      && current_stat_info.stat.st_rdev != stat_data.st_rdev)
+    {
+      report_difference (&current_stat_info, _("Device number differs"));
+      return;
+    }
 
-      if (!get_stat_data (current_stat_info.file_name, &stat_data))
-	break;
+  if ((current_stat_info.stat.st_mode & MODE_ALL) !=
+      (stat_data.st_mode & MODE_ALL))
+    report_difference (&current_stat_info, _("Mode differs"));
+}
 
-      if (current_header->header.typeflag == CHRTYPE
-	  ? !S_ISCHR (stat_data.st_mode)
-	  : current_header->header.typeflag == BLKTYPE
-	  ? !S_ISBLK (stat_data.st_mode)
-	  : /* current_header->header.typeflag == FIFOTYPE */
-	  !S_ISFIFO (stat_data.st_mode))
-	{
-	  report_difference (&current_stat_info, _("File type differs"));
-	  break;
-	}
+static void
+diff_dumpdir ()
+{
+  char *dumpdir_buffer = get_directory_contents (current_stat_info.file_name,
+						 0);
 
-      if ((current_header->header.typeflag == CHRTYPE
-	   || current_header->header.typeflag == BLKTYPE)
-	  && current_stat_info.stat.st_rdev != stat_data.st_rdev)
-	{
-	  report_difference (&current_stat_info, _("Device number differs"));
-	  break;
-	}
+  if (multi_volume_option)
+    {
+      assign_string (&save_name, current_stat_info.file_name);
+      save_totsize = current_stat_info.stat.st_size;
+      /* save_sizeleft is set in read_and_process.  */
+    }
 
-      if ((current_stat_info.stat.st_mode & MODE_ALL) != (stat_data.st_mode & MODE_ALL))
-	{
-	  report_difference (&current_stat_info, _("Mode differs"));
-	  break;
-	}
+  if (dumpdir_buffer)
+    {
+      dumpdir_cursor = dumpdir_buffer;
+      read_and_process (current_stat_info.stat.st_size, process_dumpdir);
+      free (dumpdir_buffer);
+    }
+  else
+    read_and_process (current_stat_info.stat.st_size, process_noop);
 
-      break;
+  if (multi_volume_option)
+    assign_string (&save_name, 0);
+}
 
-    case GNUTYPE_DUMPDIR:
-      {
-	char *dumpdir_buffer = get_directory_contents (current_stat_info.file_name, 0);
+static void
+diff_multivol ()
+{
+  struct stat stat_data;
+  int fd, status;
+  off_t offset;
 
-	if (multi_volume_option)
-	  {
-	    assign_string (&save_name, current_stat_info.file_name);
-	    save_totsize = current_stat_info.stat.st_size;
-	    /* save_sizeleft is set in read_and_process.  */
-	  }
+  if (current_stat_info.had_trailing_slash)
+    {
+      diff_dir ();
+      return;
+    }
+  
+  if (!get_stat_data (current_stat_info.file_name, &stat_data))
+    return;
 
-	if (dumpdir_buffer)
-	  {
-	    dumpdir_cursor = dumpdir_buffer;
-	    read_and_process (current_stat_info.stat.st_size, process_dumpdir);
-	    free (dumpdir_buffer);
-	  }
-	else
-	  read_and_process (current_stat_info.stat.st_size, process_noop);
+  if (!S_ISREG (stat_data.st_mode))
+    {
+      report_difference (&current_stat_info, _("File type differs"));
+      skip_member ();
+      return;
+    }
 
-	if (multi_volume_option)
-	  assign_string (&save_name, 0);
-	/* Fall through.  */
-      }
+  offset = OFF_FROM_HEADER (current_header->oldgnu_header.offset);
+  if (stat_data.st_size != current_stat_info.stat.st_size + offset)
+    {
+      report_difference (&current_stat_info, _("Size differs"));
+      skip_member ();
+      return;
+    }
 
-    case DIRTYPE:
-    really_dir:
-      if (!get_stat_data (current_stat_info.file_name, &stat_data))
-	break;
+  fd = open (current_stat_info.file_name, O_RDONLY | O_BINARY);
+  
+  if (fd < 0)
+    {
+      open_error (current_stat_info.file_name);
+      report_difference (&current_stat_info, NULL);
+      skip_member ();
+      return;
+    }
 
-      if (!S_ISDIR (stat_data.st_mode))
-	{
-	  report_difference (&current_stat_info, _("File type differs"));
-	  break;
-	}
+  if (lseek (fd, offset, SEEK_SET) < 0)
+    {
+      seek_error_details (current_stat_info.file_name, offset);
+      report_difference (&current_stat_info, NULL);
+      return;
+    }
 
-      if ((current_stat_info.stat.st_mode & MODE_ALL) != (stat_data.st_mode & MODE_ALL))
-	{
-	  report_difference (&current_stat_info, _("Mode differs"));
-	  break;
-	}
+  if (multi_volume_option)
+    {
+      assign_string (&save_name, current_stat_info.file_name);
+      save_totsize = stat_data.st_size;
+      /* save_sizeleft is set in read_and_process.  */
+    }
 
-      break;
+  read_and_process (current_stat_info.stat.st_size, process_rawdata);
 
-    case GNUTYPE_VOLHDR:
-      break;
+  if (multi_volume_option)
+    assign_string (&save_name, 0);
+  
+  status = close (fd);
+  if (status != 0)
+    close_error (current_stat_info.file_name);
+}
 
-    case GNUTYPE_MULTIVOL:
-      {
-	off_t offset;
+/* Diff a file against the archive.  */
+void
+diff_archive (void)
+{
 
-	if (current_stat_info.had_trailing_slash)
-	  goto really_dir;
+  set_next_block_after (current_header);
+  decode_header (current_header, &current_stat_info, &current_format, 1);
 
-	if (!get_stat_data (current_stat_info.file_name, &stat_data))
-	  break;
+  /* Print the block from current_header and current_stat_info.  */
 
-	if (!S_ISREG (stat_data.st_mode))
-	  {
-	    report_difference (&current_stat_info, _("File type differs"));
-	    skip_member ();
-	    break;
-	  }
+  if (verbose_option)
+    {
+      if (now_verifying)
+	fprintf (stdlis, _("Verify "));
+      print_header (&current_stat_info, -1);
+    }
 
-	offset = OFF_FROM_HEADER (current_header->oldgnu_header.offset);
-	if (stat_data.st_size != current_stat_info.stat.st_size + offset)
-	  {
-	    report_difference (&current_stat_info, _("Size differs"));
-	    skip_member ();
-	    break;
-	  }
+  switch (current_header->header.typeflag)
+    {
+    default:
+      ERROR ((0, 0, _("%s: Unknown file type '%c', diffed as normal file"),
+	      quotearg_colon (current_stat_info.file_name),
+	      current_header->header.typeflag));
+      /* Fall through.  */
 
-	diff_handle = open (current_stat_info.file_name, O_RDONLY | O_BINARY);
+    case AREGTYPE:
+    case REGTYPE:
+    case GNUTYPE_SPARSE:
+    case CONTTYPE:
 
-	if (diff_handle < 0)
-	  {
-	    open_error (current_stat_info.file_name);
-	    report_difference (&current_stat_info, NULL);
-	    skip_member ();
-	    break;
-	  }
+      /* Appears to be a file.  See if it's really a directory.  */
 
-	if (lseek (diff_handle, offset, SEEK_SET) < 0)
-	  {
-	    seek_error_details (current_stat_info.file_name, offset);
-	    report_difference (&current_stat_info, NULL);
-	    break;
-	  }
+      if (current_stat_info.had_trailing_slash)
+	diff_dir ();
+      else
+	diff_file ();
+      break;
 
-	if (multi_volume_option)
-	  {
-	    assign_string (&save_name, current_stat_info.file_name);
-	    save_totsize = stat_data.st_size;
-	    /* save_sizeleft is set in read_and_process.  */
-	  }
+    case LNKTYPE:
+      diff_link ();
+      break;
 
-	read_and_process (current_stat_info.stat.st_size, process_rawdata);
+#ifdef HAVE_READLINK
+    case SYMTYPE:
+      diff_symlink ();
+      break;
+#endif
+      
+    case CHRTYPE:
+    case BLKTYPE:
+    case FIFOTYPE:
+      diff_special ();
+      break;
 
-	if (multi_volume_option)
-	  assign_string (&save_name, 0);
+    case GNUTYPE_DUMPDIR:
+      diff_dumpdir ();
+      /* Fall through.  */
+      
+    case DIRTYPE:
+      diff_dir ();
+      break;
 
-	status = close (diff_handle);
-	if (status != 0)
-	  close_error (current_stat_info.file_name);
+    case GNUTYPE_VOLHDR:
+      break;
 
-	break;
-      }
+    case GNUTYPE_MULTIVOL:
+      diff_multivol ();
     }
 }
 
