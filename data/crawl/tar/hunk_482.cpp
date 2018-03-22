-/*
- * Copyright (c) 1983 Regents of the University of California.
- * All rights reserved.
- *
- * Redistribution and use in source and binary forms are permitted
- * provided that the above copyright notice and this paragraph are
- * duplicated in all such forms and that any documentation,
- * advertising materials, and other materials related to such
- * distribution and use acknowledge that the software was developed
- * by the University of California, Berkeley.  The name of the
- * University may not be used to endorse or promote products derived
- * from this software without specific prior written permission.
- * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
- * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
- * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
- */
-
-#ifndef lint
-char copyright[] =
-"@(#) Copyright (c) 1983 Regents of the University of California.\n\
- All rights reserved.\n";
-#endif /* not lint */
-
-/*
- * rmt
- */
-#include <stdio.h>
-#include <sgtty.h>
-#include <sys/types.h>
+/* Remote connection server.
+   Copyright (C) 1994, 1995, 1996 Free Software Foundation, Inc.
+
+   This program is free software; you can redistribute it and/or modify it
+   under the terms of the GNU General Public License as published by the
+   Free Software Foundation; either version 2, or (at your option) any later
+   version.
+
+   This program is distributed in the hope that it will be useful, but
+   WITHOUT ANY WARRANTY; without even the implied warranty of
+   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General
+   Public License for more details.
+
+   You should have received a copy of the GNU General Public License along
+   with this program; if not, write to the Free Software Foundation, Inc.,
+   59 Place - Suite 330, Boston, MA 02111-1307, USA.  */
+
+/* Copyright (C) 1983 Regents of the University of California.
+   All rights reserved.
+
+   Redistribution and use in source and binary forms are permitted provided
+   that the above copyright notice and this paragraph are duplicated in all
+   such forms and that any documentation, advertising materials, and other
+   materials related to such distribution and use acknowledge that the
+   software was developed by the University of California, Berkeley.  The
+   name of the University may not be used to endorse or promote products
+   derived from this software without specific prior written permission.
+   THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED
+   WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF
+   MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
+
+#include "system.h"
+
 #include <sys/socket.h>
-#ifdef HAVE_SYS_GENTAPE_H	/* e.g., ISC UNIX */
-#include <sys/gentape.h>
-#else
-#ifdef M_UNIX
-#include <sys/tape.h>
-#else
-#include <sys/mtio.h>
+
+#ifndef EXIT_FAILURE
+# define EXIT_FAILURE 1
 #endif
+#ifndef EXIT_SUCCESS
+# define EXIT_SUCCESS 0
 #endif
-#include <errno.h>
 
-#if defined (_I386) && defined (_AIX)
-#include <fcntl.h>
-#endif
+/* Maximum size of a string from the requesting program.  */
+#define	STRING_SIZE 64
 
-#ifdef HAVE_UNISTD_H
-#include <unistd.h>
-#else
-long lseek ();
-#endif
+/* Name of executing program.  */
+const char *program_name;
+
+/* File descriptor of the tape device, or negative if none open.  */
+static int tape = -1;
+
+/* Buffer containing transferred data, and its allocated size.  */
+static char *record_buffer = NULL;
+static int allocated_size = -1;
+
+/* Buffer for constructing the reply.  */
+static char reply_buffer[BUFSIZ];
+
+/* Debugging tools.  */
+
+static FILE *debug_file = NULL;
+
+#define	DEBUG(File) \
+  if (debug_file) fprintf(debug_file, File)
 
-#ifdef STDC_HEADERS
-#include <string.h>
-#include <stdlib.h>
+#define	DEBUG1(File, Arg) \
+  if (debug_file) fprintf(debug_file, File, Arg)
+
+#define	DEBUG2(File, Arg1, Arg2) \
+  if (debug_file) fprintf(debug_file, File, Arg1, Arg2)
+
+/*------------------------------------------------.
+| Return an error string, given an error number.  |
+`------------------------------------------------*/
+
+#if HAVE_STRERROR
+# ifndef strerror
+char *strerror ();
+# endif
 #else
-extern char *malloc ();
+static char *
+private_strerror (int errnum)
+{
+  extern const char *const sys_errlist[];
+  extern int sys_nerr;
+
+  if (errnum > 0 && errnum <= sys_nerr)
+    return sys_errlist[errnum];
+  return N_("Unknown system error");
+}
+# define strerror private_strerror
 #endif
 
-int tape = -1;
+/*---.
+| ?  |
+`---*/
+
+static void
+report_error_message (const char *string)
+{
+  DEBUG1 ("rmtd: E 0 (%s)\n", string);
+
+  sprintf (reply_buffer, "E0\n%s\n", string);
+  write (1, reply_buffer, strlen (reply_buffer));
+}
 
