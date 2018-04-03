    puts (_("#  File is an intermediate prerequisite."));
  if (f->also_make != 0)
    {
      const struct dep *d;
      fputs (_("#  Also makes:"), stdout);
      for (d = f->also_make; d != 0; d = d->next)
	printf (" %s", dep_name (d));
