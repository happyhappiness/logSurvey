 	 suffix means a directory.  */
 
       if (current_stat_info.had_trailing_slash)
-	goto really_dir;
-
-      /* FIXME: deal with protection issues.  */
-
-    again_file:
-      openflag = (O_WRONLY | O_BINARY | O_CREAT
-		  | (old_files_option == OVERWRITE_OLD_FILES
-		     ? O_TRUNC
-		     : O_EXCL));
-      mode = current_stat_info.stat.st_mode & MODE_RWX & ~ current_umask;
-
-      if (to_stdout_option)
-	{
-	  fd = STDOUT_FILENO;
-	  goto extract_file;
-	}
-
-      if (! prepare_to_extract (file_name))
-	{
-	  skip_member ();
-	  if (backup_option)
-	    undo_last_backup ();
-	  break;
-	}
-
-#if O_CTG
-      /* Contiguous files (on the Masscomp) have to specify the size in
-	 the open call that creates them.  */
-
-      if (typeflag == CONTTYPE)
-	fd = open (file_name, openflag | O_CTG, mode, current_stat_info.stat.st_size);
+	extract_dir (file_name, typeflag);
       else
-	fd = open (file_name, openflag, mode);
-
-#else /* not O_CTG */
-      if (typeflag == CONTTYPE)
-	{
-	  static int conttype_diagnosed;
-
-	  if (!conttype_diagnosed)
-	    {
-	      conttype_diagnosed = 1;
-	      WARN ((0, 0, _("Extracting contiguous files as regular files")));
-	    }
-	}
-      fd = open (file_name, openflag, mode);
-
-#endif /* not O_CTG */
-
-      if (fd < 0)
-	{
-	  if (maybe_recoverable (file_name, &interdir_made))
-	    goto again_file;
-
-	  open_error (file_name);
-	  skip_member ();
-	  if (backup_option)
-	    undo_last_backup ();
-	  break;
-	}
-
-    extract_file:
-      if (current_stat_info.is_sparse)
-	{
-	  sparse_extract_file (fd, &current_stat_info, &size);
-	}
-      else
-	for (size = current_stat_info.stat.st_size; size > 0; )
-	  {
-	    if (multi_volume_option)
-	      {
-		assign_string (&save_name, current_stat_info.file_name);
-		save_totsize = current_stat_info.stat.st_size;
-		save_sizeleft = size;
-	      }
-
-	    /* Locate data, determine max length writeable, write it,
-	       block that we have used the data, then check if the write
-	       worked.  */
-
-	    data_block = find_next_block ();
-	    if (! data_block)
-	      {
-		ERROR ((0, 0, _("Unexpected EOF in archive")));
-		break;		/* FIXME: What happens, then?  */
-	      }
-
-	    written = available_space_after (data_block);
-
-	    if (written > size)
-	      written = size;
-	    errno = 0;
-	    count = full_write (fd, data_block->buffer, written);
-	    size -= count;
-
-	    set_next_block_after ((union block *)
-				  (data_block->buffer + written - 1));
-	    if (count != written)
-	      {
-		write_error_details (file_name, count, written);
-		break;
-	      }
-	  }
-
-      skip_file (size);
-
-      if (multi_volume_option)
-	assign_string (&save_name, 0);
-
-      /* If writing to stdout, don't try to do anything to the filename;
-	 it doesn't exist, or we don't want to touch it anyway.  */
-
-      if (to_stdout_option)
-	break;
-
-      status = close (fd);
-      if (status < 0)
-	{
-	  close_error (file_name);
-	  if (backup_option)
-	    undo_last_backup ();
-	}
-
-      set_stat (file_name, &current_stat_info.stat, 0, 0,
-		(old_files_option == OVERWRITE_OLD_FILES
-		 ? UNKNOWN_PERMSTATUS
-		 : ARCHIVED_PERMSTATUS),
-		typeflag);
+	extract_file (file_name, typeflag);
       break;
 
     case SYMTYPE:
