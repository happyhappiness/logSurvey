     }
 }
 
-/* Handle write errors on the archive.  Write errors are always fatal */
-/* Hitting the end of a volume does not cause a write error unless the write
-*  was the first block of the volume */
+/*---------------------------------------------------------------------.
+| Handle write errors on the archive.  Write errors are always fatal.  |
+| Hitting the end of a volume does not cause a write error unless the  |
+| write was the first record of the volume.			       |
+`---------------------------------------------------------------------*/
 
-void
-writeerror (err)
-     int err;
+static void
+write_error (int status)
 {
-  if (err < 0)
-    {
-      msg_perror ("can't write to %s", ar_files[cur_ar_file]);
-      exit (EX_BADARCH);
-    }
+  int saved_errno = errno;
+
+  /* It might be useful to know how much was written before the error
+     occured.  Beware that mere printing maybe change errno value.  */
+  if (totals_option)
+    print_total_written ();
+
+  if (status < 0)
+    FATAL_ERROR ((0, saved_errno, _("Cannot write to %s"),
+		  *archive_name_cursor));
   else
-    {
-      msg ("only wrote %u of %u bytes to %s", err, blocksize, ar_files[cur_ar_file]);
-      exit (EX_BADARCH);
-    }
+    FATAL_ERROR ((0, 0, _("Only wrote %u of %u bytes to %s"),
+		  status, record_size, *archive_name_cursor));
 }
 
