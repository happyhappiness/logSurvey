  if (infile == 0)
    {
      if (type != 1)
	{
	  /* If we did some searching, errno has the error
	     from the last attempt, rather from FILENAME itself.  */
	  errno = makefile_errno;
	  perror_with_name ("fopen: ", filename);
	}
      return;
    }

