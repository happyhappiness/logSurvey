    }
}

/*---------------------------------------------------------------------.
| Handle write errors on the archive.  Write errors are always fatal.  |
| Hitting the end of a volume does not cause a write error unless the  |
| write was the first record of the volume.			       |
`---------------------------------------------------------------------*/

static void
write_error (int status)
{
  int saved_errno = errno;

  /* It might be useful to know how much was written before the error
     occured.  Beware that mere printing maybe change errno value.  */
  if (totals_option)
    print_total_written ();

  if (status < 0)
    FATAL_ERROR ((0, saved_errno, _("Cannot write to %s"),
		  *archive_name_cursor));
  else
    FATAL_ERROR ((0, 0, _("Only wrote %u of %u bytes to %s"),
		  status, record_size, *archive_name_cursor));
}

/*-------------------------------------------------------------------.
| Handle read errors on the archive.  If the read should be retried, |
| returns to the caller.					     |
`-------------------------------------------------------------------*/

static void
read_error (void)
{
  WARN ((0, errno, _("Read error on %s"), *archive_name_cursor));

  if (record_start_block == 0)
    FATAL_ERROR ((0, 0, _("At beginning of tape, quitting now")));

  /* Read error in mid archive.  We retry up to READ_ERROR_MAX times and
     then give up on reading the archive.  */

  if (read_error_count++ > READ_ERROR_MAX)
    FATAL_ERROR ((0, 0, _("Too many errors, quitting")));
  return;
}

/*-------------------------------------.
| Perform a read to flush the buffer.  |
`-------------------------------------*/

void
flush_read (void)
{
  int status;			/* result from system call */
  int left;			/* bytes left */
  char *more;			/* pointer to next byte to read */

  if (checkpoint_option && !(++checkpoint % 10))
    WARN ((0, 0, _("Read checkpoint %d"), checkpoint));

  /* Clear the count of errors.  This only applies to a single call to
     flush_read.  */

  read_error_count = 0;		/* clear error count */

  if (write_archive_to_stdout && record_start_block != 0)
    {
      status = rmtwrite (1, record_start->buffer, (unsigned int) record_size);
      if (status != record_size)
	write_error (status);
    }
  if (multi_volume_option)
    if (save_name)
      {
	char *cursor = save_name;

#if MSDOS
	if (cursor[1] == ':')
	  cursor += 2;
#endif
	while (*cursor == '/')
	  cursor++;

	strcpy (real_s_name, cursor);
	real_s_sizeleft = save_sizeleft;
	real_s_totsize = save_totsize;
      }
    else
      {
	real_s_name[0] = '\0';
	real_s_totsize = 0;
	real_s_sizeleft = 0;
      }

error_loop:
  status = rmtread (archive, record_start->buffer, (unsigned int) record_size);
  if (status == record_size)
    return;

  if ((status == 0
       || (status < 0 && errno == ENOSPC)
       || (status > 0 && !read_full_records_option))
      && multi_volume_option)
    {
      union block *cursor;

    try_volume:
      switch (subcommand_option)
	{
	case APPEND_SUBCOMMAND:
	case CAT_SUBCOMMAND:
	case UPDATE_SUBCOMMAND:
	  if (!new_volume (ACCESS_UPDATE))
	    return;
	  break;

	default:
	  if (!new_volume (ACCESS_READ))
	    return;
	  break;
	}

    vol_error:
      status = rmtread (archive, record_start->buffer,
			(unsigned int) record_size);
      if (status < 0)
	{
	  read_error ();
	  goto vol_error;
	}
      if (status != record_size)
	goto short_read;

      cursor = record_start;

      if (cursor->header.typeflag == GNUTYPE_VOLHDR)
	{
	  if (volume_label_option)
	    {
	      if (!check_label_pattern (cursor))
		{
		  WARN ((0, 0, _("Volume `%s' does not match `%s'"),
			 cursor->header.name, volume_label_option));
		  volno--;
		  global_volno--;
		  goto try_volume;
		}
	    }
	  if (verbose_option)
	    fprintf (stdlis, _("Reading %s\n"), cursor->header.name);
	  cursor++;
	}
      else if (volume_label_option)
	WARN ((0, 0, _("WARNING: No volume header")));

      if (real_s_name[0])
	{
	  if (cursor->header.typeflag != GNUTYPE_MULTIVOL
	      || strcmp (cursor->header.name, real_s_name))
	    {
	      WARN ((0, 0, _("%s is not continued on this volume"),
		     real_s_name));
	      volno--;
	      global_volno--;
	      goto try_volume;
	    }
	  if (real_s_totsize
	      != (from_oct (1 + 12, cursor->header.size)
		  + from_oct (1 + 12, cursor->oldgnu_header.offset)))
	    {
	      WARN ((0, 0, _("%s is the wrong size (%ld != %ld + %ld)"),
			 cursor->header.name, save_totsize,
			 from_oct (1 + 12, cursor->header.size),
			 from_oct (1 + 12, cursor->oldgnu_header.offset)));
	      volno--;
	      global_volno--;
	      goto try_volume;
	    }
	  if (real_s_totsize - real_s_sizeleft
	      != from_oct (1 + 12, cursor->oldgnu_header.offset))
	    {
	      WARN ((0, 0, _("This volume is out of sequence")));
	      volno--;
	      global_volno--;
	      goto try_volume;
	    }
	  cursor++;
	}
      current_block = cursor;
      return;
    }
  else if (status < 0)
    {
      read_error ();
      goto error_loop;		/* try again */
    }

short_read:
  more = record_start->buffer + status;
  left = record_size - status;

again:
  if ((unsigned) left % BLOCKSIZE == 0)
    {
      /* FIXME: for size=0, multi-volume support.  On the first record, warn
	 about the problem.  */

      if (!read_full_records_option && verbose_option
	  && record_start_block == 0 && status > 0)
	WARN ((0, 0, _("Record size = %d blocks"), status / BLOCKSIZE));

      record_end
	= record_start + ((unsigned) (record_size - left)) / BLOCKSIZE;

      return;
    }
  if (read_full_records_option)
    {
      /* User warned us about this.  Fix up.  */

      if (left > 0)
	{
	error2loop:
	  status = rmtread (archive, more, (unsigned int) left);
	  if (status < 0)
	    {
	      read_error ();
	      goto error2loop;	/* try again */
	    }
	  if (status == 0)
	    FATAL_ERROR ((0, 0, _("Archive %s EOF not on block boundary"),
			  *archive_name_cursor));
	  left -= status;
	  more += status;
	  goto again;
	}
    }
  else
    FATAL_ERROR ((0, 0, _("Only read %d bytes from archive %s"),
		  status, *archive_name_cursor));
}

