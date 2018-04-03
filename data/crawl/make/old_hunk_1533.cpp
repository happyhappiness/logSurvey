  if (! debug_flag)
    return;

  printf ("%s access: user %d (real %d), group %d (real %d)\n",
	  flavor, geteuid (), getuid (), getegid (), getgid ());
  fflush (stdout);
}


