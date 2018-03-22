     }
 }
 
-/* Extract a file from the archive.  */
+
 void
-extract_archive (void)
+extract_dir (char *file_name, int typeflag)
+{
+  int status;
+  mode_t mode;
+  int interdir_made = 0;
+  
+  if (incremental_option)
+    /* Read the entry and delete files that aren't listed in the archive.  */
+    purge_directory (file_name);
+  else if (typeflag == GNUTYPE_DUMPDIR)
+    skip_member ();
+
+  mode = (current_stat_info.stat.st_mode | (we_are_root ? 0 : MODE_WXUSR)) & MODE_RWX;
+
+  status = prepare_to_extract (file_name);
+  if (status == 0)
+    return;
+  
+  if (status > 0)
+    while ((status = mkdir (file_name, mode)))
+      {
+	if (errno == EEXIST
+	    && (interdir_made
+		|| old_files_option == DEFAULT_OLD_FILES
+		|| old_files_option == OVERWRITE_OLD_FILES))
+	  {
+	    struct stat st;
+	    if (stat (file_name, &st) == 0)
+	      {
+		if (interdir_made)
+		  {
+		    repair_delayed_set_stat (file_name, &st);
+		    return;
+		  }
+		if (S_ISDIR (st.st_mode))
+		  {
+		    mode = st.st_mode & ~ current_umask;
+		    break;
+		  }
+	      }
+	    errno = EEXIST;
+	  }
+	
+	if (maybe_recoverable (file_name, &interdir_made))
+	  continue;
+
+	if (errno != EEXIST)
+	  {
+	    mkdir_error (file_name);
+	    if (backup_option)
+	    undo_last_backup ();
+	    return;
+	  }
+	break;
+      }
+
+  if (status == 0
+      || old_files_option == DEFAULT_OLD_FILES
+      || old_files_option == OVERWRITE_OLD_FILES)
+    delay_set_stat (file_name, &current_stat_info.stat,
+		    MODE_RWX & (mode ^ current_stat_info.stat.st_mode),
+		    (status == 0
+		     ? ARCHIVED_PERMSTATUS
+		     : UNKNOWN_PERMSTATUS));
+}
+
+
+static int
+open_output_file (char *file_name, int typeflag)
 {
-  union block *data_block;
   int fd;
+  int openflag = (O_WRONLY | O_BINARY | O_CREAT
+		  | (old_files_option == OVERWRITE_OLD_FILES
+		     ? O_TRUNC
+		     : O_EXCL));
+  mode_t mode = current_stat_info.stat.st_mode & MODE_RWX & ~ current_umask;
+
+#if O_CTG
+  /* Contiguous files (on the Masscomp) have to specify the size in
+     the open call that creates them.  */
+
+  if (typeflag == CONTTYPE)
+    fd = open (file_name, openflag | O_CTG, mode, current_stat_info.stat.st_size);
+  else
+    fd = open (file_name, openflag, mode);
+
+#else /* not O_CTG */
+  if (typeflag == CONTTYPE)
+    {
+      static int conttype_diagnosed;
+
+      if (!conttype_diagnosed)
+	{
+	  conttype_diagnosed = 1;
+	  WARN ((0, 0, _("Extracting contiguous files as regular files")));
+	}
+    }
+  fd = open (file_name, openflag, mode);
+
+#endif /* not O_CTG */
+  
+  return fd;
+}
+
+static void
+extract_file (char *file_name, int typeflag)
+{
+  int fd;
+  off_t size;
+  union block *data_block;
   int status;
   size_t count;
   size_t written;
-  int openflag;
-  mode_t mode;
-  off_t size;
   int interdir_made = 0;
+  
+  /* FIXME: deal with protection issues.  */
+
+  do
+    {
+      if (to_stdout_option)
+	fd = STDOUT_FILENO;
+      else
+	{
+	  if (! prepare_to_extract (file_name))
+	    {
+	      skip_member ();
+	      if (backup_option)
+		undo_last_backup ();
+	      return;
+	    }
+	  fd = open_output_file (file_name, typeflag);
+	}
+    }
+  while (fd < 0 && maybe_recoverable (file_name, &interdir_made));
+    
+  if (fd < 0)
+    {
+      open_error (file_name);
+      skip_member ();
+      if (backup_option)
+	undo_last_backup ();
+      return;
+    }
+    
+  if (current_stat_info.is_sparse)
+    sparse_extract_file (fd, &current_stat_info, &size);
+  else
+    for (size = current_stat_info.stat.st_size; size > 0; )
+      {
+	if (multi_volume_option)
+	  {
+	    assign_string (&save_name, current_stat_info.file_name);
+	    save_totsize = current_stat_info.stat.st_size;
+	    save_sizeleft = size;
+	  }
+
+	/* Locate data, determine max length writeable, write it,
+	   block that we have used the data, then check if the write
+	   worked.  */
+	
+	data_block = find_next_block ();
+	if (! data_block)
+	  {
+	    ERROR ((0, 0, _("Unexpected EOF in archive")));
+	    break;		/* FIXME: What happens, then?  */
+	  }
+
+	written = available_space_after (data_block);
+	
+	if (written > size)
+	  written = size;
+	errno = 0;
+	count = full_write (fd, data_block->buffer, written);
+	size -= count;
+	
+	set_next_block_after ((union block *)
+			      (data_block->buffer + written - 1));
+	if (count != written)
+	  {
+	    write_error_details (file_name, count, written);
+	    break;
+	  }
+      }
+  
+  skip_file (size);
+
+  if (multi_volume_option)
+    assign_string (&save_name, 0);
+
+  /* If writing to stdout, don't try to do anything to the filename;
+     it doesn't exist, or we don't want to touch it anyway.  */
+
+  if (to_stdout_option)
+    return;
+
+  status = close (fd);
+  if (status < 0)
+    {
+      close_error (file_name);
+      if (backup_option)
+	undo_last_backup ();
+    }
+
+  set_stat (file_name, &current_stat_info.stat, 0, 0,
+	    (old_files_option == OVERWRITE_OLD_FILES
+	     ? UNKNOWN_PERMSTATUS
+	     : ARCHIVED_PERMSTATUS),
+	    typeflag);
+}  
+
+static void
+extract_link (char *file_name)
+{
+  char const *link_name;
+  int interdir_made = 0;
+  
+  if (!prepare_to_extract (file_name))
+    return;
+
+  do
+    {
+      struct stat st1, st2;
+      int e;
+      link_name = safer_name_suffix (current_stat_info.link_name, true);
+      
+      int status = link (link_name, file_name);
+      e = errno;
+
+      if (status == 0)
+	{
+	  struct delayed_symlink *ds = delayed_symlink_head;
+	  if (ds && lstat (link_name, &st1) == 0)
+	    for (; ds; ds = ds->next)
+	      if (ds->dev == st1.st_dev
+		  && ds->ino == st1.st_ino
+		  && ds->mtime == st1.st_mtime)
+		{
+		  struct string_list *p =  xmalloc (offsetof (struct string_list, string)
+						    + strlen (file_name) + 1);
+		  strcpy (p->string, file_name);
+		  p->next = ds->sources;
+		  ds->sources = p;
+		  break;
+		}
+	  return;
+	}
+      else if ((e == EEXIST && strcmp (link_name, file_name) == 0)
+	       || (lstat (link_name, &st1) == 0
+		   && lstat (file_name, &st2) == 0
+		   && st1.st_dev == st2.st_dev
+		   && st1.st_ino == st2.st_ino))
+	return;
+      
+      errno = e;
+    }
+  while (maybe_recoverable (file_name, &interdir_made));
+
+  if (!(incremental_option && errno == EEXIST))
+    {
+      link_error (link_name, file_name);
+      if (backup_option)
+	undo_last_backup ();
+    }
+}  
+
+static void
+extract_symlink (char *file_name)
+{
+#ifdef HAVE_SYMLINK
+  int status, fd;
+  int interdir_made = 0;
+  
+  if (! prepare_to_extract (file_name))
+    return;
+
+  if (absolute_names_option
+      || ! (IS_ABSOLUTE_FILE_NAME (current_stat_info.link_name)
+	    || contains_dot_dot (current_stat_info.link_name)))
+    {
+      while (status = symlink (current_stat_info.link_name, file_name),
+	     status != 0)
+	if (!maybe_recoverable (file_name, &interdir_made))
+	  break;
+
+      if (status == 0)
+	set_stat (file_name, &current_stat_info.stat, 0, 0, 0, SYMTYPE);
+      else
+	symlink_error (current_stat_info.link_name, file_name);
+    }
+  else
+    {
+      /* This symbolic link is potentially dangerous.  Don't
+	 create it now; instead, create a placeholder file, which
+	 will be replaced after other extraction is done.  */
+      struct stat st;
+
+      while ((fd = open (file_name, O_WRONLY | O_CREAT | O_EXCL, 0)) < 0)
+	if (! maybe_recoverable (file_name, &interdir_made))
+	  break;
+
+      status = -1;
+      if (fd < 0)
+	open_error (file_name);
+      else if (fstat (fd, &st) != 0)
+	{
+	  stat_error (file_name);
+	  close (fd);
+	}
+      else if (close (fd) != 0)
+	close_error (file_name);
+      else
+	{
+	  struct delayed_set_stat *h;
+	  struct delayed_symlink *p = xmalloc (offsetof (struct delayed_symlink, target)
+					       + strlen (current_stat_info.link_name)
+					       + 1);
+	  p->next = delayed_symlink_head;
+	  delayed_symlink_head = p;
+	  p->dev = st.st_dev;
+	  p->ino = st.st_ino;
+	  p->mtime = st.st_mtime;
+	  p->uid = current_stat_info.stat.st_uid;
+	  p->gid = current_stat_info.stat.st_gid;
+	  p->sources = xmalloc (offsetof (struct string_list, string)
+				+ strlen (file_name) + 1);
+	  p->sources->next = 0;
+	  strcpy (p->sources->string, file_name);
+	  strcpy (p->target, current_stat_info.link_name);
+
+	  h = delayed_set_stat_head;
+	  if (h && ! h->after_symlinks
+	      && strncmp (file_name, h->file_name, h->file_name_len) == 0
+	      && ISSLASH (file_name[h->file_name_len])
+	      && (base_name (file_name) == file_name + h->file_name_len + 1))
+	    {
+	      do
+		{
+		  h->after_symlinks = 1;
+		  
+		  if (stat (h->file_name, &st) != 0)
+		    stat_error (h->file_name);
+		  else
+		    {
+		      h->stat_info.st_dev = st.st_dev;
+		      h->stat_info.st_ino = st.st_ino;
+		    }
+		}
+	      while ((h = h->next) && ! h->after_symlinks);
+	    }
+	  
+	  status = 0;
+	}
+    }
+
+  if (status != 0 && backup_option)
+    undo_last_backup ();
+
+#else
+  static int warned_once;
+
+  if (!warned_once)
+    {
+      warned_once = 1;
+      WARN ((0, 0, _("Attempting extraction of symbolic links as hard links")));
+    }
+  extract_link (file_name);  
+#endif
+}  
+
+#if S_IFCHR || S_IFBLK
+static void
+extract_node (char *file_name, int typeflag)
+{
+  int status;
+  int interdir_made = 0;
+  
+  do
+    {
+      if (! prepare_to_extract (file_name))
+	return;
+  
+      status = mknod (file_name, current_stat_info.stat.st_mode,
+		      current_stat_info.stat.st_rdev);
+    }
+  while (status && maybe_recoverable (file_name, &interdir_made));
+  
+  if (status != 0)
+    {
+      mknod_error (file_name);
+      if (backup_option)
+	undo_last_backup ();
+    }
+  else
+    set_stat (file_name, &current_stat_info.stat, 0, 0, ARCHIVED_PERMSTATUS, typeflag);
+}
+#endif
+
+#if HAVE_MKFIFO || defined mkfifo
+static void
+extract_fifo (char *file_name, int typeflag)
+{
+  int status;
+  int interdir_made = 0;
+  
+  if (! prepare_to_extract (file_name))
+    return;
+
+  while ((status = mkfifo (file_name, current_stat_info.stat.st_mode)))
+    if (!maybe_recoverable (file_name, &interdir_made))
+      break;
+
+  if (status == 0)
+    set_stat (file_name, &current_stat_info.stat, NULL, 0,
+	      ARCHIVED_PERMSTATUS, typeflag);
+  else
+    {
+      mkfifo_error (file_name);
+      if (backup_option)
+	undo_last_backup ();
+    }
+}  
+#endif
+
+/* Extract a file from the archive.  */
+void
+extract_archive (void)
+{
   char typeflag;
   char *file_name;
 