/*-----------------------------------------------.
| Flush the current buffer to/from the archive.	 |
`-----------------------------------------------*/

void
flush_archive (void)
{
  record_start_block += record_end - record_start;
  current_block = record_start;
  record_end = record_start + blocking_factor;

  if (access_mode == ACCESS_READ && time_to_start_writing)
    {
      access_mode = ACCESS_WRITE;
      time_to_start_writing = 0;

      if (file_to_switch_to >= 0)
	{
	  int status = rmtclose (archive);

	  if (status < 0)
	    WARN ((0, errno, _("WARNING: Cannot close %s (%d, %d)"),
		   *archive_name_cursor, archive, status));

	  archive = file_to_switch_to;
	}
      else
	backspace_output ();
    }

  switch (access_mode)
    {
    case ACCESS_READ:
      flush_read ();
      break;

    case ACCESS_WRITE:
      flush_write ();
      break;

    case ACCESS_UPDATE:
      abort ();
    }
}

/*-------------------------------------------------------------------------.
| Backspace the archive descriptor by one record worth.  If its a tape,	   |
| MTIOCTOP will work.  If its something else, we try to seek on it.  If we |
| can't seek, we lose!							   |
`-------------------------------------------------------------------------*/

static void
backspace_output (void)
{
#ifdef MTIOCTOP
  {
    struct mtop operation;

    operation.mt_op = MTBSR;
    operation.mt_count = 1;
    if (rmtioctl (archive, MTIOCTOP, (char *) &operation) >= 0)
      return;
    if (errno == EIO && rmtioctl (archive, MTIOCTOP, (char *) &operation) >= 0)
      return;
  }
#endif

  {
    off_t position = rmtlseek (archive, 0L, 1);

    /* Seek back to the beginning of this record and start writing there.  */

    position -= record_size;
    if (rmtlseek (archive, position, 0) != position)
      {
	/* Lseek failed.  Try a different method.  */

	WARN ((0, 0, _("\
Could not backspace archive file; it may be unreadable without -i")));

	/* Replace the first part of the record with NULs.  */

	if (record_start->buffer != output_start)
	  memset (record_start->buffer, 0,
		  (size_t) (output_start - record_start->buffer));
      }
  }
}

