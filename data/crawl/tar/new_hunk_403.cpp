      goto error_loop;		/* try again */
    }

 short_read:
  more = record_start->buffer + status;
  left = record_size - status;

  while (left % BLOCKSIZE != 0)
    {
      while ((status = rmtread (archive, more, left)) < 0)
	read_error ();

      if (status == 0)
	{
	  ERROR ((0, 0, _("%d garbage bytes ignored at end of archive"),
		  (int) ((record_size - left) % BLOCKSIZE)));
	  break;
	}

      if (! read_full_records_option)
	FATAL_ERROR ((0, 0, _("Unaligned block (%lu bytes) in archive"),
		      (unsigned long) (record_size - left)));
	  
      /* User warned us about this.  Fix up.  */

      left -= status;
      more += status;
    }

  /* FIXME: for size=0, multi-volume support.  On the first record, warn
     about the problem.  */

  if (!read_full_records_option && verbose_option
      && record_start_block == 0 && status > 0)
    WARN ((0, 0, _("Record size = %lu blocks"),
	   (unsigned long) ((record_size - left) / BLOCKSIZE)));

  record_end = record_start + (record_size - left) / BLOCKSIZE;
}

/*-----------------------------------------------.
