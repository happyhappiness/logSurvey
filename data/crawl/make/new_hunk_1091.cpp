  putchar ('\n');

  if (f->precious)
    puts (_("#  Precious file (dependency of .PRECIOUS)."));
  if (f->phony)
    puts (_("#  Phony target (dependency of .PHONY)."));
  if (f->cmd_target)
    puts (_("#  Command-line target."));
  if (f->dontcare)
    puts (_("#  A default or MAKEFILES makefile."));
  printf (_("#  Implicit rule search has%s been done.\n"),
	  f->tried_implicit ? "" : _(" not"));
  if (f->stem != 0)
    printf (_("#  Implicit/static pattern stem: `%s'\n"), f->stem);
  if (f->intermediate)
    puts (_("#  File is an intermediate dependency."));
  if (f->also_make != 0)
    {
      fputs (_("#  Also makes:"), stdout);
      for (d = f->also_make; d != 0; d = d->next)
	printf (" %s", dep_name (d));
      putchar ('\n');
    }
  if (f->last_mtime == 0)
    puts (_("#  Modification time never checked."));
  else if (f->last_mtime == (FILE_TIMESTAMP) -1)
    puts (_("#  File does not exist."));
  else
    {
      char buf[FILE_TIMESTAMP_PRINT_LEN_BOUND + 1];
      file_timestamp_sprintf (buf, f->last_mtime);
      printf (_("#  Last modified %s\n"), buf);
    }
  printf (_("#  File has%s been updated.\n"),
	  f->updated ? "" : _(" not"));
  switch (f->command_state)
    {
    case cs_running:
      puts (_("#  Commands currently running (THIS IS A BUG)."));
      break;
    case cs_deps_running:
      puts (_("#  Dependencies commands running (THIS IS A BUG)."));
      break;
    case cs_not_started:
    case cs_finished:
