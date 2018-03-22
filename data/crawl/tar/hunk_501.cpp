 #ifdef HAVE_UNISTD_H
 #include <unistd.h>
 #else
-long	lseek();
+long lseek ();
 #endif
 
 #ifdef STDC_HEADERS
 #include <string.h>
 #include <stdlib.h>
 #else
-extern char *malloc();
+extern char *malloc ();
 #endif
 
-int	tape = -1;
+int tape = -1;
 
-char	*record;
-int	maxrecsize = -1;
-char	*checkbuf();
-void	getstring();
-void	error();
+char *record;
+int maxrecsize = -1;
+char *checkbuf ();
+void getstring ();
+void error ();
 
 #define	SSIZE	64
-char	device[SSIZE];
-char	count[SSIZE], mode[SSIZE], pos[SSIZE], op[SSIZE];
+char device[SSIZE];
+char count[SSIZE], mode[SSIZE], pos[SSIZE], op[SSIZE];
 
-extern	errno;
-extern char	*sys_errlist[];
-char	resp[BUFSIZ];
+extern errno;
+extern char *sys_errlist[];
+char resp[BUFSIZ];
 
-FILE	*debug;
+FILE *debug;
 #define	DEBUG(f)	if (debug) fprintf(debug, f)
 #define	DEBUG1(f,a)	if (debug) fprintf(debug, f, a)
 #define	DEBUG2(f,a1,a2)	if (debug) fprintf(debug, f, a1, a2)
 
 int
