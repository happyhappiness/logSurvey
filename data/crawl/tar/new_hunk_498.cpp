 * If the third argument is 1, the "saved" record # is used; if 0, the
 * "current" record # is used.
 */
void
anno (stream, prefix, savedp)
     FILE *stream;
     char *prefix;
     int savedp;
{
#	define	MAXANNO	50
  char buffer[MAXANNO];		/* Holds annorecment */
#	define	ANNOWIDTH 13
  int space;
  long offset;
  int save_e;

  save_e = errno;
  /* Make sure previous output gets out in sequence */
  if (stream == stderr)
    fflush (stdout);
  if (f_sayblock)
    {
      if (prefix)
	{
	  fputs (prefix, stream);
	  putc (' ', stream);
	}
      offset = ar_record - ar_block;
      (void) sprintf (buffer, "rec %d: ",
		      savedp ? saved_recno :
		      baserec + offset);
      fputs (buffer, stream);
      space = ANNOWIDTH - strlen (buffer);
      if (space > 0)
	{
	  fprintf (stream, "%*s", space, "");
	}
    }
  else if (prefix)
    {
      fputs (prefix, stream);
      fputs (": ", stream);
    }
  errno = save_e;
}

#endif

/* Called to initialize the global volume number. */
int
init_volume_number ()
{
  FILE *vf;

  vf = fopen (f_volno_file, "r");
  if (!vf && errno != ENOENT)
    msg_perror ("%s", f_volno_file);

  if (vf)
    {
      fscanf (vf, "%d", &global_volno);
      fclose (vf);
    }
}

/* Called to write out the closing global volume number. */
int
closeout_volume_number ()
{
  FILE *vf;

  vf = fopen (f_volno_file, "w");
  if (!vf)
    msg_perror ("%s", f_volno_file);
  else
    {
      fprintf (vf, "%d\n", global_volno);
      fclose (vf);
    }
}

/* We've hit the end of the old volume.  Close it and open the next one */
/* Values for type:  0: writing  1: reading  2: updating */
int
new_volume (type)
     int type;
{
  int c;
  char inbuf[80];
  char *p;
  static FILE *read_file = 0;
  extern int now_verifying;
  extern char TTY_NAME[];
  static int looped = 0;

  if (!read_file && !f_run_script_at_end)
    read_file = (archive == 0) ? fopen (TTY_NAME, "r") : stdin;

  if (now_verifying)
    return -1;
  if (f_verify)
    verify_volume ();
  if ((c = rmtclose (archive)) < 0)
    msg_perror ("Warning: can't close %s(%d,%d)", ar_files[cur_ar_file], archive, c);

  global_volno++;
  volno++;
  cur_ar_file++;
  if (cur_ar_file == n_ar_files)
    {
      cur_ar_file = 0;
      looped = 1;
    }

tryagain:
  if (looped)
    {
      /* We have to prompt from now on. */
      if (f_run_script_at_end)
	system (info_script);
      else
	for (;;)
	  {
	    fprintf (msg_file, "\007Prepare volume #%d for %s and hit return: ", global_volno, ar_files[cur_ar_file]);
	    fflush (msg_file);
	    if (fgets (inbuf, sizeof (inbuf), read_file) == 0)
	      {
		fprintf (msg_file, "EOF?  What does that mean?");
		if (cmd_mode != CMD_EXTRACT && cmd_mode != CMD_LIST && cmd_mode != CMD_DIFF)
		  msg ("Warning:  Archive is INCOMPLETE!");
		exit (EX_BADARCH);
	      }
	    if (inbuf[0] == '\n' || inbuf[0] == 'y' || inbuf[0] == 'Y')
	      break;

	    switch (inbuf[0])
	      {
	      case '?':
		{
		  fprintf (msg_file, "\
 n [name]   Give a new filename for the next (and subsequent) volume(s)\n\
 q          Abort tar\n\
 !          Spawn a subshell\n\
 ?          Print this list\n");
		}
		break;

	      case 'q':	/* Quit */
		fprintf (msg_file, "No new volume; exiting.\n");
		if (cmd_mode != CMD_EXTRACT && cmd_mode != CMD_LIST && cmd_mode != CMD_DIFF)
		  msg ("Warning:  Archive is INCOMPLETE!");
		exit (EX_BADARCH);

	      case 'n':	/* Get new file name */
		{
		  char *q, *r;
		  static char *old_name;

		  for (q = &inbuf[1]; *q == ' ' || *q == '\t'; q++)
		    ;
		  for (r = q; *r; r++)
		    if (*r == '\n')
		      *r = '\0';
		  old_name = p = (char *) malloc ((unsigned) (strlen (q) + 2));
		  if (p == 0)
		    {
		      msg ("Can't allocate memory for name");
		      exit (EX_SYSTEM);
		    }
		  (void) strcpy (p, q);
		  ar_files[cur_ar_file] = p;
		}
		break;

	      case '!':
#ifdef __MSDOS__
		spawnl (P_WAIT, getenv ("COMSPEC"), "-", 0);
#else
		/* JF this needs work! */
		switch (fork ())
		  {
		  case -1:
		    msg_perror ("can't fork!");
		    break;
		  case 0:
		    p = getenv ("SHELL");
		    if (p == 0)
		      p = "/bin/sh";
		    execlp (p, "-sh", "-i", 0);
		    msg_perror ("can't exec a shell %s", p);
		    _exit (55);
		  default:
		    wait (0);
		    break;
		  }
#endif
		break;
	      }
	  }
    }


  if (type == 2 || f_verify)
    archive = rmtopen (ar_files[cur_ar_file], O_RDWR | O_CREAT, 0666);
  else if (type == 1)
    archive = rmtopen (ar_files[cur_ar_file], O_RDONLY, 0666);
  else if (type == 0)
    archive = rmtcreat (ar_files[cur_ar_file], 0666);
  else
    archive = -1;

  if (archive < 0)
    {
      msg_perror ("can't open %s", ar_files[cur_ar_file]);
      goto tryagain;
    }
#ifdef __MSDOS__
  setmode (archive, O_BINARY);
#endif
  return 0;
}

/* this is a useless function that takes a buffer returned by wantbytes
   and does nothing with it.  If the function called by wantbytes returns
   an error indicator (non-zero), this function is called for the rest of
   the file.
 */
int
no_op (size, data)
     int size;
     char *data;
{
  return 0;
}

/* Some other routine wants SIZE bytes in the archive.  For each chunk of
   the archive, call FUNC with the size of the chunk, and the address of
   the chunk it can work with.
 */
int
wantbytes (size, func)
     long size;
     int (*func) ();
{
  char *data;
  long data_size;

  while (size)
    {
      data = findrec ()->charptr;
      if (data == NULL)
	{			/* Check it... */
	  msg ("Unexpected EOF on archive file");
	  return -1;
	}
      data_size = endofrecs ()->charptr - data;
      if (data_size > size)
	data_size = size;
      if ((*func) (data_size, data))
	func = no_op;
      userec ((union record *) (data + data_size - 1));
      size -= data_size;
    }
  return 0;
}
