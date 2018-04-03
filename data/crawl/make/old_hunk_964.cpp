      file_timestamp_sprintf (buf, f->last_mtime);
      printf (_("#  Last modified %s\n"), buf);
    }
  printf (_("#  File has%s been updated.\n"),
	  f->updated ? "" : _(" not"));
  switch (f->command_state)
    {
    case cs_running:
