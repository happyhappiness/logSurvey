      possible, real problems are unlikely.  Doing any better would require a
      convention, GNU-wide, for all programs doing backups.  */
 
-  assign_string (&after_backup_name, NULL);
-  after_backup_name = find_backup_file_name (path);
-  if (after_backup_name == NULL)
-    FATAL_ERROR ((0, 0, "Virtual memory exhausted"));
+  assign_string (&after_backup_name, 0);
+  after_backup_name = find_backup_file_name (path, backup_type);
+  if (! after_backup_name)
+    xalloc_die ();
 
   if (rename (before_backup_name, after_backup_name) == 0)
     {
       if (verbose_option)
-	fprintf (stdlis, _("Renaming previous `%s' to `%s'\n"),
-		 before_backup_name, after_backup_name);
+	fprintf (stdlis, _("Renaming %s to %s\n"),
+		 quote_n (0, before_backup_name),
+		 quote_n (1, after_backup_name));
       return 1;
     }
-
-  /* The backup operation failed.  */
-
-  ERROR ((0, errno, _("%s: Cannot rename for backup"), before_backup_name));
-  assign_string (&after_backup_name, NULL);
-  return 0;
+  else
+    {
+      /* The backup operation failed.  */
+      int e = errno;
+      ERROR ((0, e, _("%s: Cannot rename to %s"),
+	      quotearg_colon (before_backup_name),
+	      quote_n (1, after_backup_name)));
+      assign_string (&after_backup_name, 0);
+      return 0;
+    }
 }
 
-/*-----------------------------------------------------------------------.
-| Try to restore the recently backed up file to its original name.  This |
-| is usually only needed after a failed extraction.			 |
-`-----------------------------------------------------------------------*/
-
+/* Try to restore the recently backed up file to its original name.
+   This is usually only needed after a failed extraction.  */
 void
 undo_last_backup (void)
 {
   if (after_backup_name)
     {
       if (rename (after_backup_name, before_backup_name) != 0)
-	ERROR ((0, errno, _("%s: Cannot rename from backup"),
-		before_backup_name));
+	{
+	  int e = errno;
+	  ERROR ((0, e, _("%s: Cannot rename to %s"),
+		  quotearg_colon (after_backup_name),
+		  quote_n (1, before_backup_name)));
+	}
       if (verbose_option)
-	fprintf (stdlis, _("Renaming `%s' back to `%s'\n"),
-		 after_backup_name, before_backup_name);
-      assign_string (&after_backup_name, NULL);
+	fprintf (stdlis, _("Renaming %s back to %s\n"),
+		 quote_n (0, after_backup_name),
+		 quote_n (1, before_backup_name));
+      assign_string (&after_backup_name, 0);
     }
 }
