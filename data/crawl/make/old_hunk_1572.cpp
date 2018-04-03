    for (dir = directories[i]; dir != 0; dir = dir->next)
      {
	++dirs;
	if (dir->files == 0)
	  printf ("# %s: could not be opened.\n", dir->name);
	else
	  {
	    register unsigned int f = 0, im = 0;
	    register unsigned int j;
	    register struct dirfile *df;
	    for (j = 0; j < DIRFILE_BUCKETS; ++j)
	      for (df = dir->files[j]; df != 0; df = df->next)
		if (df->impossible)
		  ++im;
		else
		  ++f;
	    printf ("# %s: ", dir->name);
	    if (f == 0)
	      fputs ("No", stdout);
	    else