-char *record;
-int maxrecsize = -1;
-char *checkbuf ();
-void getstring ();
-void error ();
+/*---.
+| ?  |
+`---*/
 
-#define	SSIZE	64
-char device[SSIZE];
-char count[SSIZE], mode[SSIZE], pos[SSIZE], op[SSIZE];
+static void
+report_numbered_error (int num)
+{
+  DEBUG2 ("rmtd: E %d (%s)\n", num, strerror (num));
 
-extern errno;
-extern char *sys_errlist[];
-char resp[BUFSIZ];
+  sprintf (reply_buffer, "E%d\n%s\n", num, strerror (num));
+  write (1, reply_buffer, strlen (reply_buffer));
+}
 
-FILE *debug;
-#define	DEBUG(f)	if (debug) fprintf(debug, f)
-#define	DEBUG1(f,a)	if (debug) fprintf(debug, f, a)
-#define	DEBUG2(f,a1,a2)	if (debug) fprintf(debug, f, a1, a2)
+/*---.
+| ?  |
+`---*/
+
+static void
+get_string (char *string)
+{
+  int counter;
+
+  for (counter = 0; counter < STRING_SIZE; counter++)
+    {
+      if (read (0, string + counter, 1) != 1)
+	exit (EXIT_SUCCESS);
+
+      if (string[counter] == '\n')
+	break;
+    }
+  string[counter] = '\0';
+}
+
+/*---.
+| ?  |
+`---*/
+
+static void
+prepare_record_buffer (int size)
+{
+  if (size <= allocated_size)
+    return;
+
+  if (record_buffer)
+    free (record_buffer);
+
+  record_buffer = malloc ((size_t) size);
+
+  if (record_buffer == NULL)
+    {
+      DEBUG (_("rmtd: Cannot allocate buffer space\n"));
+
+      report_error_message (N_("Cannot allocate buffer space"));
+      exit (EXIT_FAILURE);      /* exit status used to be 4 */
+    }
+
+  allocated_size = size;
+
+#ifdef SO_RCVBUF
+  while (size > 1024 &&
+   setsockopt (0, SOL_SOCKET, SO_RCVBUF, (char *) &size, sizeof (size)) < 0)
+    size -= 1024;
+#else
+  /* FIXME: I do not see any purpose to the following line...  Sigh! */
+  size = 1 + ((size - 1) % 1024);
+#endif
+}
+
+/*---.
+| ?  |
+`---*/
 
 int
