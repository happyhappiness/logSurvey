	else
	  error_prefix = "";

#if !defined(__MSDOS__) && !defined(_AMIGA)
	if (pipe (pipedes) < 0)
	  {
	    perror_with_name (error_prefix, "pipe");
