    }
}

/* Handle write errors on the archive.  Write errors are always fatal */
/* Hitting the end of a volume does not cause a write error unless the write
*  was the first block of the volume */

void
writeerror (err)
     int err;
{
  if (err < 0)
    {
      msg_perror ("can't write to %s", ar_files[cur_ar_file]);
      exit (EX_BADARCH);
    }
  else
    {
      msg ("only wrote %u of %u bytes to %s", err, blocksize, ar_files[cur_ar_file]);
      exit (EX_BADARCH);
    }
}

/*
 * Handle read errors on the archive.
 *
 * If the read should be retried, readerror() returns to the caller.
 */
void
readerror ()
{
#	define	READ_ERROR_MAX	10

  read_error_flag++;		/* Tell callers */

  msg_perror ("read error on %s", ar_files[cur_ar_file]);

  if (baserec == 0)
    {
      /* First block of tape.  Probably stupidity error */
      exit (EX_BADARCH);
    }

  /*
	 * Read error in mid archive.  We retry up to READ_ERROR_MAX times
	 * and then give up on reading the archive.  We set read_error_flag
	 * for our callers, so they can cope if they want.
	 */
  if (r_error_count++ > READ_ERROR_MAX)
    {
      msg ("Too many errors, quitting.");
      exit (EX_BADARCH);
    }
  return;
}


/*
 * Perform a read to flush the buffer.
 */
