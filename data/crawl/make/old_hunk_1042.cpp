  if (f->stem != 0)
    printf (_("#  Implicit/static pattern stem: `%s'\n"), f->stem);
  if (f->intermediate)
    puts (_("#  File is an intermediate dependency."));
  if (f->also_make != 0)
    {
      fputs (_("#  Also makes:"), stdout);
