   /* Something went wrong.  Close down and go home.  */
 
   signal (SIGPIPE, pipe_handler);
-  _rmt_shutdown (fildes);
-  errno = EIO;
+  _rmt_shutdown (handle, EIO);
   return -1;
 }
 
-/* Read and return the status from remote tape connection FILDES.
-   If an error occurred, return -1 and set errno.  */
+/*----------------------------------------------------------------------.
+| Read and return the status from remote tape connection HANDLE.  If an |
+| error occurred, return -1 and set errno.			        |
+`----------------------------------------------------------------------*/
 
 static int
-status (fildes)
-     int fildes;
+get_status (int handle)
 {
-  int i;
-  char c, *cp;
-  char buffer[CMDBUFSIZE];
+  char command_buffer[COMMAND_BUFFER_SIZE];
+  char *cursor;
+  int counter;
 
   /* Read the reply command line.  */
 
-  for (i = 0, cp = buffer; i < CMDBUFSIZE; i++, cp++)
+  for (counter = 0, cursor = command_buffer;
+       counter < COMMAND_BUFFER_SIZE;
+       counter++, cursor++)
     {
-      if (read (READ (fildes), cp, 1) != 1)
+      if (read (READ_SIDE (handle), cursor, 1) != 1)
 	{
-	  _rmt_shutdown (fildes);
-	  errno = EIO;
+	  _rmt_shutdown (handle, EIO);
 	  return -1;
 	}
-      if (*cp == '\n')
+      if (*cursor == '\n')
 	{
-	  *cp = '\0';
+	  *cursor = '\0';
 	  break;
 	}
     }
 
-  if (i == CMDBUFSIZE)
+  if (counter == COMMAND_BUFFER_SIZE)
     {
-      _rmt_shutdown (fildes);
-      errno = EIO;
+      _rmt_shutdown (handle, EIO);
       return -1;
     }
 
   /* Check the return status.  */
 
-  for (cp = buffer; *cp; cp++)
-    if (*cp != ' ')
+  for (cursor = command_buffer; *cursor; cursor++)
+    if (*cursor != ' ')
       break;
 
-  if (*cp == 'E' || *cp == 'F')
+  if (*cursor == 'E' || *cursor == 'F')
     {
-      errno = atoi (cp + 1);
+      errno = atoi (cursor + 1); /* FIXME: errno should be read-only */
+
       /* Skip the error message line.  */
-      while (read (READ (fildes), &c, 1) == 1)
-	if (c == '\n')
-	  break;
 
-      if (*cp == 'F')
-	_rmt_shutdown (fildes);
+      /* FIXME: there is better to do than merely ignoring error messages
+	 coming from the remote end.  Translate them, too...  */
+
+      {
+	char character;
+
+	while (read (READ_SIDE (handle), &character, 1) == 1)
+	  if (character == '\n')
+	    break;
+      }
+
+      if (*cursor == 'F')
+	_rmt_shutdown (handle, errno);
 
       return -1;
     }
 
-  /* Check for mis-synced pipes. */
+  /* Check for mis-synced pipes.  */
 
-  if (*cp != 'A')
+  if (*cursor != 'A')
     {
-      _rmt_shutdown (fildes);
-      errno = EIO;
+      _rmt_shutdown (handle, EIO);
       return -1;
     }
 
   /* Got an `A' (success) response.  */
-  return atoi (cp + 1);
+
+  return atoi (cursor + 1);
 }
 
-#ifdef HAVE_NETDB_H
-/* Execute /etc/rmt as user USER on remote system HOST using rexec.
-   Return a file descriptor of a bidirectional socket for stdin and stdout.
-   If USER is NULL, or an empty string, use the current username.
+#if HAVE_NETDB_H
 
-   By default, this code is not used, since it requires that
-   the user have a .netrc file in his/her home directory, or that the
-   application designer be willing to have rexec prompt for login and
-   password info.  This may be unacceptable, and .rhosts files for use
-   with rsh are much more common on BSD systems.  */
+/*-------------------------------------------------------------------------.
+| Execute /etc/rmt as user USER on remote system HOST using rexec.  Return |
+| a file descriptor of a bidirectional socket for stdin and stdout.  If	   |
+| USER is NULL, use the current username.				   |
+| 									   |
+| By default, this code is not used, since it requires that the user have  |
+| a .netrc file in his/her home directory, or that the application	   |
+| designer be willing to have rexec prompt for login and password info.	   |
+| This may be unacceptable, and .rhosts files for use with rsh are much	   |
+| more common on BSD systems.						   |
+`-------------------------------------------------------------------------*/
 
 static int
