     return buffer;
   }
 }
-
-/*----------------------------------------------------------------------.
-| Add all the files in PATH, which is a directory, to the namelist.  If |
-| any of the files is a directory, recurse on the subdirectory.	        |
-`----------------------------------------------------------------------*/
-
-static void
-add_hierarchy_to_namelist (char *path, int device)
-{
-  char *buffer = get_directory_contents (path, device);
-
-  {
-    struct name *name;
-
-    for (name = namelist; name; name = name->next)
-      if (strcmp (name->name, path) == 0)
-	  break;
-    if (name)
-      name->dir_contents = buffer ? buffer : "\0\0\0\0";
-  }
-
-  if (buffer)
-    {
-      int name_length = strlen (path);
-      int allocated_length = (name_length >= NAME_FIELD_SIZE
-			      ? name_length + NAME_FIELD_SIZE
-			      : NAME_FIELD_SIZE);
-      char *name_buffer = xmalloc ((size_t) (allocated_length + 1));
-				/* FIXME: + 2 above?  */
-      char *string;
-      int string_length;
-
-      strcpy (name_buffer, path);
-      if (name_buffer[name_length - 1] != '/')
-	{
-	  name_buffer[name_length++] = '/';
-	  name_buffer[name_length] = '\0';
-	}
-
-      for (string = buffer; *string; string += string_length + 1)
-	{
-	  string_length = strlen (string);
-	  if (*string == 'D')
-	    {
-	      if (name_length + string_length >= allocated_length)
-		{
-		  while (name_length + string_length >= allocated_length)
-		    allocated_length += NAME_FIELD_SIZE;
-		  name_buffer = (char *)
-		    xrealloc (name_buffer, (size_t) (allocated_length + 1));
-		}
-	      strcpy (name_buffer + name_length, string + 1);
-	      addname (name_buffer);
-	      add_hierarchy_to_namelist (name_buffer, device);
-	    }
-	}
-
-      free (name_buffer);
-    }
-}
 
-/*---.
-| ?  |
-`---*/
+static FILE *listed_incremental_stream;
 
-static void
+void
 read_directory_file (void)
 {
-  dev_t device_number;
-  ino_t inode_number;
-  char *strp;
+  int fd;
   FILE *fp;
-  char buf[512];
-  static char *path = NULL;
-
-  if (path == NULL)
-    path = xmalloc (PATH_MAX);
-  time (&time_now);
-  if (listed_incremental_option[0] != '/')
-    {
-#if HAVE_GETCWD
-      if (!getcwd (path, PATH_MAX))
-	FATAL_ERROR ((0, 0, _("Could not get current directory")));
-#else
-      char *getwd ();
-
-      if (!getwd (path))
-	FATAL_ERROR ((0, 0, _("Could not get current directory: %s"), path));
-#endif
-
-      if (strlen (path) + 1 + strlen (listed_incremental_option) + 1 > PATH_MAX)
-	ERROR ((TAREXIT_FAILURE, 0, _("File name %s/%s too long"),
-		path, listed_incremental_option));
-
-      strcat (path, "/");
-      strcat (path, listed_incremental_option);
-      listed_incremental_option = path;
-    }
-  fp = fopen (listed_incremental_option, "r");
-  if (fp == 0 && errno != ENOENT)
+  char *buf = 0;
+  size_t bufsize;
+
+  /* Open the file for both read and write.  That way, we can write
+     it later without having to reopen it, and don't have to worry if
+     we chdir in the meantime.  */
+  fd = open (listed_incremental_option, O_RDWR | O_CREAT, MODE_RW);
+  if (fd < 0)
     {
-      ERROR ((0, errno, _("Cannot open %s"), listed_incremental_option));
+      open_error (listed_incremental_option);
       return;
     }
-  if (!fp)
-    return;
-  fgets (buf, sizeof (buf), fp);
-
-  /* FIXME: Using after_date_option as a first time flag looks fairly
-     dubious to me!  So, using -N with incremental might be buggy just
-     because of the next few lines.  I saw a few unexplained, almost harsh
-     advices, from other GNU people, about *not* using -N with incremental
-     dumps, and here might lie (part of) the reason.  */
-  if (!after_date_option)
-    {
-      newer_mtime_option = atol (buf);
-      after_date_option = 1;
-    }
 
-  while (fgets (buf, sizeof (buf), fp))
+  fp = fdopen (fd, "r+");
+  if (! fp)
     {
-      strp = &buf[strlen (buf)];
-      if (strp[-1] == '\n')
-	strp[-1] = '\0';
-      /* FIXME: For files ending with an incomplete line, maybe a NUL might
-	 be missing, here...  */
-
-      strp = buf;
-      device_number = atol (strp);
-      while (ISDIGIT (*strp))
-	strp++;
-      inode_number = atol (strp);
-      while (ISSPACE (*strp))
-	strp++;
-      while (ISDIGIT (*strp))
-	strp++;
-      strp++;
-      unquote_string (strp);
-      note_directory (strp, device_number, inode_number, NULL);
+      open_error (listed_incremental_option);
+      close (fd);
+      return;
     }
-  if (fclose (fp) == EOF)
-    ERROR ((0, errno, "%s", listed_incremental_option));
-}
 