-main(argc, argv)
-	int argc;
-	char **argv;
+main (argc, argv)
+     int argc;
+     char **argv;
 {
-	int rval;
-	char c;
-	int n, i, cc;
+  int rval;
+  char c;
+  int n, i, cc;
 
-	argc--, argv++;
-	if (argc > 0) {
-		debug = fopen(*argv, "w");
-		if (debug == 0)
-			exit(1);
-		(void) setbuf(debug, (char *)0);
-	}
+  argc--, argv++;
+  if (argc > 0)
+    {
+      debug = fopen (*argv, "w");
+      if (debug == 0)
+	exit (1);
+      (void) setbuf (debug, (char *) 0);
+    }
 top:
-	errno = 0;
-	rval = 0;
-	if (read(0, &c, 1) != 1)
-		exit(0);
-	switch (c) {
+  errno = 0;
+  rval = 0;
+  if (read (0, &c, 1) != 1)
+    exit (0);
+  switch (c)
+    {
 
-	case 'O':
-		if (tape >= 0)
-			(void) close(tape);
-		getstring(device); getstring(mode);
-		DEBUG2("rmtd: O %s %s\n", device, mode);
+    case 'O':
+      if (tape >= 0)
+	(void) close (tape);
+      getstring (device);
+      getstring (mode);
+      DEBUG2 ("rmtd: O %s %s\n", device, mode);
 #if defined (i386) && defined (AIX)
-		/* This is alleged to fix a byte ordering problem. */
-		/* I'm quite suspicious if it's right. -- mib */
-		{
-		  int oflag = atoi (mode);
-		  int nflag = 0;
-		  if ((oflag & 3) == 0)
-		    nflag |= O_RDONLY;
-		  if (oflag & 1)
-		    nflag |= O_WRONLY;
-		  if (oflag & 2)
-		    nflag |= O_RDWR;
-		  if (oflag & 0x0008)
-		    nflag |= O_APPEND;
-		  if (oflag & 0x0200)
-		    nflag |= O_CREAT;
-		  if (oflag & 0x0400)
-		    nflag |= O_TRUNC;
-		  if (oflag & 0x0800)
-		    nflag |= O_EXCL;
-		  tape = open (device, nflag, 0666);
-		}
-#else		
-		tape = open(device, atoi(mode),0666);
+      /* This is alleged to fix a byte ordering problem. */
+      /* I'm quite suspicious if it's right. -- mib */
+      {
+	int oflag = atoi (mode);
+	int nflag = 0;
+	if ((oflag & 3) == 0)
+	  nflag |= O_RDONLY;
+	if (oflag & 1)
+	  nflag |= O_WRONLY;
+	if (oflag & 2)
+	  nflag |= O_RDWR;
+	if (oflag & 0x0008)
+	  nflag |= O_APPEND;
+	if (oflag & 0x0200)
+	  nflag |= O_CREAT;
+	if (oflag & 0x0400)
+	  nflag |= O_TRUNC;
+	if (oflag & 0x0800)
+	  nflag |= O_EXCL;
+	tape = open (device, nflag, 0666);
+      }
+#else
+      tape = open (device, atoi (mode), 0666);
 #endif
-		if (tape < 0)
-			goto ioerror;
-		goto respond;
+      if (tape < 0)
+	goto ioerror;
+      goto respond;
 
-	case 'C':
-		DEBUG("rmtd: C\n");
-		getstring(device);		/* discard */
-		if (close(tape) < 0)
-			goto ioerror;
-		tape = -1;
-		goto respond;
+    case 'C':
+      DEBUG ("rmtd: C\n");
+      getstring (device);	/* discard */
+      if (close (tape) < 0)
+	goto ioerror;
+      tape = -1;
+      goto respond;
 
-	case 'L':
-		getstring(count); getstring(pos);
-		DEBUG2("rmtd: L %s %s\n", count, pos);
-		rval = lseek(tape, (long) atoi(count), atoi(pos));
-		if (rval < 0)
-			goto ioerror;
-		goto respond;
+    case 'L':
+      getstring (count);
+      getstring (pos);
+      DEBUG2 ("rmtd: L %s %s\n", count, pos);
+      rval = lseek (tape, (long) atoi (count), atoi (pos));
+      if (rval < 0)
+	goto ioerror;
+      goto respond;
 
-	case 'W':
-		getstring(count);
-		n = atoi(count);
-		DEBUG1("rmtd: W %s\n", count);
-		record = checkbuf(record, n);
-		for (i = 0; i < n; i += cc) {
-			cc = read(0, &record[i], n - i);
-			if (cc <= 0) {
-				DEBUG("rmtd: premature eof\n");
-				exit(2);
-			}
-		}
-		rval = write(tape, record, n);
-		if (rval < 0)
-			goto ioerror;
-		goto respond;
+    case 'W':
+      getstring (count);
+      n = atoi (count);
+      DEBUG1 ("rmtd: W %s\n", count);
+      record = checkbuf (record, n);
+      for (i = 0; i < n; i += cc)
+	{
+	  cc = read (0, &record[i], n - i);
+	  if (cc <= 0)
+	    {
+	      DEBUG ("rmtd: premature eof\n");
+	      exit (2);
+	    }
+	}
+      rval = write (tape, record, n);
+      if (rval < 0)
+	goto ioerror;
+      goto respond;
 
-	case 'R':
-		getstring(count);
-		DEBUG1("rmtd: R %s\n", count);
-		n = atoi(count);
-		record = checkbuf(record, n);
-		rval = read(tape, record, n);
-		if (rval < 0)
-			goto ioerror;
-		(void) sprintf(resp, "A%d\n", rval);
-		(void) write(1, resp, strlen(resp));
-		(void) write(1, record, rval);
-		goto top;
+    case 'R':
+      getstring (count);
+      DEBUG1 ("rmtd: R %s\n", count);
+      n = atoi (count);
+      record = checkbuf (record, n);
+      rval = read (tape, record, n);
+      if (rval < 0)
+	goto ioerror;
+      (void) sprintf (resp, "A%d\n", rval);
+      (void) write (1, resp, strlen (resp));
+      (void) write (1, record, rval);
+      goto top;
 
-	case 'I':
-		getstring(op); getstring(count);
-		DEBUG2("rmtd: I %s %s\n", op, count);
+    case 'I':
+      getstring (op);
+      getstring (count);
+      DEBUG2 ("rmtd: I %s %s\n", op, count);
 #ifdef MTIOCTOP
-		{ struct mtop mtop;
-		  mtop.mt_op = atoi(op);
-		  mtop.mt_count = atoi(count);
-		  if (ioctl(tape, MTIOCTOP, (char *)&mtop) < 0)
-			goto ioerror;
-		  rval = mtop.mt_count;
-		}
+      {
+	struct mtop mtop;
+	mtop.mt_op = atoi (op);
+	mtop.mt_count = atoi (count);
+	if (ioctl (tape, MTIOCTOP, (char *) &mtop) < 0)
+	  goto ioerror;
+	rval = mtop.mt_count;
+      }
 #endif
-		goto respond;
+      goto respond;
 
-	case 'S':		/* status */
-		DEBUG("rmtd: S\n");
-		{
+    case 'S':			/* status */
+      DEBUG ("rmtd: S\n");
+      {
 #ifdef MTIOCGET
-		  struct mtget mtget;
-		  if (ioctl(tape, MTIOCGET, (char *)&mtget) < 0)
-			goto ioerror;
-		  rval = sizeof (mtget);
-		  (void) sprintf(resp, "A%d\n", rval);
-		  (void) write(1, resp, strlen(resp));
-		  (void) write(1, (char *)&mtget, sizeof (mtget));
+	struct mtget mtget;
+	if (ioctl (tape, MTIOCGET, (char *) &mtget) < 0)
+	  goto ioerror;
+	rval = sizeof (mtget);
+	(void) sprintf (resp, "A%d\n", rval);
+	(void) write (1, resp, strlen (resp));
+	(void) write (1, (char *) &mtget, sizeof (mtget));
 #endif
-		  goto top;
-		}
+	goto top;
+      }
 
-	default:
-		DEBUG1("rmtd: garbage command %c\n", c);
-		exit(3);
-	}
+    default:
+      DEBUG1 ("rmtd: garbage command %c\n", c);
+      exit (3);
+    }
 respond:
-	DEBUG1("rmtd: A %d\n", rval);
-	(void) sprintf(resp, "A%d\n", rval);
-	(void) write(1, resp, strlen(resp));
-	goto top;
+  DEBUG1 ("rmtd: A %d\n", rval);
+  (void) sprintf (resp, "A%d\n", rval);
+  (void) write (1, resp, strlen (resp));
+  goto top;
 ioerror:
-	error(errno);
-	goto top;
+  error (errno);
+  goto top;
 }
 
 void