void
fl_read ()
{
  int err;			/* Result from system call */
  int left;			/* Bytes left */
  char *more;			/* Pointer to next byte to read */

  if (f_checkpoint && !(++checkpoint % 10))
    msg ("Read checkpoint %d\n", checkpoint);

  /*
	 * Clear the count of errors.  This only applies to a single
	 * call to fl_read.  We leave read_error_flag alone; it is
	 * only turned off by higher level software.
	 */
  r_error_count = 0;		/* Clear error count */

  /*
	 * If we are about to wipe out a record that
	 * somebody needs to keep, copy it out to a holding
	 * area and adjust somebody's pointer to it.
	 */
  if (save_rec &&
      *save_rec >= ar_record &&
      *save_rec < ar_last)
    {
      record_save_area = **save_rec;
      *save_rec = &record_save_area;
    }
  if (write_archive_to_stdout && baserec != 0)
    {
      err = rmtwrite (1, ar_block->charptr, blocksize);
      if (err != blocksize)
	writeerror (err);
    }
  if (f_multivol)
    {
      if (save_name)
	{
	  if (save_name != real_s_name)
	    {
#ifdef __MSDOS__
	      if (save_name[1] == ':')
		save_name += 2;
#endif
	      while (*save_name == '/')
		save_name++;

	      strcpy (real_s_name, save_name);
	      save_name = real_s_name;
	    }
	  real_s_totsize = save_totsize;
	  real_s_sizeleft = save_sizeleft;

	}
      else
	{
	  real_s_name[0] = '\0';
	  real_s_totsize = 0;
	  real_s_sizeleft = 0;
	}
    }

error_loop:
  err = rmtread (archive, ar_block->charptr, (int) blocksize);
  if (err == blocksize)
    return;

  if ((err == 0 || (err < 0 && errno == ENOSPC) || (err > 0 && !f_reblock)) && f_multivol)
    {
      union record *head;

    try_volume:
      if (new_volume ((cmd_mode == CMD_APPEND || cmd_mode == CMD_CAT || cmd_mode == CMD_UPDATE) ? 2 : 1) < 0)
	return;
    vol_error:
      err = rmtread (archive, ar_block->charptr, (int) blocksize);
      if (err < 0)
	{
	  readerror ();
	  goto vol_error;
	}
      if (err != blocksize)
	goto short_read;

      head = ar_block;

      if (head->header.linkflag == LF_VOLHDR)
	{
	  if (f_volhdr)
	    {
#if 0
	      char *ptr;

	      ptr = (char *) malloc (strlen (f_volhdr) + 20);
	      sprintf (ptr, "%s Volume %d", f_volhdr, volno);
#endif
	      if (re_match (label_pattern, head->header.arch_name,
			    strlen (head->header.arch_name),
			    0, 0) < 0)
		{
		  msg ("Volume mismatch! %s!=%s", f_volhdr,
		       head->header.arch_name);
		  --volno;
		  --global_volno;
		  goto try_volume;
		}

#if 0
	      if (strcmp (ptr, head->header.name))
		{
		  msg ("Volume mismatch! %s!=%s", ptr, head->header.name);
		  --volno;
		  --global_volno;
		  free (ptr);
		  goto try_volume;
		}
	      free (ptr);
#endif
	    }
	  if (f_verbose)
	    fprintf (msg_file, "Reading %s\n", head->header.arch_name);
	  head++;
	}
      else if (f_volhdr)
	{
	  msg ("Warning:  No volume header!");
	}

      if (real_s_name[0])
	{
	  long from_oct ();

	  if (head->header.linkflag != LF_MULTIVOL || strcmp (head->header.arch_name, real_s_name))
	    {
	      msg ("%s is not continued on this volume!", real_s_name);
	      --volno;
	      --global_volno;
	      goto try_volume;
	    }
	  if (real_s_totsize != from_oct (1 + 12, head->header.size) + from_oct (1 + 12, head->header.offset))
	    {
	      msg ("%s is the wrong size (%ld!=%ld+%ld)",
		   head->header.arch_name, save_totsize,
		   from_oct (1 + 12, head->header.size),
		   from_oct (1 + 12, head->header.offset));
	      --volno;
	      --global_volno;
	      goto try_volume;
	    }
	  if (real_s_totsize - real_s_sizeleft != from_oct (1 + 12, head->header.offset))
	    {
	      msg ("This volume is out of sequence");
	      --volno;
	      --global_volno;
	      goto try_volume;
	    }
	  head++;
	}
      ar_record = head;
      return;
    }
  else if (err < 0)
    {
      readerror ();
      goto error_loop;		/* Try again */
    }

short_read:
  more = ar_block->charptr + err;
  left = blocksize - err;

again:
  if (0 == (((unsigned) left) % RECORDSIZE))
    {
      /* FIXME, for size=0, multi vol support */
      /* On the first block, warn about the problem */
      if (!f_reblock && baserec == 0 && f_verbose && err > 0)
	{
	  /*	msg("Blocksize = %d record%s",
				err / RECORDSIZE, (err > RECORDSIZE)? "s": "");*/
	  msg ("Blocksize = %d records", err / RECORDSIZE);
	}
      ar_last = ar_block + ((unsigned) (blocksize - left)) / RECORDSIZE;
      return;
    }
  if (f_reblock)
    {
      /*
		 * User warned us about this.  Fix up.
		 */
      if (left > 0)
	{
	error2loop:
	  err = rmtread (archive, more, (int) left);
	  if (err < 0)
	    {
	      readerror ();
	      goto error2loop;	/* Try again */
	    }
	  if (err == 0)
	    {
	      msg ("archive %s EOF not on block boundary", ar_files[cur_ar_file]);
	      exit (EX_BADARCH);
	    }
	  left -= err;
	  more += err;
	  goto again;
	}
    }
  else
    {
      msg ("only read %d bytes from archive %s", err, ar_files[cur_ar_file]);
      exit (EX_BADARCH);
    }
}


/*
 * Flush the current buffer to/from the archive.
 */
void
flush_archive ()
{
  int c;

  baserec += ar_last - ar_block;/* Keep track of block #s */
  ar_record = ar_block;		/* Restore pointer to start */
  ar_last = ar_block + blocking;/* Restore pointer to end */

  if (ar_reading)
    {
      if (time_to_start_writing)
	{
	  time_to_start_writing = 0;
	  ar_reading = 0;

	  if (file_to_switch_to >= 0)
	    {
	      if ((c = rmtclose (archive)) < 0)
		msg_perror ("Warning: can't close %s(%d,%d)", ar_files[cur_ar_file], archive, c);

	      archive = file_to_switch_to;
	    }
	  else
	    (void) backspace_output ();
	  fl_write ();
	}
      else
	fl_read ();
    }
  else
    {
      fl_write ();
    }
}

