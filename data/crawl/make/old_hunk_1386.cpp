  else if (f->last_mtime == (time_t) -1)
    puts ("#  File does not exist.");
  else
#ifdef VMS
    printf ("#  Last modified %.24s (%0lx)\n",
	    cvt_time(f->last_mtime), (unsigned long) f->last_mtime);
#else
    printf ("#  Last modified %.24s (%ld)\n",
	    ctime (&f->last_mtime), (long int) f->last_mtime);
#endif
  printf ("#  File has%s been updated.\n",
	  f->updated ? "" : " not");
  switch (f->command_state)