-/*
- * Handle read errors on the archive.
- *
- * If the read should be retried, readerror() returns to the caller.
- */
-void
-readerror ()
-{
-#	define	READ_ERROR_MAX	10
+/*-------------------------------------------------------------------.
+| Handle read errors on the archive.  If the read should be retried, |
+| returns to the caller.					     |
+`-------------------------------------------------------------------*/
 
-  read_error_flag++;		/* Tell callers */
+static void
+read_error (void)
+{
+  WARN ((0, errno, _("Read error on %s"), *archive_name_cursor));
 
-  msg_perror ("read error on %s", ar_files[cur_ar_file]);
+  if (record_start_block == 0)
+    FATAL_ERROR ((0, 0, _("At beginning of tape, quitting now")));
 
-  if (baserec == 0)
-    {
-      /* First block of tape.  Probably stupidity error */
-      exit (EX_BADARCH);
-    }
+  /* Read error in mid archive.  We retry up to READ_ERROR_MAX times and
+     then give up on reading the archive.  */
 
-  /*
-	 * Read error in mid archive.  We retry up to READ_ERROR_MAX times
-	 * and then give up on reading the archive.  We set read_error_flag
-	 * for our callers, so they can cope if they want.
-	 */
-  if (r_error_count++ > READ_ERROR_MAX)
-    {
-      msg ("Too many errors, quitting.");
-      exit (EX_BADARCH);
-    }
+  if (read_error_count++ > READ_ERROR_MAX)
+    FATAL_ERROR ((0, 0, _("Too many errors, quitting")));
   return;
 }
 
+/*-------------------------------------.
+| Perform a read to flush the buffer.  |
+`-------------------------------------*/
 
-/*
- * Perform a read to flush the buffer.
- */
 void
-fl_read ()
+flush_read (void)
 {
-  int err;			/* Result from system call */
-  int left;			/* Bytes left */
-  char *more;			/* Pointer to next byte to read */
-
-  if (f_checkpoint && !(++checkpoint % 10))
-    msg ("Read checkpoint %d\n", checkpoint);
-
-  /*
-	 * Clear the count of errors.  This only applies to a single
-	 * call to fl_read.  We leave read_error_flag alone; it is
-	 * only turned off by higher level software.
-	 */
-  r_error_count = 0;		/* Clear error count */
-
-  /*
-	 * If we are about to wipe out a record that
-	 * somebody needs to keep, copy it out to a holding
-	 * area and adjust somebody's pointer to it.
-	 */
-  if (save_rec &&
-      *save_rec >= ar_record &&
-      *save_rec < ar_last)
-    {
-      record_save_area = **save_rec;
-      *save_rec = &record_save_area;
-    }
-  if (write_archive_to_stdout && baserec != 0)
-    {
-      err = rmtwrite (1, ar_block->charptr, blocksize);
-      if (err != blocksize)
-	writeerror (err);
-    }
-  if (f_multivol)
-    {
-      if (save_name)
-	{
-	  if (save_name != real_s_name)
-	    {
-#ifdef __MSDOS__
-	      if (save_name[1] == ':')
-		save_name += 2;
-#endif
-	      while (*save_name == '/')
-		save_name++;
+  int status;			/* result from system call */
+  int left;			/* bytes left */
+  char *more;			/* pointer to next byte to read */
 
-	      strcpy (real_s_name, save_name);
-	      save_name = real_s_name;
-	    }
-	  real_s_totsize = save_totsize;
-	  real_s_sizeleft = save_sizeleft;
+  if (checkpoint_option && !(++checkpoint % 10))
+    WARN ((0, 0, _("Read checkpoint %d"), checkpoint));
 
-	}
-      else
-	{
-	  real_s_name[0] = '\0';
-	  real_s_totsize = 0;
-	  real_s_sizeleft = 0;
-	}
+  /* Clear the count of errors.  This only applies to a single call to
+     flush_read.  */
+
+  read_error_count = 0;		/* clear error count */
+
+  if (write_archive_to_stdout && record_start_block != 0)
+    {
+      status = rmtwrite (1, record_start->buffer, (unsigned int) record_size);
+      if (status != record_size)
+	write_error (status);
     }
+  if (multi_volume_option)
+    if (save_name)
+      {
+	char *cursor = save_name;
+
+#if MSDOS
+	if (cursor[1] == ':')
+	  cursor += 2;
+#endif
+	while (*cursor == '/')
+	  cursor++;
+
+	strcpy (real_s_name, cursor);
+	real_s_sizeleft = save_sizeleft;
+	real_s_totsize = save_totsize;
+      }
+    else
+      {
+	real_s_name[0] = '\0';
+	real_s_totsize = 0;
+	real_s_sizeleft = 0;
+      }
 
 error_loop:
-  err = rmtread (archive, ar_block->charptr, (int) blocksize);
-  if (err == blocksize)
+  status = rmtread (archive, record_start->buffer, (unsigned int) record_size);
+  if (status == record_size)
     return;
 
-  if ((err == 0 || (err < 0 && errno == ENOSPC) || (err > 0 && !f_reblock)) && f_multivol)
+  if ((status == 0
+       || (status < 0 && errno == ENOSPC)
+       || (status > 0 && !read_full_records_option))
+      && multi_volume_option)
     {
-      union record *head;
+      union block *cursor;
 
     try_volume:
-      if (new_volume ((cmd_mode == CMD_APPEND || cmd_mode == CMD_CAT || cmd_mode == CMD_UPDATE) ? 2 : 1) < 0)
-	return;
+      switch (subcommand_option)
+	{
+	case APPEND_SUBCOMMAND:
+	case CAT_SUBCOMMAND:
+	case UPDATE_SUBCOMMAND:
+	  if (!new_volume (ACCESS_UPDATE))
+	    return;
+	  break;
+
+	default:
+	  if (!new_volume (ACCESS_READ))
+	    return;
+	  break;
+	}
+
     vol_error:
-      err = rmtread (archive, ar_block->charptr, (int) blocksize);
-      if (err < 0)
+      status = rmtread (archive, record_start->buffer,
+			(unsigned int) record_size);
+      if (status < 0)
 	{
-	  readerror ();
+	  read_error ();
 	  goto vol_error;
 	}
-      if (err != blocksize)
+      if (status != record_size)
 	goto short_read;
 
-      head = ar_block;
+      cursor = record_start;
 
-      if (head->header.linkflag == LF_VOLHDR)
+      if (cursor->header.typeflag == GNUTYPE_VOLHDR)
 	{
-	  if (f_volhdr)
+	  if (volume_label_option)
 	    {
-#if 0
-	      char *ptr;
-
-	      ptr = (char *) malloc (strlen (f_volhdr) + 20);
-	      sprintf (ptr, "%s Volume %d", f_volhdr, volno);
-#endif
-	      if (re_match (label_pattern, head->header.arch_name,
-			    strlen (head->header.arch_name),
-			    0, 0) < 0)
-		{
-		  msg ("Volume mismatch! %s!=%s", f_volhdr,
-		       head->header.arch_name);
-		  --volno;
-		  --global_volno;
-		  goto try_volume;
-		}
-
-#if 0
-	      if (strcmp (ptr, head->header.name))
+	      if (!check_label_pattern (cursor))
 		{
-		  msg ("Volume mismatch! %s!=%s", ptr, head->header.name);
-		  --volno;
-		  --global_volno;
-		  free (ptr);
+		  WARN ((0, 0, _("Volume `%s' does not match `%s'"),
+			 cursor->header.name, volume_label_option));
+		  volno--;
+		  global_volno--;
 		  goto try_volume;
 		}
-	      free (ptr);
-#endif
 	    }
-	  if (f_verbose)
-	    fprintf (msg_file, "Reading %s\n", head->header.arch_name);
-	  head++;
-	}
-      else if (f_volhdr)
-	{
-	  msg ("Warning:  No volume header!");
+	  if (verbose_option)
+	    fprintf (stdlis, _("Reading %s\n"), cursor->header.name);
+	  cursor++;
 	}
+      else if (volume_label_option)
+	WARN ((0, 0, _("WARNING: No volume header")));
 
       if (real_s_name[0])
 	{
-	  long from_oct ();
-
-	  if (head->header.linkflag != LF_MULTIVOL || strcmp (head->header.arch_name, real_s_name))
+	  if (cursor->header.typeflag != GNUTYPE_MULTIVOL
+	      || strcmp (cursor->header.name, real_s_name))
 	    {
-	      msg ("%s is not continued on this volume!", real_s_name);
-	      --volno;
-	      --global_volno;
+	      WARN ((0, 0, _("%s is not continued on this volume"),
+		     real_s_name));
+	      volno--;
+	      global_volno--;
 	      goto try_volume;
 	    }
-	  if (real_s_totsize != from_oct (1 + 12, head->header.size) + from_oct (1 + 12, head->header.offset))
+	  if (real_s_totsize
+	      != (from_oct (1 + 12, cursor->header.size)
+		  + from_oct (1 + 12, cursor->oldgnu_header.offset)))
 	    {
-	      msg ("%s is the wrong size (%ld!=%ld+%ld)",
-		   head->header.arch_name, save_totsize,
-		   from_oct (1 + 12, head->header.size),
-		   from_oct (1 + 12, head->header.offset));
-	      --volno;
-	      --global_volno;
+	      WARN ((0, 0, _("%s is the wrong size (%ld != %ld + %ld)"),
+			 cursor->header.name, save_totsize,
+			 from_oct (1 + 12, cursor->header.size),
+			 from_oct (1 + 12, cursor->oldgnu_header.offset)));
+	      volno--;
+	      global_volno--;
 	      goto try_volume;
 	    }
-	  if (real_s_totsize - real_s_sizeleft != from_oct (1 + 12, head->header.offset))
+	  if (real_s_totsize - real_s_sizeleft
+	      != from_oct (1 + 12, cursor->oldgnu_header.offset))
 	    {
-	      msg ("This volume is out of sequence");
-	      --volno;
-	      --global_volno;
+	      WARN ((0, 0, _("This volume is out of sequence")));
+	      volno--;
+	      global_volno--;
 	      goto try_volume;
 	    }
-	  head++;
+	  cursor++;
 	}
-      ar_record = head;
+      current_block = cursor;
       return;
     }
-  else if (err < 0)
+  else if (status < 0)
     {
-      readerror ();
-      goto error_loop;		/* Try again */
+      read_error ();
+      goto error_loop;		/* try again */
     }
 
 short_read:
-  more = ar_block->charptr + err;
-  left = blocksize - err;
+  more = record_start->buffer + status;
+  left = record_size - status;
 
 again:
-  if (0 == (((unsigned) left) % RECORDSIZE))
+  if ((unsigned) left % BLOCKSIZE == 0)
     {
-      /* FIXME, for size=0, multi vol support */
-      /* On the first block, warn about the problem */
-      if (!f_reblock && baserec == 0 && f_verbose && err > 0)
-	{
-	  /*	msg("Blocksize = %d record%s",
-				err / RECORDSIZE, (err > RECORDSIZE)? "s": "");*/
-	  msg ("Blocksize = %d records", err / RECORDSIZE);
-	}
-      ar_last = ar_block + ((unsigned) (blocksize - left)) / RECORDSIZE;
+      /* FIXME: for size=0, multi-volume support.  On the first record, warn
+	 about the problem.  */
+
+      if (!read_full_records_option && verbose_option
+	  && record_start_block == 0 && status > 0)
+	WARN ((0, 0, _("Record size = %d blocks"), status / BLOCKSIZE));
+
+      record_end
+	= record_start + ((unsigned) (record_size - left)) / BLOCKSIZE;
+
       return;
     }
-  if (f_reblock)
+  if (read_full_records_option)
     {
-      /*
-		 * User warned us about this.  Fix up.
-		 */
+      /* User warned us about this.  Fix up.  */
+
       if (left > 0)
 	{
 	error2loop:
-	  err = rmtread (archive, more, (int) left);
-	  if (err < 0)
-	    {
-	      readerror ();
-	      goto error2loop;	/* Try again */
-	    }
-	  if (err == 0)
+	  status = rmtread (archive, more, (unsigned int) left);
+	  if (status < 0)
 	    {
-	      msg ("archive %s EOF not on block boundary", ar_files[cur_ar_file]);
-	      exit (EX_BADARCH);
+	      read_error ();
+	      goto error2loop;	/* try again */
 	    }
-	  left -= err;
-	  more += err;
+	  if (status == 0)
+	    FATAL_ERROR ((0, 0, _("Archive %s EOF not on block boundary"),
+			  *archive_name_cursor));
+	  left -= status;
+	  more += status;
 	  goto again;
 	}
     }
   else
-    {
-      msg ("only read %d bytes from archive %s", err, ar_files[cur_ar_file]);
-      exit (EX_BADARCH);
-    }
+    FATAL_ERROR ((0, 0, _("Only read %d bytes from archive %s"),
+		  status, *archive_name_cursor));
 }
 
+/*-----------------------------------------------.
+| Flush the current buffer to/from the archive.	 |
+`-----------------------------------------------*/
 
-/*
- * Flush the current buffer to/from the archive.
- */
 void
-flush_archive ()
+flush_archive (void)
 {
-  int c;
+  record_start_block += record_end - record_start;
+  current_block = record_start;
+  record_end = record_start + blocking_factor;
 
-  baserec += ar_last - ar_block;/* Keep track of block #s */
-  ar_record = ar_block;		/* Restore pointer to start */
-  ar_last = ar_block + blocking;/* Restore pointer to end */
-
-  if (ar_reading)
+  if (access_mode == ACCESS_READ && time_to_start_writing)
     {
-      if (time_to_start_writing)
+      access_mode = ACCESS_WRITE;
+      time_to_start_writing = 0;
+
+      if (file_to_switch_to >= 0)
 	{
-	  time_to_start_writing = 0;
-	  ar_reading = 0;
+	  int status = rmtclose (archive);
 
-	  if (file_to_switch_to >= 0)
-	    {
-	      if ((c = rmtclose (archive)) < 0)
-		msg_perror ("Warning: can't close %s(%d,%d)", ar_files[cur_ar_file], archive, c);
+	  if (status < 0)
+	    WARN ((0, errno, _("WARNING: Cannot close %s (%d, %d)"),
+		   *archive_name_cursor, archive, status));
 
-	      archive = file_to_switch_to;
-	    }
-	  else
-	    (void) backspace_output ();
-	  fl_write ();
+	  archive = file_to_switch_to;
 	}
       else
-	fl_read ();
+	backspace_output ();
     }
-  else
+
+  switch (access_mode)
     {
-      fl_write ();
+    case ACCESS_READ:
+      flush_read ();
+      break;
+
+    case ACCESS_WRITE:
+      flush_write ();
+      break;
+
+    case ACCESS_UPDATE:
+      abort ();
     }
 }
 
-/* Backspace the archive descriptor by one blocks worth.
-   If its a tape, MTIOCTOP will work.  If its something else,
-   we try to seek on it.  If we can't seek, we lose! */
-int
-backspace_output ()
-{
-  long cur;
-  /* int er; */
-  extern char *output_start;
+/*-------------------------------------------------------------------------.
+| Backspace the archive descriptor by one record worth.  If its a tape,	   |
+| MTIOCTOP will work.  If its something else, we try to seek on it.  If we |
+| can't seek, we lose!							   |
+`-------------------------------------------------------------------------*/
 
+static void
+backspace_output (void)
+{
 #ifdef MTIOCTOP
-  struct mtop t;
+  {
+    struct mtop operation;
 
-  t.mt_op = MTBSR;
-  t.mt_count = 1;
-  if ((rmtioctl (archive, MTIOCTOP, &t)) >= 0)
-    return 1;
-  if (errno == EIO && (rmtioctl (archive, MTIOCTOP, &t)) >= 0)
-    return 1;
+    operation.mt_op = MTBSR;
+    operation.mt_count = 1;
+    if (rmtioctl (archive, MTIOCTOP, (char *) &operation) >= 0)
+      return;
+    if (errno == EIO && rmtioctl (archive, MTIOCTOP, (char *) &operation) >= 0)
+      return;
+  }
 #endif
 
-  cur = rmtlseek (archive, 0L, 1);
-  cur -= blocksize;
-  /* Seek back to the beginning of this block and
-	   start writing there. */
+  {
+    off_t position = rmtlseek (archive, 0L, 1);
 
-  if (rmtlseek (archive, cur, 0) != cur)
-    {
-      /* Lseek failed.  Try a different method */
-      msg ("Couldn't backspace archive file.  It may be unreadable without -i.");
-      /* Replace the first part of the block with nulls */
-      if (ar_block->charptr != output_start)
-	bzero (ar_block->charptr, output_start - ar_block->charptr);
-      return 2;
-    }
-  return 3;
+    /* Seek back to the beginning of this record and start writing there.  */
+
+    position -= record_size;
+    if (rmtlseek (archive, position, 0) != position)
+      {
+	/* Lseek failed.  Try a different method.  */
+
+	WARN ((0, 0, _("\
+Could not backspace archive file; it may be unreadable without -i")));
+
+	/* Replace the first part of the record with NULs.  */
+
+	if (record_start->buffer != output_start)
+	  memset (record_start->buffer, 0,
+		  (size_t) (output_start - record_start->buffer));
+      }
+  }
 }
 
+/*-------------------------.
+| Close the archive file.  |
+`-------------------------*/
 
-/*
- * Close the archive file.
- */
 void
-close_archive ()
+close_archive (void)
 {
-  int child;
-  int status;
-  int c;
-
-  if (time_to_start_writing || !ar_reading)
+  if (time_to_start_writing || access_mode == ACCESS_WRITE)
     flush_archive ();
-  if (cmd_mode == CMD_DELETE)
+
+#if !MSDOS
+
+  /* Manage to fully drain a pipe we might be reading, so to not break it on
+     the producer after the EOF block.  FIXME: one of these days, GNU tar
+     might become clever enough to just stop working, once there is no more
+     work to do, we might have to revise this area in such time.  */
+
+  if (access_mode == ACCESS_READ && S_ISFIFO (archive_stat.st_mode))
+    while (rmtread (archive, record_start->buffer, (unsigned int) record_size)
+	   > 0)
+      continue;
+#endif
+
+  if (subcommand_option == DELETE_SUBCOMMAND)
     {
       off_t pos;
 
       pos = rmtlseek (archive, 0L, 1);
-#ifndef __MSDOS__
-      (void) ftruncate (archive, pos);
+#if MSDOS
+      rmtwrite (archive, "", 0);
 #else
-      (void) rmtwrite (archive, "", 0);
+      ftruncate (archive, (size_t) pos);
 #endif
     }
-  if (f_verify)
+  if (verify_option)
     verify_volume ();
 
-  if ((c = rmtclose (archive)) < 0)
-    msg_perror ("Warning: can't close %s(%d,%d)", ar_files[cur_ar_file], archive, c);
+  {
+    int status = rmtclose (archive);
 
-#ifndef	__MSDOS__
-  if (childpid)
+    if (status < 0)
+      WARN ((0, errno, _("WARNING: Cannot close %s (%d, %d)"),
+	     *archive_name_cursor, archive, status));
+  }
+
+#if !MSDOS
+
+  if (child_pid)
     {
-      /*
-       * Loop waiting for the right child to die, or for
-       * no more kids.
-       */
-      while (((child = wait (&status)) != childpid) && child != -1)
-	;
+      WAIT_T wait_status;
+      int child;
+
+      /* Loop waiting for the right child to die, or for no more kids.  */
+
+      while ((child = wait (&wait_status), child != child_pid)
+	     && child != -1)
+	continue;
 
       if (child != -1)
-	{
-	  if (WIFSIGNALED (status))
-	    {
-	      /* SIGPIPE is OK, everything else is a problem. */
-	      if (WTERMSIG (status) != SIGPIPE)
-		msg ("child died with signal %d%s", WTERMSIG (status),
-		     WIFCOREDUMPED (status) ? " (core dumped)" : "");
-	    }
-	  else
-	    {
-	      /* Child voluntarily terminated  -- but why? */
-	      if (WEXITSTATUS (status) == MAGIC_STAT)
-		{
-		  exit (EX_SYSTEM);	/* Child had trouble */
-		}
-	      if (WEXITSTATUS (status) == (SIGPIPE + 128))
-		{
-		  /*
-		   * /bin/sh returns this if its child
-		   * dies with SIGPIPE.  'Sok.
-		   */
-		  /* Do nothing. */
-		}
-	      else if (WEXITSTATUS (status))
-		msg ("child returned status %d",
-		     WEXITSTATUS (status));
-	    }
-	}
-    }
-#endif /* __MSDOS__ */
-}
+	if (WIFSIGNALED (wait_status)
+#if 0
+	    && !WIFSTOPPED (wait_status)
+#endif
+	    )
+	  {
+	    /* SIGPIPE is OK, everything else is a problem.  */
 
+	    if (WTERMSIG (wait_status) != SIGPIPE)
+	      ERROR ((0, 0, _("Child died with signal %d%s"),
+		      WTERMSIG (wait_status),
+		      WCOREDUMP (wait_status) ? _(" (core dumped)") : ""));
+	  }
+	else
+	  {
+	    /* Child voluntarily terminated -- but why?  /bin/sh returns
+	       SIGPIPE + 128 if its child, then do nothing.  */
 
-#ifdef DONTDEF
-/*
- * Message management.
- *
- * anno writes a message prefix on stream (eg stdout, stderr).
- *
- * The specified prefix is normally output followed by a colon and a space.
- * However, if other command line options are set, more output can come
- * out, such as the record # within the archive.
- *
- * If the specified prefix is NULL, no output is produced unless the
- * command line option(s) are set.
- *
- * If the third argument is 1, the "saved" record # is used; if 0, the
- * "current" record # is used.
- */
-void
-anno (stream, prefix, savedp)
-     FILE *stream;
-     char *prefix;
-     int savedp;
-{
-#	define	MAXANNO	50
-  char buffer[MAXANNO];		/* Holds annorecment */
-#	define	ANNOWIDTH 13
-  int space;
-  long offset;
-  int save_e;
-
-  save_e = errno;
-  /* Make sure previous output gets out in sequence */
-  if (stream == stderr)
-    fflush (stdout);
-  if (f_sayblock)
-    {
-      if (prefix)
-	{
-	  fputs (prefix, stream);
-	  putc (' ', stream);
-	}
-      offset = ar_record - ar_block;
-      (void) sprintf (buffer, "rec %d: ",
-		      savedp ? saved_recno :
-		      baserec + offset);
-      fputs (buffer, stream);
-      space = ANNOWIDTH - strlen (buffer);
-      if (space > 0)
-	{
-	  fprintf (stream, "%*s", space, "");
-	}
-    }
-  else if (prefix)
-    {
-      fputs (prefix, stream);
-      fputs (": ", stream);
+	    if (WEXITSTATUS (wait_status) != (SIGPIPE + 128)
+		&& WEXITSTATUS (wait_status))
+	      ERROR ((0, 0, _("Child returned status %d"),
+		      WEXITSTATUS (wait_status)));
+	  }
     }
-  errno = save_e;
+#endif /* !MSDOS */
+
+  if (current_file_name)
+    free (current_file_name);
+  if (current_link_name)
+    free (current_link_name);
+  if (save_name)
+    free (save_name);
+  free (multi_volume_option ? record_start - 2 : record_start);
 }
 
-#endif
+/*------------------------------------------------.
+| Called to initialize the global volume number.  |
+`------------------------------------------------*/
 
-/* Called to initialize the global volume number. */
 void
-init_volume_number ()
+init_volume_number (void)
 {
-  FILE *vf;
-
-  vf = fopen (f_volno_file, "r");
-  if (!vf && errno != ENOENT)
-    msg_perror ("%s", f_volno_file);
+  FILE *file = fopen (volno_file_option, "r");
 
-  if (vf)
+  if (file)
     {
-      fscanf (vf, "%d", &global_volno);
-      fclose (vf);
+      fscanf (file, "%d", &global_volno);
+      if (fclose (file) == EOF)
+	ERROR ((0, errno, "%s", volno_file_option));
     }
+  else if (errno != ENOENT)
+    ERROR ((0, errno, "%s", volno_file_option));
 }
 
-/* Called to write out the closing global volume number. */
+/*-------------------------------------------------------.
+| Called to write out the closing global volume number.	 |
+`-------------------------------------------------------*/
+
 void
-closeout_volume_number ()
+closeout_volume_number (void)
 {
-  FILE *vf;
+  FILE *file = fopen (volno_file_option, "w");
 
-  vf = fopen (f_volno_file, "w");
-  if (!vf)
-    msg_perror ("%s", f_volno_file);
-  else
+  if (file)
     {
-      fprintf (vf, "%d\n", global_volno);
-      fclose (vf);
+      fprintf (file, "%d\n", global_volno);
+      if (fclose (file) == EOF)
+	ERROR ((0, errno, "%s", volno_file_option));
     }
+  else
+    ERROR ((0, errno, "%s", volno_file_option));
 }
 
-/* We've hit the end of the old volume.  Close it and open the next one */
-/* Values for type:  0: writing  1: reading  2: updating */
-int
-new_volume (type)
-     int type;
+/*-----------------------------------------------------------------------.
+| We've hit the end of the old volume.  Close it and open the next one.	 |
+| Return nonzero on success.						 |
+`-----------------------------------------------------------------------*/
+
+static int
+new_volume (enum access_mode access)
 {
-  int c;
-  char inbuf[80];
-  char *p;
-  static FILE *read_file = 0;
-  extern int now_verifying;
-  extern char TTY_NAME[];
+  static FILE *read_file = NULL;
   static int looped = 0;
 
-  if (!read_file && !f_run_script_at_end)
-    read_file = (archive == 0) ? fopen (TTY_NAME, "r") : stdin;
+  int status;
+
+  if (!read_file && !info_script_option)
+    /* FIXME: if fopen is used, it will never be closed.  */
+    read_file = archive == STDIN ? fopen (TTY_NAME, "r") : stdin;
 
   if (now_verifying)
-    return -1;
-  if (f_verify)
+    return 0;
+  if (verify_option)
     verify_volume ();
-  if ((c = rmtclose (archive)) < 0)
-    msg_perror ("Warning: can't close %s(%d,%d)", ar_files[cur_ar_file], archive, c);
+
+  if (status = rmtclose (archive), status < 0)
+    WARN ((0, errno, _("WARNING: Cannot close %s (%d, %d)"),
+	   *archive_name_cursor, archive, status));
 
   global_volno++;
   volno++;
-  cur_ar_file++;
-  if (cur_ar_file == n_ar_files)
+  archive_name_cursor++;
+  if (archive_name_cursor == archive_name_array + archive_names)
     {
-      cur_ar_file = 0;
+      archive_name_cursor = archive_name_array;
       looped = 1;
     }
 
 tryagain:
   if (looped)
     {
-      /* We have to prompt from now on. */
-      if (f_run_script_at_end)
+      /* We have to prompt from now on.  */
+
+      if (info_script_option)
 	{
-	  closeout_volume_number ();
-	  system (info_script);
+	  if (volno_file_option)
+	    closeout_volume_number ();
+	  system (info_script_option);
 	}
       else
-	for (;;)
+	while (1)
 	  {
-	    fprintf (msg_file, "\007Prepare volume #%d for %s and hit return: ", global_volno, ar_files[cur_ar_file]);
-	    fflush (msg_file);
-	    if (fgets (inbuf, sizeof (inbuf), read_file) == 0)
+	    char input_buffer[80];
+
+	    fprintf (stderr,
+		     _("\007Prepare volume #%d for %s and hit return: "),
+		     global_volno, *archive_name_cursor);
+	    fflush (stderr);
+
+	    if (fgets (input_buffer, sizeof (input_buffer), read_file) == 0)
 	      {
-		fprintf (msg_file, "EOF?  What does that mean?");
-		if (cmd_mode != CMD_EXTRACT && cmd_mode != CMD_LIST && cmd_mode != CMD_DIFF)
-		  msg ("Warning:  Archive is INCOMPLETE!");
-		exit (EX_BADARCH);
+		fprintf (stderr, _("EOF where user reply was expected"));
+
+		if (subcommand_option != EXTRACT_SUBCOMMAND
+		    && subcommand_option != LIST_SUBCOMMAND
+		    && subcommand_option != DIFF_SUBCOMMAND)
+		  WARN ((0, 0, _("WARNING: Archive is incomplete")));
+
+		exit (TAREXIT_FAILURE);
 	      }
-	    if (inbuf[0] == '\n' || inbuf[0] == 'y' || inbuf[0] == 'Y')
+	    if (input_buffer[0] == '\n'
+		|| input_buffer[0] == 'y'
+		|| input_buffer[0] == 'Y')
 	      break;
 
-	    switch (inbuf[0])
+	    switch (input_buffer[0])
 	      {
 	      case '?':
 		{
-		  fprintf (msg_file, "\
- n [name]   Give a new filename for the next (and subsequent) volume(s)\n\
+		  fprintf (stderr, _("\
+ n [name]   Give a new file name for the next (and subsequent) volume(s)\n\
  q          Abort tar\n\
  !          Spawn a subshell\n\
- ?          Print this list\n");
+ ?          Print this list\n"));
 		}
 		break;
 
-	      case 'q':	/* Quit */
-		fprintf (msg_file, "No new volume; exiting.\n");
-		if (cmd_mode != CMD_EXTRACT && cmd_mode != CMD_LIST && cmd_mode != CMD_DIFF)
-		  msg ("Warning:  Archive is INCOMPLETE!");
-		exit (EX_BADARCH);
+	      case 'q':
+		/* Quit.  */
+
+		fprintf (stdlis, _("No new volume; exiting.\n"));
+
+		if (subcommand_option != EXTRACT_SUBCOMMAND
+		    && subcommand_option != LIST_SUBCOMMAND
+		    && subcommand_option != DIFF_SUBCOMMAND)
+		  WARN ((0, 0, _("WARNING: Archive is incomplete")));
+
+		exit (TAREXIT_FAILURE);
+
+	      case 'n':
+		/* Get new file name.  */
 
-	      case 'n':	/* Get new file name */
 		{
-		  char *q, *r;
-		  static char *old_name;
-
-		  for (q = &inbuf[1]; *q == ' ' || *q == '\t'; q++)
-		    ;
-		  for (r = q; *r; r++)
-		    if (*r == '\n')
-		      *r = '\0';
-		  old_name = p = (char *) malloc ((unsigned) (strlen (q) + 2));
-		  if (p == 0)
-		    {
-		      msg ("Can't allocate memory for name");
-		      exit (EX_SYSTEM);
-		    }
-		  (void) strcpy (p, q);
-		  ar_files[cur_ar_file] = p;
+		  char *name = &input_buffer[1];
+		  char *cursor;
+
+		  while (*name == ' ' || *name == '\t')
+		    name++;
+		  cursor = name;
+		  while (*cursor && *cursor != '\n')
+		    cursor++;
+		  *cursor = '\0';
+
+		  /* FIXME: the following allocation is never reclaimed.  */
+		  *archive_name_cursor = xstrdup (name);
 		}
 		break;
 
 	      case '!':
-#ifdef __MSDOS__
+#if MSDOS
 		spawnl (P_WAIT, getenv ("COMSPEC"), "-", 0);
-#else
-		/* JF this needs work! */
+#else /* not MSDOS */
 		switch (fork ())
 		  {
 		  case -1:
-		    msg_perror ("can't fork!");
+		    WARN ((0, errno, _("Cannot fork!")));
 		    break;
+
 		  case 0:
-		    p = getenv ("SHELL");
-		    if (p == 0)
-		      p = "/bin/sh";
-		    execlp (p, "-sh", "-i", 0);
-		    msg_perror ("can't exec a shell %s", p);
-		    _exit (55);
+		    {
+		      const char *shell = getenv ("SHELL");
+
+		      if (shell == NULL)
+			shell = "/bin/sh";
+		      execlp (shell, "-sh", "-i", 0);
+		      FATAL_ERROR ((0, errno, _("Cannot exec a shell %s"),
+				    shell));
+		    }
+
 		  default:
-		    wait (0);
+		    {
+		      WAIT_T wait_status;
+
+		      wait (&wait_status);
+		    }
 		    break;
 		  }
-#endif
+
+		/* FIXME: I'm not sure if that's all that has to be done
+		   here.  (jk)  */
+
+#endif /* not MSDOS */
 		break;
 	      }
 	  }
     }
 
-
-  if (type == 2 || f_verify)
-    archive = rmtopen (ar_files[cur_ar_file], O_RDWR | O_CREAT, 0666);
-  else if (type == 1)
-    archive = rmtopen (ar_files[cur_ar_file], O_RDONLY, 0666);
-  else if (type == 0)
-    archive = rmtcreat (ar_files[cur_ar_file], 0666);
+  if (verify_option)
+    archive = rmtopen (*archive_name_cursor, O_RDWR | O_CREAT, 0666,
+		       rsh_command_option);
   else
-    archive = -1;
+    switch (access)
+      {
+      case ACCESS_READ:
+	archive = rmtopen (*archive_name_cursor, O_RDONLY, 0666,
+			   rsh_command_option);
+	break;
+
+      case ACCESS_WRITE:
+	if (backup_option)
+	  maybe_backup_file (*archive_name_cursor, 1);
+	archive = rmtcreat (*archive_name_cursor, 0666, rsh_command_option);
+	break;
+
+      case ACCESS_UPDATE:
+	archive = rmtopen (*archive_name_cursor, O_RDWR | O_CREAT, 0666,
+			   rsh_command_option);
+	break;
+      }
 
   if (archive < 0)
     {
-      msg_perror ("can't open %s", ar_files[cur_ar_file]);
+      WARN ((0, errno, _("Cannot open %s"), *archive_name_cursor));
+      if (!verify_option && access == ACCESS_WRITE && backup_option)
+	undo_last_backup ();
       goto tryagain;
     }
-#ifdef __MSDOS__
+
+#if MSDOS
   setmode (archive, O_BINARY);
 #endif
-  return 0;
-}
-
-/* this is a useless function that takes a buffer returned by wantbytes
-   and does nothing with it.  If the function called by wantbytes returns
-   an error indicator (non-zero), this function is called for the rest of
-   the file.
- */
-int
-no_op (size, data)
-     int size;
-     char *data;
-{
-  return 0;
-}
 
-/* Some other routine wants SIZE bytes in the archive.  For each chunk of
-   the archive, call FUNC with the size of the chunk, and the address of
-   the chunk it can work with.
- */
-int
-wantbytes (size, func)
-     long size;
-     int (*func) ();
-{
-  char *data;
-  long data_size;
-
-  while (size)
-    {
-      data = findrec ()->charptr;
-      if (data == NULL)
-	{			/* Check it... */
-	  msg ("Unexpected EOF on archive file");
-	  return -1;
-	}
-      data_size = endofrecs ()->charptr - data;
-      if (data_size > size)
-	data_size = size;
-      if ((*func) (data_size, data))
-	func = no_op;
-      userec ((union record *) (data + data_size - 1));
-      size -= data_size;
-    }
-  return 0;
+  return 1;
 }
