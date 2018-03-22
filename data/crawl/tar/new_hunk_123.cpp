   0 up to TAR_INCREMENTAL_VERSION, inclusive.
   It is able to create only snapshots of TAR_INCREMENTAL_VERSION */

#define TAR_INCREMENTAL_VERSION 2

/* Read incremental snapshot formats 0 and 1 */
static void
read_incr_db_01 (int version, const char *initbuf)
{
  int n;
  uintmax_t u;
  time_t t = u;
  char *buf = 0;
  size_t bufsize;
  char *ebuf;
  long lineno = 1;

  if (version == 1)
    {
      if (getline (&buf, &bufsize, listed_incremental_stream) <= 0)
	{
	  read_error (listed_incremental_option);
	  free (buf);
	  return;
	}
      ++lineno;
    }
  else
    {
      buf = strdup (initbuf);
      bufsize = strlen (buf) + 1;
    }
  
  t = u = (errno = 0, strtoumax (buf, &ebuf, 10));
  if (buf == ebuf || (u == 0 && errno == EINVAL))
    ERROR ((0, 0, "%s:%ld: %s",
	    quotearg_colon (listed_incremental_option),
	    lineno,
	    _("Invalid time stamp")));
  else if (t != u)
    ERROR ((0, 0, "%s:%ld: %s",
	    quotearg_colon (listed_incremental_option),
	    lineno,
	    _("Time stamp out of range")));
  else if (version == 1)
    {
      newer_mtime_option.tv_sec = t;

      t = u = (errno = 0, strtoumax (buf, &ebuf, 10));
      if (buf == ebuf || (u == 0 && errno == EINVAL))
	ERROR ((0, 0, "%s:%ld: %s",
		quotearg_colon (listed_incremental_option),
		lineno,
		_("Invalid time stamp")));
      else if (t != u)
	ERROR ((0, 0, "%s:%ld: %s",
		quotearg_colon (listed_incremental_option),
		lineno,
		_("Time stamp out of range")));
      newer_mtime_option.tv_nsec = t;
    }
  else
    {
      /* pre-1 incremental format does not contain nanoseconds */
      newer_mtime_option.tv_sec = t;
      newer_mtime_option.tv_nsec = 0;
    }

  while (0 < (n = getline (&buf, &bufsize, listed_incremental_stream)))
    {
      dev_t dev;
      ino_t ino;
      bool nfs = buf[0] == '+';
      char *strp = buf + nfs;
      struct timespec mtime;
      
      lineno++;
      
      if (buf[n - 1] == '\n')
	buf[n - 1] = '\0';
      
      if (version == 1)
	{
	  errno = 0;
	  mtime.tv_sec = u = strtoumax (strp, &ebuf, 10);
	  if (!isspace (*ebuf))
	    ERROR ((0, 0, "%s:%ld: %s",
		    quotearg_colon (listed_incremental_option), lineno,
		    _("Invalid modification time (seconds)")));
	  else if (mtime.tv_sec != u)
	    ERROR ((0, 0, "%s:%ld: %s",
		    quotearg_colon (listed_incremental_option), lineno,
		    _("Modification time (seconds) out of range")));
	  strp = ebuf;
	  
	  errno = 0;
	  mtime.tv_nsec = u = strtoumax (strp, &ebuf, 10);
	  if (!isspace (*ebuf))
	    ERROR ((0, 0, "%s:%ld: %s",
		    quotearg_colon (listed_incremental_option), lineno,
		    _("Invalid modification time (nanoseconds)")));
	  else if (mtime.tv_nsec != u)
	    ERROR ((0, 0, "%s:%ld: %s",
		    quotearg_colon (listed_incremental_option), lineno,
		    _("Modification time (nanoseconds) out of range")));
	  strp = ebuf;
	}
      else
	memset (&mtime, 0, sizeof mtime);
      
      errno = 0;
      dev = u = strtoumax (strp, &ebuf, 10);
      if (!isspace (*ebuf))
	ERROR ((0, 0, "%s:%ld: %s",
		quotearg_colon (listed_incremental_option), lineno,
		_("Invalid device number")));
      else if (dev != u)
	ERROR ((0, 0, "%s:%ld: %s",
		quotearg_colon (listed_incremental_option), lineno,
		_("Device number out of range")));
      strp = ebuf;

      errno = 0;
      ino = u = strtoumax (strp, &ebuf, 10);
      if (!isspace (*ebuf))
	ERROR ((0, 0, "%s:%ld: %s",
		quotearg_colon (listed_incremental_option), lineno,
		_("Invalid inode number")));
      else if (ino != u)
	ERROR ((0, 0, "%s:%ld: %s",
		quotearg_colon (listed_incremental_option), lineno,
		_("Inode number out of range")));
      strp = ebuf;
      
      strp++;
      unquote_string (strp);
      note_directory (strp, mtime, dev, ino, nfs, false, NULL);
    }
  free (buf);
}