-#ifdef HAVE_SYMLINK
-      if (! prepare_to_extract (file_name))
-	break;
-
-      if (absolute_names_option
-	  || ! (IS_ABSOLUTE_FILE_NAME (current_stat_info.link_name)
-		|| contains_dot_dot (current_stat_info.link_name)))
-	{
-	  while (status = symlink (current_stat_info.link_name, file_name),
-		 status != 0)
-	    if (!maybe_recoverable (file_name, &interdir_made))
-	      break;
-
-	  if (status == 0)
-	    set_stat (file_name, &current_stat_info.stat, 0, 0, 0, SYMTYPE);
-	  else
-	    symlink_error (current_stat_info.link_name, file_name);
-	}
-      else
-	{
-	  /* This symbolic link is potentially dangerous.  Don't
-	     create it now; instead, create a placeholder file, which
-	     will be replaced after other extraction is done.  */
-	  struct stat st;
-
-	  while (fd = open (file_name, O_WRONLY | O_CREAT | O_EXCL, 0),
-		 fd < 0)
-	    if (! maybe_recoverable (file_name, &interdir_made))
-	      break;
-
-	  status = -1;
-	  if (fd < 0)
-	    open_error (file_name);
-	  else if (fstat (fd, &st) != 0)
-	    {
-	      stat_error (file_name);
-	      close (fd);
-	    }
-	  else if (close (fd) != 0)
-	    close_error (file_name);
-	  else
-	    {
-	      struct delayed_set_stat *h;
-	      struct delayed_symlink *p =
-		xmalloc (offsetof (struct delayed_symlink, target)
-			 + strlen (current_stat_info.link_name) + 1);
-	      p->next = delayed_symlink_head;
-	      delayed_symlink_head = p;
-	      p->dev = st.st_dev;
-	      p->ino = st.st_ino;
-	      p->mtime = st.st_mtime;
-	      p->uid = current_stat_info.stat.st_uid;
-	      p->gid = current_stat_info.stat.st_gid;
-	      p->sources = xmalloc (offsetof (struct string_list, string)
-				    + strlen (file_name) + 1);
-	      p->sources->next = 0;
-	      strcpy (p->sources->string, file_name);
-	      strcpy (p->target, current_stat_info.link_name);
-
-	      h = delayed_set_stat_head;
-	      if (h && ! h->after_symlinks
-		  && strncmp (file_name, h->file_name, h->file_name_len) == 0
-		  && ISSLASH (file_name[h->file_name_len])
-		  && (base_name (file_name)
-		      == file_name + h->file_name_len + 1))
-		{
-		  do
-		    {
-		      h->after_symlinks = 1;
-
-		      if (stat (h->file_name, &st) != 0)
-			stat_error (h->file_name);
-		      else
-			{
-			  h->stat_info.st_dev = st.st_dev;
-			  h->stat_info.st_ino = st.st_ino;
-			}
-		    }
-		  while ((h = h->next) && ! h->after_symlinks);
-		}
-
-	      status = 0;
-	    }
-	}
-
-      if (status != 0 && backup_option)
-	undo_last_backup ();
+      extract_symlink (file_name);
       break;
-
-#else
-      {
-	static int warned_once;
-
-	if (!warned_once)
-	  {
-	    warned_once = 1;
-	    WARN ((0, 0,
-		   _("Attempting extraction of symbolic links as hard links")));
-	  }
-      }
-      typeflag = LNKTYPE;
-      /* Fall through.  */
-#endif
-
+      
     case LNKTYPE:
-      if (! prepare_to_extract (file_name))
-	break;
-
-    again_link:
-      {
-	char const *link_name = safer_name_suffix (current_stat_info.link_name,
-	                                           true);
-	struct stat st1, st2;
-	int e;
-
-	/* MSDOS does not implement links.  However, djgpp's link() actually
-	   copies the file.  */
-	status = link (link_name, file_name);
-	e = errno;
-
-	if (status == 0)
-	  {
-	    struct delayed_symlink *ds = delayed_symlink_head;
-	    if (ds && lstat (link_name, &st1) == 0)
-	      for (; ds; ds = ds->next)
-		if (ds->dev == st1.st_dev
-		    && ds->ino == st1.st_ino
-		    && ds->mtime == st1.st_mtime)
-		  {
-		    struct string_list *p =
-		      xmalloc (offsetof (struct string_list, string)
-			       + strlen (file_name) + 1);
-		    strcpy (p->string, file_name);
-		    p->next = ds->sources;
-		    ds->sources = p;
-		    break;
-		  }
-	    break;
-	  }
-
-	if ((e == EEXIST && strcmp (link_name, file_name) == 0)
-	    || (lstat (link_name, &st1) == 0
-		&& lstat (file_name, &st2) == 0
-		&& st1.st_dev == st2.st_dev
-		&& st1.st_ino == st2.st_ino))
-	  break;
-
-	errno = e;
-	if (maybe_recoverable (file_name, &interdir_made))
-	  goto again_link;
-
-	if (incremental_option && errno == EEXIST)
-	  break;
-
-	link_error (link_name, file_name);
-	if (backup_option)
-	  undo_last_backup ();
-      }
+      extract_link (file_name);
       break;
 
 #if S_IFCHR
     case CHRTYPE:
       current_stat_info.stat.st_mode |= S_IFCHR;
