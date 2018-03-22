       else if (typeflag == GNUTYPE_DUMPDIR)
 	skip_file (current_stat.st_size);
 
-      if (to_stdout_option)
+      if (! prepare_to_extract (CURRENT_FILE_NAME))
 	break;
 
+      mode = ((current_stat.st_mode
+	       | (we_are_root ? 0 : MODE_WXUSR))
+	      & MODE_RWX);
+
     again_dir:
-      status = mkdir (CURRENT_FILE_NAME,
-		      ((we_are_root ? 0 : MODE_WXUSR)
-		       | current_stat.st_mode));
+      status = mkdir (CURRENT_FILE_NAME, mode);
       if (status != 0)
 	{
-	  /* If the directory creation fails, let's consider immediately the
-	     case where the directory already exists.  We have three good
-	     reasons for clearing out this case before attempting recovery.
-
-	     1) It would not be efficient recovering the error by deleting
-	     the directory in maybe_recoverable, then recreating it right
-	     away.  We only hope we will be able to adjust its permissions
-	     adequately, later.
-
-	     2) Removing the directory might fail if it is not empty.  By
-	     exception, this real error is traditionally not reported.
-
-	     3) Let's suppose `DIR' already exists and we are about to
-	     extract `DIR/../DIR'.  This would fail because the directory
-	     already exists, and maybe_recoverable would react by removing
-	     `DIR'.  This then would fail again because there are missing
-	     intermediate directories, and maybe_recoverable would react by
-	     creating `DIR'.  We would then have an extraction loop.  */
-
-	  if (errno == EEXIST)
+	  if (errno == EEXIST && interdir_made
+	      && contains_dot_dot (CURRENT_FILE_NAME))
 	    {
-	      struct stat st1;
-	      int saved_errno = errno;
-
-	      if (stat (CURRENT_FILE_NAME, &st1) == 0 && S_ISDIR (st1.st_mode))
-		goto check_perms;
-
-	      errno = saved_errno;
+	      int e = errno;
+	      struct stat st;
+	      if (stat (CURRENT_FILE_NAME, &st) == 0)
+		{
+		  repair_delayed_set_stat (CURRENT_FILE_NAME, &st);
+		  break;
+		}
+	      e = errno;
 	    }
-
-	  if (maybe_recoverable (CURRENT_FILE_NAME))
+	
+	  if (maybe_recoverable (CURRENT_FILE_NAME, &interdir_made))
 	    goto again_dir;
 
-	  /* If we're trying to create '.', let it be.  */
-
-	  /* FIXME: Strange style...  */
-
-	  if (CURRENT_FILE_NAME[name_length] == '.'
-	      && (name_length == 0
-		  || CURRENT_FILE_NAME[name_length - 1] == '/'))
-	    goto check_perms;
-
-	  ERROR ((0, errno, _("%s: Could not create directory"),
-		  CURRENT_FILE_NAME));
-	  if (backup_option)
-	    undo_last_backup ();
-	  break;
-	}
-
-    check_perms:
-      if (!we_are_root && MODE_WXUSR != (MODE_WXUSR & current_stat.st_mode))
-	{
-	  current_stat.st_mode |= MODE_WXUSR;
-	  WARN ((0, 0, _("Added write and execute permission to directory %s"),
-		 CURRENT_FILE_NAME));
+	  if (errno != EEXIST || old_files_option == KEEP_OLD_FILES)
+	    {
+	      int e = errno;
+	      ERROR ((0, e, "%s: mkdir", quotearg_colon (CURRENT_FILE_NAME)));
+	      if (backup_option)
+		undo_last_backup ();
+	      break;
+	    }
 	}
 
-#if !MSDOS
-      /* MSDOS does not associate time stamps with directories.   In this
-	 case, no need to try delaying their restoration.  */
-
-      if (touch_option)
-
-	/* FIXME: I do not believe in this.  Ignoring time stamps does not
-	   alleviate the need of delaying the restoration of directories'
-	   mode.  Let's ponder this for a little while.  */
-
-	set_mode (CURRENT_FILE_NAME, &current_stat);
-
-      else
-	{
-	  data = xmalloc (sizeof (struct delayed_set_stat));
-	  data->file_name = xstrdup (CURRENT_FILE_NAME);
-	  data->stat_info = current_stat;
-	  data->next = delayed_set_stat_head;
-	  delayed_set_stat_head = data;
-	}
-#endif /* !MSDOS */
+      if (status == 0
+	  || old_files_option == OVERWRITE_OLD_FILES)
+	delay_set_stat (CURRENT_FILE_NAME, &current_stat,
+			mode & ~ current_stat.st_mode,
+			(status == 0
+			 ? ARCHIVED_PERMSTATUS
+			 : UNKNOWN_PERMSTATUS));
       break;
 
     case GNUTYPE_VOLHDR:
       if (verbose_option)
-	fprintf (stdlis, _("Reading %s\n"), current_file_name);
+	fprintf (stdlis, _("Reading %s\n"), quote (current_file_name));
       break;
 
     case GNUTYPE_NAMES:
