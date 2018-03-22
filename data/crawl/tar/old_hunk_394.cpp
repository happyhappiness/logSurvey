
  if (show_version)
    {
      printf ("tar (GNU %s) %s\n", PACKAGE, VERSION);
      fputs (_("\
\n\
Copyright 1988, 92,93,94,95,96,97,98, 1999 Free Software Foundation, Inc.\n"),
	     stdout);
      fputs (_("\
This is free software; see the source for copying conditions.  There is NO\n\
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.\n"),
	     stdout);
      fputs (_("\
\n\
Written by John Gilmore and Jay Fenlason.\n"),
	     stdout);
      exit (TAREXIT_SUCCESS);
    }

