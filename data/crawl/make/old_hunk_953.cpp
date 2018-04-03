    puts (_("#  Command-line target."));
  if (f->dontcare)
    puts (_("#  A default or MAKEFILES makefile."));
  printf (_("#  Implicit rule search has%s been done.\n"),
	  f->tried_implicit ? "" : _(" not"));
  if (f->stem != 0)
    printf (_("#  Implicit/static pattern stem: `%s'\n"), f->stem);
  if (f->intermediate)