/*-------------------------.
| Close the archive file.  |
`-------------------------*/

void
close_archive (void)
{
  if (time_to_start_writing || access_mode == ACCESS_WRITE)
    flush_archive ();

#if !MSDOS

  /* Manage to fully drain a pipe we might be reading, so to not break it on
     the producer after the EOF block.  FIXME: one of these days, GNU tar
     might become clever enough to just stop working, once there is no more
     work to do, we might have to revise this area in such time.  */

  if (access_mode == ACCESS_READ && S_ISFIFO (archive_stat.st_mode))
    while (rmtread (archive, record_start->buffer, (unsigned int) record_size)
	   > 0)
      continue;
#endif

  if (subcommand_option == DELETE_SUBCOMMAND)
    {
      off_t pos;

      pos = rmtlseek (archive, 0L, 1);
#if MSDOS
      rmtwrite (archive, "", 0);
#else
      ftruncate (archive, (size_t) pos);
#endif
    }
  if (verify_option)
    verify_volume ();

  {
    int status = rmtclose (archive);

    if (status < 0)
      WARN ((0, errno, _("WARNING: Cannot close %s (%d, %d)"),
	     *archive_name_cursor, archive, status));
  }

#if !MSDOS

  if (child_pid)
    {
      WAIT_T wait_status;
      int child;

      /* Loop waiting for the right child to die, or for no more kids.  */

      while ((child = wait (&wait_status), child != child_pid)
	     && child != -1)
	continue;

      if (child != -1)
	if (WIFSIGNALED (wait_status)
#if 0
	    && !WIFSTOPPED (wait_status)
#endif
	    )
	  {
	    /* SIGPIPE is OK, everything else is a problem.  */

	    if (WTERMSIG (wait_status) != SIGPIPE)
	      ERROR ((0, 0, _("Child died with signal %d%s"),
		      WTERMSIG (wait_status),
		      WCOREDUMP (wait_status) ? _(" (core dumped)") : ""));
	  }
	else
	  {
	    /* Child voluntarily terminated -- but why?  /bin/sh returns
	       SIGPIPE + 128 if its child, then do nothing.  */

	    if (WEXITSTATUS (wait_status) != (SIGPIPE + 128)
		&& WEXITSTATUS (wait_status))
	      ERROR ((0, 0, _("Child returned status %d"),
		      WEXITSTATUS (wait_status)));
	  }
    }
#endif /* !MSDOS */

  if (current_file_name)
    free (current_file_name);
  if (current_link_name)
    free (current_link_name);
  if (save_name)
    free (save_name);
  free (multi_volume_option ? record_start - 2 : record_start);
}

/*------------------------------------------------.
| Called to initialize the global volume number.  |
`------------------------------------------------*/

void
init_volume_number (void)
{
  FILE *file = fopen (volno_file_option, "r");

  if (file)
    {
      fscanf (file, "%d", &global_volno);
      if (fclose (file) == EOF)
	ERROR ((0, errno, "%s", volno_file_option));
    }
  else if (errno != ENOENT)
    ERROR ((0, errno, "%s", volno_file_option));
}

/*-------------------------------------------------------.
| Called to write out the closing global volume number.	 |
`-------------------------------------------------------*/

void
closeout_volume_number (void)
{
  FILE *file = fopen (volno_file_option, "w");

  if (file)
    {
      fprintf (file, "%d\n", global_volno);
      if (fclose (file) == EOF)
	ERROR ((0, errno, "%s", volno_file_option));
    }
  else
    ERROR ((0, errno, "%s", volno_file_option));
}

/*-----------------------------------------------------------------------.
| We've hit the end of the old volume.  Close it and open the next one.	 |
| Return nonzero on success.						 |
`-----------------------------------------------------------------------*/