/* Backspace the archive descriptor by one blocks worth.
   If its a tape, MTIOCTOP will work.  If its something else,
   we try to seek on it.  If we can't seek, we lose! */
int
backspace_output ()
{
  long cur;
  /* int er; */
  extern char *output_start;

#ifdef MTIOCTOP
  struct mtop t;

  t.mt_op = MTBSR;
  t.mt_count = 1;
  if ((rmtioctl (archive, MTIOCTOP, &t)) >= 0)
    return 1;
  if (errno == EIO && (rmtioctl (archive, MTIOCTOP, &t)) >= 0)
    return 1;
#endif

  cur = rmtlseek (archive, 0L, 1);
  cur -= blocksize;
  /* Seek back to the beginning of this block and
	   start writing there. */

  if (rmtlseek (archive, cur, 0) != cur)
    {
      /* Lseek failed.  Try a different method */
      msg ("Couldn't backspace archive file.  It may be unreadable without -i.");
      /* Replace the first part of the block with nulls */
      if (ar_block->charptr != output_start)
	bzero (ar_block->charptr, output_start - ar_block->charptr);
      return 2;
    }
  return 3;
}


/*
 * Close the archive file.
 */
void
close_archive ()
{
  int child;
  int status;
  int c;

  if (time_to_start_writing || !ar_reading)
    flush_archive ();
  if (cmd_mode == CMD_DELETE)
    {
      off_t pos;

      pos = rmtlseek (archive, 0L, 1);
#ifndef __MSDOS__
      (void) ftruncate (archive, pos);
#else
      (void) rmtwrite (archive, "", 0);
#endif
    }
  if (f_verify)
    verify_volume ();

  if ((c = rmtclose (archive)) < 0)
    msg_perror ("Warning: can't close %s(%d,%d)", ar_files[cur_ar_file], archive, c);

#ifndef	__MSDOS__
  if (childpid)
    {
      /*
       * Loop waiting for the right child to die, or for
       * no more kids.
       */
      while (((child = wait (&status)) != childpid) && child != -1)
	;

      if (child != -1)
	{
	  if (WIFSIGNALED (status))
	    {
	      /* SIGPIPE is OK, everything else is a problem. */
	      if (WTERMSIG (status) != SIGPIPE)
		msg ("child died with signal %d%s", WTERMSIG (status),
		     WIFCOREDUMPED (status) ? " (core dumped)" : "");
	    }
	  else
	    {
	      /* Child voluntarily terminated  -- but why? */
	      if (WEXITSTATUS (status) == MAGIC_STAT)
		{
		  exit (EX_SYSTEM);	/* Child had trouble */
		}
	      if (WEXITSTATUS (status) == (SIGPIPE + 128))
		{
		  /*
		   * /bin/sh returns this if its child
		   * dies with SIGPIPE.  'Sok.
		   */
		  /* Do nothing. */
		}
	      else if (WEXITSTATUS (status))
		msg ("child returned status %d",
		     WEXITSTATUS (status));
	    }
	}
    }
#endif /* __MSDOS__ */
}


#ifdef DONTDEF
/*
 * Message management.
 *
 * anno writes a message prefix on stream (eg stdout, stderr).
 *
 * The specified prefix is normally output followed by a colon and a space.
 * However, if other command line options are set, more output can come
 * out, such as the record # within the archive.
 *
 * If the specified prefix is NULL, no output is produced unless the
 * command line option(s) are set.
 *
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
void
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
void
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
	{
	  closeout_volume_number ();
	  system (info_script);
	}
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