/* Read a nul-terminated string from FP and store it in STK.
   Store the number of bytes read (including nul terminator) in PCOUNT.

   Return the last character read or EOF on end of file. */
static int
read_obstack (FILE *fp, struct obstack *stk, size_t *pcount)
{
  int c;
  size_t i;

  for (i = 0, c = getc (fp); c != EOF && c != 0; c = getc (fp), i++)
    obstack_1grow (stk, c);
  obstack_1grow (stk, 0);

  *pcount = i;
  return c;
}

/* Read from file FP a nul-terminated string and convert it to
   uintmax_t. Return the resulting value in PVAL.

   Throw fatal error if the string cannot be converted.
   
   Return the last character read or EOF on end of file. */

static int
read_num (FILE *fp, uintmax_t *pval)
{
  int c;
  size_t i;
  char buf[UINTMAX_STRSIZE_BOUND], *ep;

  for (i = 0, c = getc (fp); c != EOF && c != 0; c = getc (fp), i++)
    {
      if (i == sizeof buf - 1)
	FATAL_ERROR ((0, 0, _("Field too long while reading snapshot file")));
      buf[i] = c;
    }
  buf[i] = 0;
  *pval = strtoumax (buf, &ep, 10);
  if (*ep)
    FATAL_ERROR ((0, 0, _("Unexpected field value in snapshot file")));
  return c;
}  

/* Read incremental snapshot format 2 */
static void
read_incr_db_2 ()
{
  uintmax_t u;
  struct obstack stk;
  
  obstack_init (&stk);

  if (read_num (listed_incremental_stream, &u))
    FATAL_ERROR ((0, 0, "%s: %s",
		  quotearg_colon (listed_incremental_option), 
		  _("Error reading time stamp")));
  newer_mtime_option.tv_sec = u;
  if (newer_mtime_option.tv_sec != u)
    FATAL_ERROR ((0, 0, "%s: %s",
		  quotearg_colon (listed_incremental_option),
		  _("Time stamp out of range")));

  if (read_num (listed_incremental_stream, &u))
    FATAL_ERROR ((0, 0, "%s: %s",
		  quotearg_colon (listed_incremental_option), 
		  _("Error reading time stamp")));
  newer_mtime_option.tv_nsec = u;
  if (newer_mtime_option.tv_nsec != u)
    FATAL_ERROR ((0, 0, "%s: %s",
		  quotearg_colon (listed_incremental_option),
		  _("Time stamp out of range")));

  for (;;)
    {
      struct timespec mtime;
      dev_t dev;
      ino_t ino;
      bool nfs;
      char *name;
      char *content;
      size_t s;
      
      if (read_num (listed_incremental_stream, &u))
	return; /* Normal return */

      nfs = u;
      
      if (read_num (listed_incremental_stream, &u))
	break;
      mtime.tv_sec = u;
      if (mtime.tv_sec != u)
	FATAL_ERROR ((0, 0, "%s: %s",
		      quotearg_colon (listed_incremental_option), 
		      _("Modification time (seconds) out of range")));
      
      if (read_num (listed_incremental_stream, &u))
	break;
      mtime.tv_nsec = u;
      if (mtime.tv_nsec != u)
	FATAL_ERROR ((0, 0, "%s: %s",
		      quotearg_colon (listed_incremental_option), 
		      _("Modification time (nanoseconds) out of range")));

      if (read_num (listed_incremental_stream, &u))
	break;
      dev = u;
      if (dev != u)
	FATAL_ERROR ((0, 0, "%s: %s",
		      quotearg_colon (listed_incremental_option), 
		      _("Device number out of range")));

      if (read_num (listed_incremental_stream, &u))
	break;
      ino = u;
      if (ino != u)
	FATAL_ERROR ((0, 0, "%s: %s",
		      quotearg_colon (listed_incremental_option), 
		      _("Inode number out of range")));

      if (read_obstack (listed_incremental_stream, &stk, &s))
	break;

      name = obstack_finish (&stk);

      while (read_obstack (listed_incremental_stream, &stk, &s) == 0 && s > 1)
	;
      if (getc (listed_incremental_stream) != 0)
	FATAL_ERROR ((0, 0, "%s: %s",
		      quotearg_colon (listed_incremental_option), 
		      _("Missing record terminator")));
      
      content = obstack_finish (&stk);
      note_directory (name, mtime, dev, ino, nfs, false, content);
      obstack_free (&stk, content);
    }
  FATAL_ERROR ((0, 0, "%s: %s",
		quotearg_colon (listed_incremental_option), 
		_("Unexpected EOF")));
}

/* Read incremental snapshot file (directory file).
   If the file has older incremental version, make sure that it is processed