+
+/* Depending on DEREF, apply either stat or lstat to (NAME, BUF).  */
+int
+deref_stat (bool deref, char const *name, struct stat *buf)
+{
+  return deref ? stat (name, buf) : lstat (name, buf);
+}
+
+/* A description of a working directory.  */
+struct wd
+{
+  char const *name;
+  int saved;
+  struct saved_cwd saved_cwd;
+};
+
+/* A vector of chdir targets.  wd[0] is the initial working directory.  */
+static struct wd *wd;
+
+/* The number of working directories in the vector.  */
+static size_t wds;
+
+/* The allocated size of the vector.  */
+static size_t wd_alloc;
+
+/* DIR is the operand of a -C option; add it to vector of chdir targets,
+   and return the index of its location.  */
+int
+chdir_arg (char const *dir)
+{
+  if (wds == wd_alloc)
+    {
+      wd_alloc = 2 * (wd_alloc + 1);
+      wd = xrealloc (wd, sizeof *wd * wd_alloc);
+      if (! wds)
+	{
+	  wd[wds].name = ".";
+	  wd[wds].saved = 0;
+	  wds++;
+	}
+    }
+
+  /* Optimize the common special case of the working directory,
+     or the working directory as a prefix.  */
+  if (dir[0])
+    {
+      while (dir[0] == '.' && ISSLASH (dir[1]))
+	for (dir += 2;  ISSLASH (*dir);  dir++)
+	  continue;
+      if (! dir[dir[0] == '.'])
+	return wds - 1;
+    }
+
+  wd[wds].name = dir;
+  wd[wds].saved = 0;
+  return wds++;
+}
+
+/* Change to directory I.  If I is 0, change to the initial working
+   directory; otherwise, I must be a value returned by chdir_arg.  */
+void
+chdir_do (int i)
+{
+  static int previous;
+
+  if (previous != i)
+    {
+      struct wd *prev = &wd[previous];
+      struct wd *curr = &wd[i];
+
+      if (! prev->saved)
+	{
+	  prev->saved = 1;
+	  if (save_cwd (&prev->saved_cwd) != 0)
+	    FATAL_ERROR ((0, 0, _("Cannot save working directory")));
+	}
+
+      if (curr->saved)
+	{
+	  if (restore_cwd (&curr->saved_cwd))
+	    FATAL_ERROR ((0, 0, _("Cannot change working directory")));
+	}
+      else
+	{
+	  if (i && ! ISSLASH (curr->name[0]))
+	    chdir_do (i - 1);
+	  if (chdir (curr->name) != 0)
+	    chdir_fatal (curr->name);
+	}
+
+      previous = i;
+    }
+}
+
+/* Decode MODE from its binary form in a stat structure, and encode it
+   into a 9-byte string STRING, terminated with a NUL.  */
+
+void
+decode_mode (mode_t mode, char *string)
+{
+  *string++ = mode & S_IRUSR ? 'r' : '-';
+  *string++ = mode & S_IWUSR ? 'w' : '-';
+  *string++ = (mode & S_ISUID
+	       ? (mode & S_IXUSR ? 's' : 'S')
+	       : (mode & S_IXUSR ? 'x' : '-'));
+  *string++ = mode & S_IRGRP ? 'r' : '-';
+  *string++ = mode & S_IWGRP ? 'w' : '-';
+  *string++ = (mode & S_ISGID
+	       ? (mode & S_IXGRP ? 's' : 'S')
+	       : (mode & S_IXGRP ? 'x' : '-'));
+  *string++ = mode & S_IROTH ? 'r' : '-';
+  *string++ = mode & S_IWOTH ? 'w' : '-';
+  *string++ = (mode & S_ISVTX
+	       ? (mode & S_IXOTH ? 't' : 'T')
+	       : (mode & S_IXOTH ? 'x' : '-'));
+  *string = '\0';
+}
+
+/* Report an error associated with the system call CALL and the
+   optional name NAME.  */
+static void
+call_arg_error (char const *call, char const *name)
+{
+  int e = errno;
+  ERROR ((0, e, _("%s: Cannot %s"), quotearg_colon (name), call));
+}
+
+/* Report a fatal error associated with the system call CALL and
+   the optional file name NAME.  */
+static void
+call_arg_fatal (char const *call, char const *name)
+{
+  int e = errno;
+  FATAL_ERROR ((0, e, _("%s: Cannot %s"), quotearg_colon (name),  call));
+}
+
+/* Report a warning associated with the system call CALL and
+   the optional file name NAME.  */
+static void
+call_arg_warn (char const *call, char const *name)
+{
+  int e = errno;
+  WARN ((0, e, _("%s: Warning: Cannot %s"), quotearg_colon (name), call));
+}
+
+void
+chdir_fatal (char const *name)
+{
+  call_arg_fatal ("chdir", name);
+}
+
+void
+chmod_error_details (char const *name, mode_t mode)
+{
+  int e = errno;
+  char buf[10];
+  decode_mode (mode, buf);
+  ERROR ((0, e, _("%s: Cannot change mode to %s"),
+	  quotearg_colon (name), buf));
+}
+
+void
+chown_error_details (char const *name, uid_t uid, gid_t gid)
+{
+  int e = errno;
+  ERROR ((0, e, _("%s: Cannot change ownership to uid %lu, gid %lu"),
+	  quotearg_colon (name), (unsigned long) uid, (unsigned long) gid));
+}
+
+void
+close_error (char const *name)
+{
+  call_arg_error ("close", name);
+}
+
+void
+close_fatal (char const *name)
+{
+  call_arg_fatal ("close", name);
+}
+
+void
+close_warn (char const *name)
+{
+  call_arg_warn ("close", name);
+}
+
+void
+exec_fatal (char const *name)
+{
+  call_arg_fatal ("exec", name);
+}
+
+void
+link_error (char const *target, char const *source)
+{
+  int e = errno;
+  ERROR ((0, e, _("%s: Cannot hard link to %s"),
+	  quotearg_colon (source), quote_n (1, target)));
+}
+
+void
+mkdir_error (char const *name)
+{
+  call_arg_error ("mkdir", name);
+}
+
+void
+mkfifo_error (char const *name)
+{
+  call_arg_error ("mkfifo", name);
+}
+
+void
+mknod_error (char const *name)
+{
+  call_arg_error ("mknod", name);
+}
+
+void
+open_error (char const *name)
+{
+  call_arg_error ("open", name);
+}
+
+void
+open_fatal (char const *name)
+{
+  call_arg_fatal ("open", name);
+}
+
+void
+open_warn (char const *name)
+{
+  call_arg_warn ("open", name);
+}
+
+void
+read_error (char const *name)
+{
+  call_arg_error ("read", name);
+}
+
+void
+read_error_details (char const *name, off_t offset, size_t size)
+{
+  char buf[UINTMAX_STRSIZE_BOUND];
+  int e = errno;
+  ERROR ((0, e,
+	  _("%s: Read error at byte %s, reading %lu bytes"),
+	  quotearg_colon (name), STRINGIFY_BIGINT (offset, buf),
+	  (unsigned long) size));
+}
+
+void
+read_warn_details (char const *name, off_t offset, size_t size)
+{
+  char buf[UINTMAX_STRSIZE_BOUND];
+  int e = errno;
+  WARN ((0, e,
+	 _("%s: Warning: Read error at byte %s, reading %lu bytes"),
+	 quotearg_colon (name), STRINGIFY_BIGINT (offset, buf),
+	 (unsigned long) size));
+}
+
+void
+read_fatal (char const *name)
+{
+  call_arg_fatal ("read", name);
+}
+
+void
+read_fatal_details (char const *name, off_t offset, size_t size)
+{
+  char buf[UINTMAX_STRSIZE_BOUND];
+  int e = errno;
+  FATAL_ERROR ((0, e,
+		_("%s: Read error at byte %s, reading %lu bytes"),
+		quotearg_colon (name), STRINGIFY_BIGINT (offset, buf),
+		(unsigned long) size));
+}
+
+void
+readlink_error (char const *name)
+{
+  call_arg_error ("readlink", name);
+}
+
+void
+readlink_warn (char const *name)
+{
+  call_arg_warn ("readlink", name);
+}
+
+void
+savedir_error (char const *name)
+{
+  call_arg_error ("savedir", name);
+}
+
+void
+savedir_warn (char const *name)
+{
+  call_arg_warn ("savedir", name);
+}
+
+void
+seek_error (char const *name)
+{
+  call_arg_error ("seek", name);
+}
+
+void
+seek_error_details (char const *name, off_t offset)
+{
+  char buf[UINTMAX_STRSIZE_BOUND];
+  int e = errno;
+  ERROR ((0, e, _("%s: Cannot seek to %s"),
+	  quotearg_colon (name),
+	  STRINGIFY_BIGINT (offset, buf)));
+}
+
+void
+seek_warn (char const *name)
+{
+  call_arg_warn ("seek", name);
+}
+
+void
+seek_warn_details (char const *name, off_t offset)
+{
+  char buf[UINTMAX_STRSIZE_BOUND];
+  int e = errno;
+  WARN ((0, e, _("%s: Warning: Cannot seek to %s"),
+	 quotearg_colon (name),
+	 STRINGIFY_BIGINT (offset, buf)));
+}
+
+void
+symlink_error (char const *contents, char const *name)
+{
+  int e = errno;
+  ERROR ((0, e, _("%s: Cannot create symlink to %s"),
+	  quotearg_colon (name), quote_n (1, contents)));
+}
+
+void
+stat_error (char const *name)
+{
+  call_arg_error ("stat", name);
+}
+
+void
+stat_warn (char const *name)
+{
+  call_arg_warn ("stat", name);
+}
+
+void
+truncate_error (char const *name)
+{
+  call_arg_error ("truncate", name);
+}
+
+void
+truncate_warn (char const *name)
+{
+  call_arg_warn ("truncate", name);
+}
+
+void
+unlink_error (char const *name)
+{
+  call_arg_error ("unlink", name);
+}
+
+void
+utime_error (char const *name)
+{
+  call_arg_error ("utime", name);
+}
+
+void
+waitpid_error (char const *name)
+{
+  call_arg_error ("waitpid", name);
+}
+
+void
+write_error (char const *name)
+{
+  call_arg_error ("write", name);
+}
+
+void
+write_error_details (char const *name, ssize_t status, size_t size)
+{
+  if (status < 0)
+    write_error (name);
+  else
+    ERROR ((0, 0, _("%s: Wrote only %lu of %lu bytes"),
+	    name, (unsigned long) status, (unsigned long) record_size));
+}
+
+void
+write_fatal (char const *name)
+{
+  call_arg_fatal ("write", name);
+}
+
+void
+write_fatal_details (char const *name, ssize_t status, size_t size)
+{
+  write_error_details (name, status, size);
+  fatal_exit ();
+}
+
+
+/* Fork, aborting if unsuccessful.  */
+pid_t
+xfork (void)
+{
+  pid_t p = fork ();
+  if (p == (pid_t) -1)
+    call_arg_fatal ("fork", _("child process"));
+  return p;
+}
+
+/* Create a pipe, aborting if unsuccessful.  */
+void
+xpipe (int fd[2])
+{
+  if (pipe (fd) < 0)
+    call_arg_fatal ("pipe", _("interprocess channel"));
+}
+
+/* Return an unambiguous printable representation, allocated in slot N,
+   for NAME, suitable for diagnostics.  */
+char const *
+quote_n (int n, char const *name)
+{
+  return quotearg_n_style (n, locale_quoting_style, name);
+}
+
+/* Return an unambiguous printable representation of NAME, suitable
+   for diagnostics.  */
+char const *
+quote (char const *name)
+{
+  return quote_n (0, name);
+}
