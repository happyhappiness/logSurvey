       if (! prepare_to_extract (CURRENT_FILE_NAME))
 	break;
 
-      while (status = symlink (current_link_name, CURRENT_FILE_NAME),
-	     status != 0)
-	if (!maybe_recoverable (CURRENT_FILE_NAME, &interdir_made))
-	  break;
-
-      if (status == 0)
-
-	/* Setting the attributes of symbolic links might, on some systems,
-	   change the pointed to file, instead of the symbolic link itself.
-	   At least some of these systems have a lchown call, and the
-	   set_stat routine knows about this.    */
-
-	set_stat (CURRENT_FILE_NAME, &current_stat, 0,
-		  ARCHIVED_PERMSTATUS, typeflag);
+      if (absolute_names_option
+	  || (current_link_name[0] != '/'
+	      && ! contains_dot_dot (current_link_name)))
+	{
+	  while (status = symlink (current_link_name, CURRENT_FILE_NAME),
+		 status != 0)
+	    if (!maybe_recoverable (CURRENT_FILE_NAME, &interdir_made))
+	      break;
 
+	  if (status == 0)
+	    set_stat (CURRENT_FILE_NAME, &current_stat, 0, 0, SYMTYPE);
+	  else
+	    symlink_error (current_link_name, CURRENT_FILE_NAME);
+	}
       else
 	{
-	  int e = errno;
-	  ERROR ((0, e, _("%s: Cannot create symlink to %s"),
-		  quotearg_colon (CURRENT_FILE_NAME),
-		  quote (current_link_name)));
-	  if (backup_option)
-	    undo_last_backup ();
+	  /* This symbolic link is potentially dangerous.  Don't
+	     create it now; instead, create a placeholder file, which
+	     will be replaced after other extraction is done.  */
+	  struct stat st;
+
+	  while (fd = open (CURRENT_FILE_NAME, O_WRONLY | O_CREAT | O_EXCL, 0),
+		 fd < 0)
+	    if (! maybe_recoverable (CURRENT_FILE_NAME, &interdir_made))
+	      break;
+
+	  status = -1;
+	  if (fd < 0)
+	    open_error (CURRENT_FILE_NAME);
+	  else if (fstat (fd, &st) != 0)
+	    {
+	      stat_error (CURRENT_FILE_NAME);
+	      close (fd);
+	    }
+	  else if (close (fd) != 0)
+	    close_error (CURRENT_FILE_NAME);
+	  else
+	    {
+	      size_t filelen = strlen (CURRENT_FILE_NAME);
+	      size_t linklen = strlen (current_link_name);
+	      struct delayed_symlink *p =
+		xmalloc (sizeof *p + filelen + linklen + 1);
+	      p->next = delayed_symlink_head;
+	      delayed_symlink_head = p;
+	      p->dev = st.st_dev;
+	      p->ino = st.st_ino;
+	      p->mtime = st.st_mtime;
+	      p->uid = current_stat.st_uid;
+	      p->gid = current_stat.st_gid;
+	      memcpy (p->names, CURRENT_FILE_NAME, filelen + 1);
+	      memcpy (p->names + filelen + 1, current_link_name, linklen + 1);
+	      status = 0;
+	    }
 	}
+  
+      if (status != 0 && backup_option)
+	undo_last_backup ();
       break;
 
 #else
