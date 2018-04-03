  deps->changed = flags;
  deps = 0;

  /* If the makefile can't be found at all,
     either ignore it or give up entirely.  */

  if (infile == 0)
    {
      if (! (flags & RM_DONTCARE))
	{
	  /* If we did some searching, errno has the error
	     from the last attempt, rather from FILENAME itself.  */
	  errno = makefile_errno;
	  perror_with_name ("fopen: ", filename);
	}
      return;
    }

  reading_filename = filename;