-/*---.
-| ?  |
-`---*/
-
-void
-write_dir_file (void)
-{
-  FILE *fp;
-  struct directory *directory;
-  char *str;
+  listed_incremental_stream = fp;
 
-  fp = fopen (listed_incremental_option, "w");
-  if (fp == 0)
-    {
-      ERROR ((0, errno, _("Cannot write to %s"), listed_incremental_option));
-      return;
-    }
-  fprintf (fp, "%lu\n", time_now);
-  for (directory = directory_list; directory; directory = directory->next)
+  if (0 < getline (&buf, &bufsize, fp))
     {
-      if (!directory->dir_text)
-	continue;
-      str = quote_copy_string (directory->name);
-      if (str)
+      char *ebuf;
+      int n;
+      long lineno = 1;
+      unsigned long u = (errno = 0, strtoul (buf, &ebuf, 10));
+      time_t t = u;
+      if (buf == ebuf || (u == 0 && errno == EINVAL))
+	ERROR ((0, 0, "%s:1: %s", quotearg_colon (listed_incremental_option),
+		_("Invalid time stamp")));
+      else if (t != u || (u == -1 && errno == ERANGE))
+	ERROR ((0, 0, "%s:1: %s", quotearg_colon (listed_incremental_option),
+		_("Time stamp out of range")));
+      else
+	newer_mtime_option = t;
+
+      while (0 < (n = getline (&buf, &bufsize, fp)))
 	{
-	  fprintf (fp, "%u %u %s\n", directory->device_number,
-		   directory->inode_number, str);
-	  free (str);
+	  dev_t dev;
+	  ino_t ino;
+	  bool nfs = buf[0] == '+';
+	  char *strp = buf + nfs;
+
+	  lineno++;
+
+	  if (buf[n - 1] == '\n')
+	    buf[n - 1] = '\0';
+
+	  errno = 0;
+	  dev = u = strtoul (strp, &ebuf, 10);
+	  if (strp == ebuf || (u == 0 && errno == EINVAL))
+	    ERROR ((0, 0, "%s:%ld: %s",
+		    quotearg_colon (listed_incremental_option), lineno,
+		    _("Invalid device number")));
+	  else if (dev != u || (u == -1 && errno == ERANGE))
+	    ERROR ((0, 0, "%s:%ld: %s",
+		    quotearg_colon (listed_incremental_option), lineno,
+		    _("Device number out of range")));
+	  strp = ebuf;
+
+	  errno = 0;
+	  ino = u = strtoul (strp, &ebuf, 10);
+	  if (strp == ebuf || (u == 0 && errno == EINVAL))
+	    ERROR ((0, 0, "%s:%ld: %s",
+		    quotearg_colon (listed_incremental_option), lineno,
+		    _("Invalid inode number")));
+	  else if (ino != u || (u == -1 && errno == ERANGE))
+	    ERROR ((0, 0, "%s:%ld: %s",
+		    quotearg_colon (listed_incremental_option), lineno,
+		    _("Inode number out of range")));
+	  strp = ebuf;
+
+	  strp++;
+	  unquote_string (strp);
+	  note_directory (strp, dev, ino, nfs, 0);
 	}
-      else
-	fprintf (fp, "%u %u %s\n", directory->device_number,
-		 directory->inode_number, directory->name);
     }
-  if (fclose (fp) == EOF)
-    ERROR ((0, errno, "%s", listed_incremental_option));
-}
 
-/*---.
-| ?  |
-`---*/
+  if (ferror (fp))
+    read_error (listed_incremental_option);
+  if (buf)
+    free (buf);
+}
 
-static int
-compare_names (char *param1, char *param2)
+/* Output incremental data for the directory ENTRY to the file DATA.
+   Return nonzero if successful, preserving errno on write failure.  */
+static bool
+write_directory_file_entry (void *entry, void *data)
 {
-  struct name *n1 = (struct name *) param1;
-  struct name *n2 = (struct name *) param2;
+  struct directory const *directory = entry;
+  FILE *fp = data;
 
-  if (n1->found)
-    return n2->found ? strcmp (n1->name, n2->name) : -1;
-
-  if (n2->found)
-    return 1;
+  if (directory->found)
+    {
+      int e;
+      char *str = quote_copy_string (directory->name);
+      fprintf (fp, "+%lu %lu %s\n" + ! directory->nfs,
+	       (unsigned long) directory->device_number,
+	       (unsigned long) directory->inode_number,
+	       str ? str : directory->name);
+      e = errno;
+      if (str)
+	free (str);
+      errno = e;
+    }
 
-  return strcmp (n1->name, n2->name);
+  return ! ferror (fp);
 }
 