-getstring(bp)
-	char *bp;
+getstring (bp)
+     char *bp;
 {
-	int i;
-	char *cp = bp;
+  int i;
+  char *cp = bp;
 
-	for (i = 0; i < SSIZE; i++) {
-		if (read(0, cp+i, 1) != 1)
-			exit(0);
-		if (cp[i] == '\n')
-			break;
-	}
-	cp[i] = '\0';
+  for (i = 0; i < SSIZE; i++)
+    {
+      if (read (0, cp + i, 1) != 1)
+	exit (0);
+      if (cp[i] == '\n')
+	break;
+    }
+  cp[i] = '\0';
 }
 
 char *
-checkbuf(record, size)
-	char *record;
-	int size;
+checkbuf (record, size)
+     char *record;
+     int size;
 {
-	if (size <= maxrecsize)
-		return (record);
-	if (record != 0)
-		free(record);
-	record = malloc(size);
-	if (record == 0) {
-		DEBUG("rmtd: cannot allocate buffer space\n");
-		exit(4);
-	}
-	maxrecsize = size;
+  if (size <= maxrecsize)
+    return (record);
+  if (record != 0)
+    free (record);
+  record = malloc (size);
+  if (record == 0)
+    {
+      DEBUG ("rmtd: cannot allocate buffer space\n");
+      exit (4);
+    }
+  maxrecsize = size;
 #ifdef SO_RCVBUF
-	while (size > 1024 &&
-	       setsockopt(0, SOL_SOCKET, SO_RCVBUF, (char *)&size, sizeof (size)) < 0)
-		size -= 1024;
+  while (size > 1024 &&
+   setsockopt (0, SOL_SOCKET, SO_RCVBUF, (char *) &size, sizeof (size)) < 0)
+    size -= 1024;
 #else
-	size= 1+((size-1)%1024);
+  size = 1 + ((size - 1) % 1024);
 #endif
-	return (record);
+  return (record);
 }
 
 void
-error(num)
-	int num;
+error (num)
+     int num;
 {
 
-	DEBUG2("rmtd: E %d (%s)\n", num, sys_errlist[num]);
-	(void) sprintf(resp, "E%d\n%s\n", num, sys_errlist[num]);
-	(void) write(1, resp, strlen (resp));
+  DEBUG2 ("rmtd: E %d (%s)\n", num, sys_errlist[num]);
+  (void) sprintf (resp, "E%d\n%s\n", num, sys_errlist[num]);
+  (void) write (1, resp, strlen (resp));
 }