-main (argc, argv)
-     int argc;
-     char **argv;
+main (int argc, char *const *argv)
 {
-  int rval;
-  char c;
-  int n, i, cc;
+  char command;
+  int status;
+
+  /* FIXME: Localisation is meaningless, unless --help and --version are
+     locally used.  Localisation would be best accomplished by the calling
+     tar, on messages found within error packets.  */
+
+  program_name = argv[0];
+  setlocale (LC_ALL, "");
+  bindtextdomain (PACKAGE, LOCALEDIR);
+  textdomain (PACKAGE);
+
+  /* FIXME: Implement --help and --version as for any other GNU program.  */
 
   argc--, argv++;
   if (argc > 0)
     {
-      debug = fopen (*argv, "w");
-      if (debug == 0)
-	exit (1);
-      (void) setbuf (debug, (char *) 0);
+      debug_file = fopen (*argv, "w");
+      if (debug_file == 0)
+	{
+	  report_numbered_error (errno);
+	  exit (EXIT_FAILURE);
+	}
+      setbuf (debug_file, NULL);
     }
+
 top:
-  errno = 0;
-  rval = 0;
-  if (read (0, &c, 1) != 1)
-    exit (0);
-  switch (c)
+  errno = 0;			/* FIXME: errno should be read-only */
+  status = 0;
+  if (read (0, &command, 1) != 1)
+    exit (EXIT_SUCCESS);
+
+  switch (command)
     {
+      /* FIXME: Maybe 'H' and 'V' for --help and --version output?  */
 
     case 'O':
-      if (tape >= 0)
-	(void) close (tape);
-      getstring (device);
-      getstring (mode);
-      DEBUG2 ("rmtd: O %s %s\n", device, mode);
-#if defined (i386) && defined (AIX)
-      /* This is alleged to fix a byte ordering problem. */
-      /* I'm quite suspicious if it's right. -- mib */
       {
-	int oflag = atoi (mode);
-	int nflag = 0;
-	if ((oflag & 3) == 0)
-	  nflag |= O_RDONLY;
-	if (oflag & 1)
-	  nflag |= O_WRONLY;
-	if (oflag & 2)
-	  nflag |= O_RDWR;
-	if (oflag & 0x0008)
-	  nflag |= O_APPEND;
-	if (oflag & 0x0200)
-	  nflag |= O_CREAT;
-	if (oflag & 0x0400)
-	  nflag |= O_TRUNC;
-	if (oflag & 0x0800)
-	  nflag |= O_EXCL;
-	tape = open (device, nflag, 0666);
-      }
+	char device_string[STRING_SIZE];
+	char mode_string[STRING_SIZE];
+
+	get_string (device_string);
+	get_string (mode_string);
+	DEBUG2 ("rmtd: O %s %s\n", device_string, mode_string);
+
+	if (tape >= 0)
+	  close (tape);
+
+#if defined (i386) && defined (AIX)
+
+	/* This is alleged to fix a byte ordering problem.  I'm quite
+	   suspicious if it's right. -- mib.  */
+
+	{
+	  int old_mode = atoi (mode_string);
+	  int new_mode = 0;
+
+	  if ((old_mode & 3) == 0)
+	    new_mode |= O_RDONLY;
+	  if (old_mode & 1)
+	    new_mode |= O_WRONLY;
+	  if (old_mode & 2)
+	    new_mode |= O_RDWR;
+	  if (old_mode & 0x0008)
+	    new_mode |= O_APPEND;
+	  if (old_mode & 0x0200)
+	    new_mode |= O_CREAT;
+	  if (old_mode & 0x0400)
+	    new_mode |= O_TRUNC;
+	  if (old_mode & 0x0800)
+	    new_mode |= O_EXCL;
+	  tape = open (device_string, new_mode, 0666);
+	}
 #else
-      tape = open (device, atoi (mode), 0666);
+	tape = open (device_string, atoi (mode_string), 0666);
 #endif
-      if (tape < 0)
-	goto ioerror;
-      goto respond;
+	if (tape < 0)
+	  goto ioerror;
+	goto respond;
+      }
 
     case 'C':
-      DEBUG ("rmtd: C\n");
-      getstring (device);	/* discard */
-      if (close (tape) < 0)
-	goto ioerror;
-      tape = -1;
-      goto respond;
+      {
+	char device_string[STRING_SIZE];
+
+	get_string (device_string); /* discard */
+	DEBUG ("rmtd: C\n");
+
+	if (close (tape) < 0)
+	  goto ioerror;
+	tape = -1;
+	goto respond;
+      }
 
     case 'L':
-      getstring (count);
-      getstring (pos);
-      DEBUG2 ("rmtd: L %s %s\n", count, pos);
-      rval = lseek (tape, (long) atoi (count), atoi (pos));
-      if (rval < 0)
-	goto ioerror;
-      goto respond;
+      {
+	char count_string[STRING_SIZE];
+	char position_string[STRING_SIZE];
+
+	get_string (count_string);
+	get_string (position_string);
+	DEBUG2 ("rmtd: L %s %s\n", count_string, position_string);
+
+	status
+	  = lseek (tape, (off_t) atol (count_string), atoi (position_string));
+	if (status < 0)
+	  goto ioerror;
+	goto respond;
+      }
 
     case 'W':
-      getstring (count);
-      n = atoi (count);
-      DEBUG1 ("rmtd: W %s\n", count);
-      record = checkbuf (record, n);
-      for (i = 0; i < n; i += cc)
-	{
-	  cc = read (0, &record[i], n - i);
-	  if (cc <= 0)
-	    {
-	      DEBUG ("rmtd: premature eof\n");
-	      exit (2);
-	    }
-	}
-      rval = write (tape, record, n);
-      if (rval < 0)
-	goto ioerror;
-      goto respond;
+      {
+	char count_string[STRING_SIZE];
+	int size;
+	int counter;
 
-    case 'R':
-      getstring (count);
-      DEBUG1 ("rmtd: R %s\n", count);
-      n = atoi (count);
-      record = checkbuf (record, n);
-      rval = read (tape, record, n);
-      if (rval < 0)
-	goto ioerror;
-      (void) sprintf (resp, "A%d\n", rval);
-      (void) write (1, resp, strlen (resp));
-      (void) write (1, record, rval);
-      goto top;
+	get_string (count_string);
+	size = atoi (count_string);
+	DEBUG1 ("rmtd: W %s\n", count_string);
 
-    case 'I':
-      getstring (op);
-      getstring (count);
-      DEBUG2 ("rmtd: I %s %s\n", op, count);
-#ifdef MTIOCTOP
+	prepare_record_buffer (size);
+	for (counter = 0; counter < size; counter += status)
+	  {
+	    status = read (0, &record_buffer[counter], size - counter);
+	    if (status <= 0)
+	      {
+		DEBUG (_("rmtd: Premature eof\n"));
+
+		report_error_message (N_("Premature end of file"));
+		exit (EXIT_FAILURE); /* exit status used to be 2 */
+	      }
+	  }
+	status = write (tape, record_buffer, size);
+	if (status < 0)
+	  goto ioerror;
+	goto respond;
+      }
+
+    case 'R':
       {
-	struct mtop mtop;
-	mtop.mt_op = atoi (op);
-	mtop.mt_count = atoi (count);
-	if (ioctl (tape, MTIOCTOP, (char *) &mtop) < 0)
+	char count_string[STRING_SIZE];
+	int size;
+
+	get_string (count_string);
+	DEBUG1 ("rmtd: R %s\n", count_string);
+
+	size = atoi (count_string);
+	prepare_record_buffer (size);
+	status = read (tape, record_buffer, size);
+	if (status < 0)
 	  goto ioerror;
-	rval = mtop.mt_count;
+	sprintf (reply_buffer, "A%d\n", status);
+	write (1, reply_buffer, strlen (reply_buffer));
+	write (1, record_buffer, status);
+	goto top;
       }
+
+    case 'I':
+      {
+	char operation_string[STRING_SIZE];
+	char count_string[STRING_SIZE];
+
+	get_string (operation_string);
+	get_string  (count_string);
+	DEBUG2 ("rmtd: I %s %s\n", operation_string, count_string);
+
+#ifdef MTIOCTOP
+	{
+	  struct mtop mtop;
+
+	  mtop.mt_op = atoi (operation_string);
+	  mtop.mt_count = atoi (count_string);
+	  if (ioctl (tape, MTIOCTOP, (char *) &mtop) < 0)
+	    goto ioerror;
+	  status = mtop.mt_count;
+	}
 #endif
-      goto respond;
+	goto respond;
+      }
 
     case 'S':			/* status */
-      DEBUG ("rmtd: S\n");
       {
+	DEBUG ("rmtd: S\n");
+
 #ifdef MTIOCGET
-	struct mtget mtget;
-	if (ioctl (tape, MTIOCGET, (char *) &mtget) < 0)
-	  goto ioerror;
-	rval = sizeof (mtget);
-	(void) sprintf (resp, "A%d\n", rval);
-	(void) write (1, resp, strlen (resp));
-	(void) write (1, (char *) &mtget, sizeof (mtget));
+	{
+	  struct mtget operation;
+
+	  if (ioctl (tape, MTIOCGET, (char *) &operation) < 0)
+	    goto ioerror;
+	  status = sizeof (operation);
+	  sprintf (reply_buffer, "A%d\n", status);
+	  write (1, reply_buffer, strlen (reply_buffer));
+	  write (1, (char *) &operation, sizeof (operation));
+	}
 #endif
 	goto top;
       }
 
     default:
-      DEBUG1 ("rmtd: garbage command %c\n", c);
-      exit (3);
-    }
-respond:
-  DEBUG1 ("rmtd: A %d\n", rval);
-  (void) sprintf (resp, "A%d\n", rval);
-  (void) write (1, resp, strlen (resp));
-  goto top;
-ioerror:
-  error (errno);
-  goto top;
-}
-
-void
-getstring (bp)
-     char *bp;
-{
-  int i;
-  char *cp = bp;
+      DEBUG1 (_("rmtd: Garbage command %c\n"), command);
 
-  for (i = 0; i < SSIZE; i++)
-    {
-      if (read (0, cp + i, 1) != 1)
-	exit (0);
-      if (cp[i] == '\n')
-	break;
+      report_error_message (N_("Garbage command"));
+      exit (EXIT_FAILURE);	/* exit status used to be 3 */
     }
-  cp[i] = '\0';
-}
 
