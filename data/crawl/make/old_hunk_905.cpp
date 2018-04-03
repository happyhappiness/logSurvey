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