static int
new_volume (enum access_mode access)
{
  static FILE *read_file = NULL;
  static int looped = 0;

  int status;

  if (!read_file && !info_script_option)
    /* FIXME: if fopen is used, it will never be closed.  */
    read_file = archive == STDIN ? fopen (TTY_NAME, "r") : stdin;

  if (now_verifying)
    return 0;
  if (verify_option)
    verify_volume ();

  if (status = rmtclose (archive), status < 0)
    WARN ((0, errno, _("WARNING: Cannot close %s (%d, %d)"),
	   *archive_name_cursor, archive, status));

  global_volno++;
  volno++;
  archive_name_cursor++;
  if (archive_name_cursor == archive_name_array + archive_names)
    {
      archive_name_cursor = archive_name_array;
      looped = 1;
    }

tryagain:
  if (looped)
    {
      /* We have to prompt from now on.  */

      if (info_script_option)
	{
	  if (volno_file_option)
	    closeout_volume_number ();
	  system (info_script_option);
	}
      else
	while (1)
	  {
	    char input_buffer[80];

	    fprintf (stderr,
		     _("\007Prepare volume #%d for %s and hit return: "),
		     global_volno, *archive_name_cursor);
	    fflush (stderr);

	    if (fgets (input_buffer, sizeof (input_buffer), read_file) == 0)
	      {
		fprintf (stderr, _("EOF where user reply was expected"));

		if (subcommand_option != EXTRACT_SUBCOMMAND
		    && subcommand_option != LIST_SUBCOMMAND
		    && subcommand_option != DIFF_SUBCOMMAND)
		  WARN ((0, 0, _("WARNING: Archive is incomplete")));

		exit (TAREXIT_FAILURE);
	      }
	    if (input_buffer[0] == '\n'
		|| input_buffer[0] == 'y'
		|| input_buffer[0] == 'Y')
	      break;

	    switch (input_buffer[0])
	      {
	      case '?':
		{
		  fprintf (stderr, _("\
 n [name]   Give a new file name for the next (and subsequent) volume(s)\n\
 q          Abort tar\n\
 !          Spawn a subshell\n\
 ?          Print this list\n"));
		}
		break;

	      case 'q':
		/* Quit.  */

		fprintf (stdlis, _("No new volume; exiting.\n"));

		if (subcommand_option != EXTRACT_SUBCOMMAND
		    && subcommand_option != LIST_SUBCOMMAND
		    && subcommand_option != DIFF_SUBCOMMAND)
		  WARN ((0, 0, _("WARNING: Archive is incomplete")));

		exit (TAREXIT_FAILURE);

	      case 'n':
		/* Get new file name.  */

		{
		  char *name = &input_buffer[1];
		  char *cursor;

		  while (*name == ' ' || *name == '\t')
		    name++;
		  cursor = name;
		  while (*cursor && *cursor != '\n')
		    cursor++;
		  *cursor = '\0';

		  /* FIXME: the following allocation is never reclaimed.  */
		  *archive_name_cursor = xstrdup (name);
		}
		break;

	      case '!':
#if MSDOS
		spawnl (P_WAIT, getenv ("COMSPEC"), "-", 0);
#else /* not MSDOS */
		switch (fork ())
		  {
		  case -1:
		    WARN ((0, errno, _("Cannot fork!")));
		    break;

		  case 0:
		    {
		      const char *shell = getenv ("SHELL");

		      if (shell == NULL)
			shell = "/bin/sh";
		      execlp (shell, "-sh", "-i", 0);
		      FATAL_ERROR ((0, errno, _("Cannot exec a shell %s"),
				    shell));
		    }

		  default:
		    {
		      WAIT_T wait_status;

		      wait (&wait_status);
		    }
		    break;
		  }

		/* FIXME: I'm not sure if that's all that has to be done
		   here.  (jk)  */

#endif /* not MSDOS */
		break;
	      }
	  }
    }

  if (verify_option)
    archive = rmtopen (*archive_name_cursor, O_RDWR | O_CREAT, 0666,
		       rsh_command_option);
  else
    switch (access)
      {
      case ACCESS_READ:
	archive = rmtopen (*archive_name_cursor, O_RDONLY, 0666,
			   rsh_command_option);
	break;

      case ACCESS_WRITE:
	if (backup_option)
	  maybe_backup_file (*archive_name_cursor, 1);
	archive = rmtcreat (*archive_name_cursor, 0666, rsh_command_option);
	break;

      case ACCESS_UPDATE:
	archive = rmtopen (*archive_name_cursor, O_RDWR | O_CREAT, 0666,
			   rsh_command_option);
	break;
      }

  if (archive < 0)
    {
      WARN ((0, errno, _("Cannot open %s"), *archive_name_cursor));
      if (!verify_option && access == ACCESS_WRITE && backup_option)
	undo_last_backup ();
      goto tryagain;
    }

#if MSDOS
  setmode (archive, O_BINARY);
#endif

  return 1;
}
