	printf (" %s", dep_name (d));
      putchar ('\n');
    }
  if (f->last_mtime == (time_t) 0)
    puts ("#  Modification time never checked.");
  else if (f->last_mtime == (time_t) -1)
    puts ("#  File does not exist.");
  else
    printf ("#  Last modified %.24s (%ld)\n",
	    ctime (&f->last_mtime), (long int) f->last_mtime);
  printf ("#  File has%s been updated.\n",
	  f->updated ? "" : " not");
  switch (f->command_state)
