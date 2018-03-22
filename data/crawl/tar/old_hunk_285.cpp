  if (show_version)
    {
      printf ("genfile (GNU %s) %s\n", PACKAGE, VERSION);
      fputs (_("\
\n\
Copyright (C) 1995, 1996, 1997 Free Software Foundation, Inc.\n"),
	     stdout);
      fputs (_("\
This is free software; see the source for copying conditions.  There is NO\n\
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.\n"),
	     stdout);
      fputs (_("\
\n\
Written by François Pinard <pinard@iro.umontreal.ca>.\n"),
	     stdout);
      exit (EXIT_SUCCESS);
    }