-_rmt_rexec (host, user)
-     char *host;
-     char *user;
+_rmt_rexec (char *host, char *user)
 {
+  int saved_stdin = dup (fileno (stdin));
+  int saved_stdout = dup (fileno (stdout));
   struct servent *rexecserv;
-  int save_stdin = dup (fileno (stdin));
-  int save_stdout = dup (fileno (stdout));
-  int tape_fd;			/* Return value. */
-
-  /* When using cpio -o < filename, stdin is no longer the tty.
-     But the rexec subroutine reads the login and the passwd on stdin,
-     to allow remote execution of the command.
-     So, reopen stdin and stdout on /dev/tty before the rexec and
-     give them back their original value after.  */
+  int result;
+
+  /* When using cpio -o < filename, stdin is no longer the tty.  But the
+     rexec subroutine reads the login and the passwd on stdin, to allow
+     remote execution of the command.  So, reopen stdin and stdout on
+     /dev/tty before the rexec and give them back their original value
+     after.  */
+
   if (freopen ("/dev/tty", "r", stdin) == NULL)
     freopen ("/dev/null", "r", stdin);
   if (freopen ("/dev/tty", "w", stdout) == NULL)
     freopen ("/dev/null", "w", stdout);
 
-  rexecserv = getservbyname ("exec", "tcp");
-  if (NULL == rexecserv)
-    {
-      fprintf (stderr, "exec/tcp: service not available");
-      exit (1);
-    }
-  if (user != NULL && *user == '\0')
-    user = NULL;
-  tape_fd = rexec (&host, rexecserv->s_port, user, NULL,
-		   "/etc/rmt", (int *) NULL);
-  fclose (stdin);
-  fdopen (save_stdin, "r");
-  fclose (stdout);
-  fdopen (save_stdout, "w");
+  if (rexecserv = getservbyname ("exec", "tcp"), !rexecserv)
+    error (EXIT_ON_EXEC_ERROR, 0, _("exec/tcp: Service not available"));
 
-  return tape_fd;
+  result = rexec (&host, rexecserv->s_port, user, NULL,
+		   "/etc/rmt", (int *) NULL);
+  if (fclose (stdin) == EOF)
+    error (0, errno, _("stdin"));
+  fdopen (saved_stdin, "r");
+  if (fclose (stdout) == EOF)
+    error (0, errno, _("stdout"));
+  fdopen (saved_stdout, "w");
+
+  return result;
 }
 
 #endif /* HAVE_NETDB_H */
 
-/* Open a magtape device on the system specified in PATH, as the given user.
-   PATH has the form `[user@]system:/dev/????'.
-   If COMPAT is defined, it can also have the form `system[.user]:/dev/????'.
-
-   OFLAG is O_RDONLY, O_WRONLY, etc.
-   MODE is ignored; 0666 is always used.
-
-   If successful, return the remote tape pipe number plus BIAS.
-   On error, return -1.  */
+/*------------------------------------------------------------------------.
+| Open a file (a magnetic tape device?) on the system specified in PATH,  |
+| as the given user.  PATH has the form `[USER@]HOST:FILE'.  OPEN_MODE is |
+| O_RDONLY, O_WRONLY, etc.  If successful, return the remote pipe number  |
+| plus BIAS.  REMOTE_SHELL may be overriden.  On error, return -1.	  |
+`------------------------------------------------------------------------*/
 
 int