-      goto make_node;
+      extract_node (file_name, typeflag);
+      break;
 #endif
 
 #if S_IFBLK
     case BLKTYPE:
       current_stat_info.stat.st_mode |= S_IFBLK;
-#endif
-
-#if S_IFCHR || S_IFBLK
-    make_node:
-      if (! prepare_to_extract (file_name))
-	break;
-
-      status = mknod (file_name, current_stat_info.stat.st_mode,
-		      current_stat_info.stat.st_rdev);
-      if (status != 0)
-	{
-	  if (maybe_recoverable (file_name, &interdir_made))
-	    goto make_node;
-	  mknod_error (file_name);
-	  if (backup_option)
-	    undo_last_backup ();
-	  break;
-	};
-      set_stat (file_name, &current_stat_info.stat, 0, 0,
-		ARCHIVED_PERMSTATUS, typeflag);
+      extract_node (file_name, typeflag);
       break;
 #endif
 
 #if HAVE_MKFIFO || defined mkfifo
     case FIFOTYPE:
-      if (! prepare_to_extract (file_name))
-	break;
-
-      while (status = mkfifo (file_name, current_stat_info.stat.st_mode),
-	     status != 0)
-	if (!maybe_recoverable (file_name, &interdir_made))
-	  break;
-
-      if (status == 0)
-	set_stat (file_name, &current_stat_info.stat, NULL, 0,
-		  ARCHIVED_PERMSTATUS, typeflag);
-      else
-	{
-	  mkfifo_error (file_name);
-	  if (backup_option)
-	    undo_last_backup ();
-	}
+      extract_fifo (file_name, typeflag);
       break;
 #endif
 
     case DIRTYPE:
     case GNUTYPE_DUMPDIR:
-    really_dir:
-      if (incremental_option)
-	{
-	  /* Read the entry and delete files that aren't listed in the
-	     archive.  */
-
-	  purge_directory (file_name);
-	}
-      else if (typeflag == GNUTYPE_DUMPDIR)
-	skip_member ();
-
-      mode = ((current_stat_info.stat.st_mode
-	       | (we_are_root ? 0 : MODE_WXUSR))
-	      & MODE_RWX);
-
-      status = prepare_to_extract (file_name);
-      if (status == 0)
-	break;
-      if (status < 0)
-	goto directory_exists;
-
-    again_dir:
-      status = mkdir (file_name, mode);
-
-      if (status != 0)
-	{
-	  if (errno == EEXIST
-	      && (interdir_made
-		  || old_files_option == DEFAULT_OLD_FILES
-		  || old_files_option == OVERWRITE_OLD_FILES))
-	    {
-	      struct stat st;
-	      if (stat (file_name, &st) == 0)
-		{
-		  if (interdir_made)
-		    {
-		      repair_delayed_set_stat (file_name, &st);
-		      break;
-		    }
-		  if (S_ISDIR (st.st_mode))
-		    {
-		      mode = st.st_mode & ~ current_umask;
-		      goto directory_exists;
-		    }
-		}
-	      errno = EEXIST;
-	    }
-
-	  if (maybe_recoverable (file_name, &interdir_made))
-	    goto again_dir;
-
-	  if (errno != EEXIST)
-	    {
-	      mkdir_error (file_name);
-	      if (backup_option)
-		undo_last_backup ();
-	      break;
-	    }
-	}
-
-    directory_exists:
-      if (status == 0
-	  || old_files_option == DEFAULT_OLD_FILES
-	  || old_files_option == OVERWRITE_OLD_FILES)
-	delay_set_stat (file_name, &current_stat_info.stat,
-			MODE_RWX & (mode ^ current_stat_info.stat.st_mode),
-			(status == 0
-			 ? ARCHIVED_PERMSTATUS
-			 : UNKNOWN_PERMSTATUS));
+      extract_dir (file_name, typeflag);
       break;
 
     case GNUTYPE_VOLHDR: