  deps->changed = flags;
  deps = 0;

  /* If the makefile can't be found at all, give up entirely.  */

  if (infile == 0)
    {
      /* If we did some searching, errno has the error from the last
	 attempt, rather from FILENAME itself.  Restore it in case the
	 caller wants to use it in a message.  */
      errno = makefile_errno;
      return 0;
    }

  reading_filename = filename;