-/*-------------------------------------------------------------------------.
-| Collect all the names from argv[] (or whatever), then expand them into a |
-| directory tree, and put all the directories at the beginning.		   |
-`-------------------------------------------------------------------------*/
-
 void
-collect_and_sort_names (void)
+write_directory_file (void)
 {
-  struct name *name;
-  struct name *next_name;
-  int num_names;
-  struct stat statbuf;
-
-  name_gather ();
-
-  if (listed_incremental_option)
-    read_directory_file ();
-
-  if (!namelist)
-    addname (".");
-
-  for (name = namelist; name; name = next_name)
-    {
-      next_name = name->next;
-      if (name->found || name->dir_contents)
-	continue;
-      if (name->regexp)		/* FIXME: just skip regexps for now */
-	continue;
-      if (name->change_dir)
-	if (chdir (name->change_dir) < 0)
-	  {
-	    ERROR ((0, errno, _("Cannot chdir to %s"), name->change_dir));
-	    continue;
-	  }
-
-      if (
-#ifdef AIX
-	  statx (name->name, &statbuf, STATSIZE, STX_HIDDEN | STX_LINK)
-#else
-	  lstat (name->name, &statbuf) < 0
-#endif
-	  )
-	{
-	  ERROR ((0, errno, _("Cannot stat %s"), name->name));
-	  continue;
-	}
-      if (S_ISDIR (statbuf.st_mode))
-	{
-	  name->found = 1;
-	  add_hierarchy_to_namelist (name->name, statbuf.st_dev);
-	}
-    }
+  FILE *fp = listed_incremental_stream;
 
-  num_names = 0;
-  for (name = namelist; name; name = name->next)
-    num_names++;
-  namelist = (struct name *)
-    merge_sort ((voidstar) namelist, num_names,
-		(char *) (&(namelist->next)) - (char *) namelist,
-		compare_names);
-
-  for (name = namelist; name; name = name->next)
-    name->found = 0;
+  if (! fp)
+    return;
 
-  if (listed_incremental_option)
-    write_dir_file ();
+  if (fseek (fp, 0L, SEEK_SET) != 0)
+    seek_error (listed_incremental_option);
+  if (ftruncate (fileno (fp), (off_t) 0) != 0)
+    truncate_error (listed_incremental_option);
+
+  fprintf (fp, "%lu\n", (unsigned long) start_time);
+  if (! ferror (fp) && directory_table)
+    hash_do_for_each (directory_table, write_directory_file_entry, fp);
+  if (ferror (fp))
+    write_error (listed_incremental_option);
+  if (fclose (fp) != 0)
+    close_error (listed_incremental_option);
 }
 
 /* Restoration of incremental dumps.  */
 
-/*---.
-| ?  |
-`---*/
-
 void
-gnu_restore (int skipcrud)
+gnu_restore (char const *directory_name)
 {
-  char *current_dir;
   char *archive_dir;
-  struct accumulator *accumulator;
-  char *p;
-  DIR *dirp;
-  struct dirent *d;
+  char *current_dir;
   char *cur, *arc;
-  long size, copied;
+  size_t size;
+  size_t copied;
   union block *data_block;
   char *to;
 
-#define CURRENT_FILE_NAME (skipcrud + current_file_name)
+  current_dir = savedir (directory_name);
 
-  dirp = opendir (CURRENT_FILE_NAME);
-
-  if (!dirp)
+  if (!current_dir)
     {
       /* The directory doesn't exist now.  It'll be created.  In any
 	 case, we don't have to delete any files out of it.  */
 
-      skip_file ((long) current_stat.st_size);
+      skip_member ();
       return;
     }
 
-  accumulator = new_accumulator ();
-  while (d = readdir (dirp), d)
-    {
-      if (is_dot_or_dotdot (d->d_name))
-	continue;
-
-      add_to_accumulator (accumulator, d->d_name, (int) (NAMLEN (d) + 1));
-    }
-  closedir (dirp);
-  add_to_accumulator (accumulator, "", 1);
-
-  current_dir = get_accumulator (accumulator);
-  archive_dir = (char *) xmalloc ((size_t) current_stat.st_size);
+  size = current_stat_info.stat.st_size;
+  if (size != current_stat_info.stat.st_size)
+    xalloc_die ();
+  archive_dir = xmalloc (size);
   to = archive_dir;
-  for (size = current_stat.st_size; size > 0; size -= copied)
+  for (; size > 0; size -= copied)
     {
       data_block = find_next_block ();
       if (!data_block)