-__rmt_open (path, oflag, mode, bias)
-     char *path;
-     int oflag;
-     int mode;
-     int bias;
+rmt_open__ (const char *path, int open_mode, int bias, const char *remote_shell)
 {
-  int i, rc;
-  char buffer[CMDBUFSIZE];	/* Command buffer.  */
-  char system[MAXHOSTLEN];	/* The remote host name.  */
-  char device[CMDBUFSIZE];	/* The remote device name.  */
-  char login[CMDBUFSIZE];	/* The remote user name.  */
-  char *sys, *dev, *user;	/* For copying into the above buffers.  */
-
-  sys = system;
-  dev = device;
-  user = login;
+  int remote_pipe_number;	/* pseudo, biased file descriptor */
+  char *path_copy ;		/* copy of path string */
+  char *remote_host;		/* remote host name */
+  char *remote_file;		/* remote file name (often a device) */
+  char *remote_user;		/* remote user name */
 
   /* Find an unused pair of file descriptors.  */
 
-  for (i = 0; i < MAXUNIT; i++)
-    if (READ (i) == -1 && WRITE (i) == -1)
+  for (remote_pipe_number = 0;
+       remote_pipe_number < MAXUNIT;
+       remote_pipe_number++)
+    if (READ_SIDE (remote_pipe_number) == -1
+	&& WRITE_SIDE (remote_pipe_number) == -1)
       break;
 
-  if (i == MAXUNIT)
+  if (remote_pipe_number == MAXUNIT)
     {
-      errno = EMFILE;
+      errno = EMFILE;		/* FIXME: errno should be read-only */
       return -1;
     }
 
-  /* Pull apart the system and device, and optional user.
-     Don't munge the original string.  */
+  /* Pull apart the system and device, and optional user.  */
 
-  while (*path != '@'
-#ifdef COMPAT
-	 && *path != '.'
-#endif
-	 && *path != ':')
-    {
-      *sys++ = *path++;
-    }
-  *sys = '\0';
-  path++;
+  {
+    char *cursor;
 
-  if (*(path - 1) == '@')
-    {
-      /* Saw user part of user@host.  Start over. */
-      strcpy (user, system);
-      sys = system;
-      while (*path != ':')
-	{
-	  *sys++ = *path++;
-	}
-      *sys = '\0';
-      path++;
-    }
-#ifdef COMPAT
-  else if (*(path - 1) == '.')
-    {
-      while (*path != ':')
+    path_copy = xstrdup (path);
+    remote_host = path_copy;
+    remote_user = NULL;
+    remote_file = NULL;
+
+    for (cursor = path_copy; *cursor; cursor++)
+      switch (*cursor)
 	{
-	  *user++ = *path++;
+	default:
+	  break;
+
+	case '@':
+	  if (!remote_user)
+	    {
+	      remote_user = remote_host;
+	      *cursor = '\0';
+	      remote_host = cursor + 1;
+	    }
+	  break;
+
+	case ':':
+	  if (!remote_file)
+	    {
+	      *cursor = '\0';
+	      remote_file = cursor + 1;
+	    }
+	  break;
 	}
-      *user = '\0';
-      path++;
-    }
-#endif
-  else
-    *user = '\0';
+  }
+
+  /* FIXME: Should somewhat validate the decoding, here.  */
+
+  if (remote_user && *remote_user == '\0')
+    remote_user = NULL;
 
-  while (*path)
+#if HAVE_NETDB_H
+
+  /* Execute the remote command using rexec.  */
+
+  READ_SIDE (remote_pipe_number) = _rmt_rexec (remote_host, remote_user);
+  if (READ_SIDE (remote_pipe_number) < 0)
     {
-      *dev++ = *path++;
+      free (path_copy);
+      return -1;
     }
-  *dev = '\0';
 
-#ifdef HAVE_NETDB_H
-  /* Execute the remote command using rexec.  */
-  READ (i) = WRITE (i) = _rmt_rexec (system, login);
-  if (READ (i) < 0)
-    return -1;
-#else /* !HAVE_NETDB_H */
-  /* Set up the pipes for the `rsh' command, and fork.  */
+  WRITE_SIDE (remote_pipe_number) = READ_SIDE (remote_pipe_number);
 
-  if (pipe (to_rmt[i]) == -1 || pipe (from_rmt[i]) == -1)
-    return -1;
+#else /* not HAVE_NETDB_H */
+  {
+    const char *remote_shell_basename;
+    int status;
 
-  rc = fork ();
-  if (rc == -1)
-    return -1;
+    /* Identify the remote command to be executed.  */
 
-  if (rc == 0)
-    {
-      /* Child.  */
-      close (0);
-      dup (to_rmt[i][0]);
-      close (to_rmt[i][0]);
-      close (to_rmt[i][1]);
+    if (!remote_shell)
+      {
+#ifdef REMOTE_SHELL
+	remote_shell = REMOTE_SHELL;
+#else
+	errno = EIO;		/* FIXME: errno should be read-only */
+	free (path_copy);
+	return -1;
+#endif
+      }
+    remote_shell_basename = strrchr (remote_shell, '/');
+    if (remote_shell_basename)
+      remote_shell_basename++;
+    else
+      remote_shell_basename = remote_shell;
+
+    /* Set up the pipes for the `rsh' command, and fork.  */
+
+    if (pipe (to_remote[remote_pipe_number]) == -1
+	|| pipe (from_remote[remote_pipe_number]) == -1)
+      {
+	free (path_copy);
+	return -1;
+      }
 
-      close (1);
-      dup (from_rmt[i][1]);
-      close (from_rmt[i][0]);
-      close (from_rmt[i][1]);
+    status = fork ();
+    if (status == -1)
+      {
+	free (path_copy);
+	return -1;
+      }
 
-      setuid (getuid ());
-      setgid (getgid ());
+    if (status == 0)
+      {
+	/* Child.  */
 
-      if (*login)
-	{
-	  execl ("/usr/ucb/rsh", "rsh", system, "-l", login,
-		 "/etc/rmt", (char *) 0);
-	  execl ("/usr/bin/remsh", "remsh", system, "-l", login,
-		 "/etc/rmt", (char *) 0);
-	  execl ("/usr/bin/rsh", "rsh", system, "-l", login,
-		 "/etc/rmt", (char *) 0);
-	  execl ("/usr/bsd/rsh", "rsh", system, "-l", login,
-		 "/etc/rmt", (char *) 0);
-	  execl ("/usr/bin/nsh", "nsh", system, "-l", login,
-		 "/etc/rmt", (char *) 0);
-	}
-      else
-	{
-	  execl ("/usr/ucb/rsh", "rsh", system,
-		 "/etc/rmt", (char *) 0);
-	  execl ("/usr/bin/remsh", "remsh", system,
-		 "/etc/rmt", (char *) 0);
-	  execl ("/usr/bin/rsh", "rsh", system,
-		 "/etc/rmt", (char *) 0);
-	  execl ("/usr/bsd/rsh", "rsh", system,
-		 "/etc/rmt", (char *) 0);
-	  execl ("/usr/bin/nsh", "nsh", system,
+	close (0);
+	dup (to_remote[remote_pipe_number][PREAD]);
+	close (to_remote[remote_pipe_number][PREAD]);
+	close (to_remote[remote_pipe_number][PWRITE]);
+
+	close (1);
+	dup (from_remote[remote_pipe_number][PWRITE]);
+	close (from_remote[remote_pipe_number][PREAD]);
+	close (from_remote[remote_pipe_number][PWRITE]);
+
+#if !MSDOS
+	setuid (getuid ());
+	setgid (getgid ());
+#endif
+
+	if (remote_user)
+	  execl (remote_shell, remote_shell_basename, remote_host,
+		 "-l", remote_user, "/etc/rmt", (char *) 0);
+	else
+	  execl (remote_shell, remote_shell_basename, remote_host,
 		 "/etc/rmt", (char *) 0);
-	}
 
-      /* Bad problems if we get here.  */
+	/* Bad problems if we get here.  */
 
-      perror ("cannot execute remote shell");
-      _exit (1);
-    }
+	/* In a previous version, _exit was used here instead of exit.  */
+	error (EXIT_ON_EXEC_ERROR, errno, _("Cannot execute remote shell"));
+      }
+
+    /* Parent.  */
 
-  /* Parent.  */
-  close (to_rmt[i][0]);
-  close (from_rmt[i][1]);
-#endif /* !HAVE_NETDB_H */
+    close (from_remote[remote_pipe_number][PWRITE]);
+    close (to_remote[remote_pipe_number][PREAD]);
+  }
+#endif /* not HAVE_NETDB_H */
 
   /* Attempt to open the tape device.  */
 
-  sprintf (buffer, "O%s\n%d\n", device, oflag);
-  if (command (i, buffer) == -1 || status (i) == -1)
-    return -1;
+  {
+    char command_buffer[COMMAND_BUFFER_SIZE];
 
-  return i + bias;
+    sprintf (command_buffer, "O%s\n%d\n", remote_file, open_mode);
+    if (do_command (remote_pipe_number, command_buffer) == -1
+	|| get_status (remote_pipe_number) == -1)
+      {
+	_rmt_shutdown (remote_pipe_number, errno);
+	free (path_copy);
+	return -1;
+      }
+  }
+
+  free (path_copy);
+  return remote_pipe_number + bias;
 }
 
-/* Close remote tape connection FILDES and shut down.
-   Return 0 if successful, -1 on error.  */
+/*----------------------------------------------------------------.
+| Close remote tape connection HANDLE and shut down.  Return 0 if |
+| successful, -1 on error.					  |
+`----------------------------------------------------------------*/
 
 int
-__rmt_close (fildes)
-     int fildes;
+rmt_close__ (int handle)
 {
-  int rc;
+  int status;
 
-  if (command (fildes, "C\n") == -1)
+  if (do_command (handle, "C\n") == -1)
     return -1;
 
-  rc = status (fildes);
-  _rmt_shutdown (fildes);
-  return rc;
+  status = get_status (handle);
+  _rmt_shutdown (handle, errno);
+  return status;
 }
 
-/* Read up to NBYTE bytes into BUF from remote tape connection FILDES.
-   Return the number of bytes read on success, -1 on error.  */
+/*-------------------------------------------------------------------------.
+| Read up to LENGTH bytes into BUFFER from remote tape connection HANDLE.  |
+| Return the number of bytes read on success, -1 on error.		   |
+`-------------------------------------------------------------------------*/
 
 int
-__rmt_read (fildes, buf, nbyte)
-     int fildes;
-     char *buf;
-     unsigned int nbyte;
+rmt_read__ (int handle, char *buffer, unsigned int length)
 {
-  int rc, i;
-  char buffer[CMDBUFSIZE];
+  char command_buffer[COMMAND_BUFFER_SIZE];
+  int status;
+  int counter;
 
-  sprintf (buffer, "R%d\n", nbyte);
-  if (command (fildes, buffer) == -1 || (rc = status (fildes)) == -1)
+  sprintf (command_buffer, "R%d\n", length);
+  if (do_command (handle, command_buffer) == -1
+      || (status = get_status (handle)) == -1)
     return -1;
 
-  for (i = 0; i < rc; i += nbyte, buf += nbyte)
+  for (counter = 0; counter < status; counter += length, buffer += length)
     {
-      nbyte = read (READ (fildes), buf, rc - i);
-      if (nbyte <= 0)
+      length = read (READ_SIDE (handle), buffer, (size_t) (status - counter));
+      if (length <= 0)
 	{
-	  _rmt_shutdown (fildes);
-	  errno = EIO;
+	  _rmt_shutdown (handle, EIO);
 	  return -1;
 	}
     }
 
-  return rc;
+  return status;
 }
 
-/* Write NBYTE bytes from BUF to remote tape connection FILDES.
-   Return the number of bytes written on success, -1 on error.  */
+/*-------------------------------------------------------------------------.
+| Write LENGTH bytes from BUFFER to remote tape connection HANDLE.  Return |
+| the number of bytes written on success, -1 on error.			   |
+`-------------------------------------------------------------------------*/
 
 int
-__rmt_write (fildes, buf, nbyte)
-     int fildes;
-     char *buf;
-     unsigned int nbyte;
+rmt_write__ (int handle, char *buffer, unsigned int length)
 {
-  char buffer[CMDBUFSIZE];
+  char command_buffer[COMMAND_BUFFER_SIZE];
   RETSIGTYPE (*pipe_handler) ();
 
-  sprintf (buffer, "W%d\n", nbyte);
-  if (command (fildes, buffer) == -1)
+  sprintf (command_buffer, "W%d\n", length);
+  if (do_command (handle, command_buffer) == -1)
     return -1;
 
   pipe_handler = signal (SIGPIPE, SIG_IGN);
-  if (write (WRITE (fildes), buf, nbyte) == nbyte)
+  if (write (WRITE_SIDE (handle), buffer, length) == length)
     {
       signal (SIGPIPE, pipe_handler);
-      return status (fildes);
+      return get_status (handle);
     }
 
   /* Write error.  */
+
   signal (SIGPIPE, pipe_handler);
-  _rmt_shutdown (fildes);
-  errno = EIO;
+  _rmt_shutdown (handle, EIO);
   return -1;
 }
 
-/* Perform an imitation lseek operation on remote tape connection FILDES.
-   Return the new file offset if successful, -1 if on error.  */
+/*------------------------------------------------------------------------.
+| Perform an imitation lseek operation on remote tape connection HANDLE.  |
+| Return the new file offset if successful, -1 if on error.		  |
+`------------------------------------------------------------------------*/
 
 long
-__rmt_lseek (fildes, offset, whence)
-     int fildes;
-     long offset;
-     int whence;
+rmt_lseek__ (int handle, off_t offset, int whence)
 {
-  char buffer[CMDBUFSIZE];
+  char command_buffer[COMMAND_BUFFER_SIZE];
 
-  sprintf (buffer, "L%ld\n%d\n", offset, whence);
-  if (command (fildes, buffer) == -1)
+  sprintf (command_buffer, "L%ld\n%d\n", offset, whence);
+  if (do_command (handle, command_buffer) == -1)
     return -1;
 
-  return status (fildes);
+  return get_status (handle);
 }
 
-/* Perform a raw tape operation on remote tape connection FILDES.
-   Return the results of the ioctl, or -1 on error.  */
+/*-----------------------------------------------------------------------.
+| Perform a raw tape operation on remote tape connection HANDLE.  Return |
+| the results of the ioctl, or -1 on error.				 |
+`-----------------------------------------------------------------------*/
 
-#ifdef MTIOCTOP
 int
-__rmt_ioctl (fildes, op, arg)
-     int fildes, op;
-     char *arg;
+rmt_ioctl__ (int handle, int operation, char *argument)
 {
-  char c;
-  int rc, cnt;
-  char buffer[CMDBUFSIZE];
-
-  switch (op)
+  switch (operation)
     {
     default:
-      errno = EINVAL;
+      errno = EOPNOTSUPP;	/* FIXME: errno should be read-only */
       return -1;
 
+#ifdef MTIOCTOP
     case MTIOCTOP:
-      /* MTIOCTOP is the easy one.  Nothing is transfered in binary.  */
-      sprintf (buffer, "I%d\n%d\n", ((struct mtop *) arg)->mt_op,
-	       ((struct mtop *) arg)->mt_count);
-      if (command (fildes, buffer) == -1)
-	return -1;
-      return status (fildes);	/* Return the count.  */
+      {
+	char command_buffer[COMMAND_BUFFER_SIZE];
 
+	/* MTIOCTOP is the easy one.  Nothing is transfered in binary.  */
+
+	sprintf (command_buffer, "I%d\n%d\n", ((struct mtop *) argument)->mt_op,
+		 ((struct mtop *) argument)->mt_count);
+	if (do_command (handle, command_buffer) == -1)
+	  return -1;
+
+	/* Return the count.  */
+
+	return get_status (handle);
+      }
+#endif /* MTIOCTOP */
+
+#ifdef MTIOCGET
     case MTIOCGET:
-      /* Grab the status and read it directly into the structure.
-	 This assumes that the status buffer is not padded
-	 and that 2 shorts fit in a long without any word
-	 alignment problems; i.e., the whole struct is contiguous.
-	 NOTE - this is probably NOT a good assumption.  */
+      {
+	int status;
+	int counter;
+
+	/* Grab the status and read it directly into the structure.  This
+	   assumes that the status buffer is not padded and that 2 shorts
+	   fit in a long without any word alignment problems; i.e., the
+	   whole struct is contiguous.  NOTE - this is probably NOT a good
+	   assumption.  */
+
+	if (do_command (handle, "S") == -1
+	    || (status = get_status (handle), status == -1))
+	  return -1;
 
-      if (command (fildes, "S") == -1 || (rc = status (fildes)) == -1)
-	return -1;
+	for (; status > 0; status -= counter, argument += counter)
+	  {
+	    counter = read (READ_SIDE (handle), argument, (size_t) status);
+	    if (counter <= 0)
+	      {
+		_rmt_shutdown (handle, EIO);
+		return -1;
+	      }
+	  }
 
-      for (; rc > 0; rc -= cnt, arg += cnt)
-	{
-	  cnt = read (READ (fildes), arg, rc);
-	  if (cnt <= 0)
-	    {
-	      _rmt_shutdown (fildes);
-	      errno = EIO;
-	      return -1;
-	    }
-	}
+	/* Check for byte position.  mt_type (or mt_model) is a small integer
+	   field (normally) so we will check its magnitude.  If it is larger
+	   than 256, we will assume that the bytes are swapped and go through
+	   and reverse all the bytes.  */
 
-      /* Check for byte position.  mt_type is a small integer field
-	 (normally) so we will check its magnitude.  If it is larger than
-	 256, we will assume that the bytes are swapped and go through
-	 and reverse all the bytes.  */
+	if (((struct mtget *) argument)->MTIO_CHECK_FIELD < 256)
+	  return 0;
 
-      if (((struct mtget *) arg)->mt_type < 256)
-	return 0;
+	for (counter = 0; counter < status; counter += 2)
+	  {
+	    char copy = argument[counter];
 
-      for (cnt = 0; cnt < rc; cnt += 2)
-	{
-	  c = arg[cnt];
-	  arg[cnt] = arg[cnt + 1];
-	  arg[cnt + 1] = c;
-	}
+	    argument[counter] = argument[counter + 1];
+	    argument[counter + 1] = copy;
+	  }
+
+	return 0;
+      }
+#endif /* MTIOCGET */
 
-      return 0;
     }
 }
-
-#endif