-char *
-checkbuf (record, size)
-     char *record;
-     int size;
-{
-  if (size <= maxrecsize)
-    return (record);
-  if (record != 0)
-    free (record);
-  record = malloc (size);
-  if (record == 0)
-    {
-      DEBUG ("rmtd: cannot allocate buffer space\n");
-      exit (4);
-    }
-  maxrecsize = size;
-#ifdef SO_RCVBUF
-  while (size > 1024 &&
-   setsockopt (0, SOL_SOCKET, SO_RCVBUF, (char *) &size, sizeof (size)) < 0)
-    size -= 1024;
-#else
-  size = 1 + ((size - 1) % 1024);
-#endif
-  return (record);
-}
+respond:
+  DEBUG1 ("rmtd: A %d\n", status);
 
-void
-error (num)
-     int num;
-{
+  sprintf (reply_buffer, "A%d\n", status);
+  write (1, reply_buffer, strlen (reply_buffer));
+  goto top;
 
-  DEBUG2 ("rmtd: E %d (%s)\n", num, sys_errlist[num]);
-  (void) sprintf (resp, "E%d\n%s\n", num, sys_errlist[num]);
-  (void) write (1, resp, strlen (resp));
+ioerror:
+  report_numbered_error (errno);
+  goto top;
 }
