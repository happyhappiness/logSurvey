    for (dir = directories[i]; dir != 0; dir = dir->next)
      {
	++dirs;
	if (dir->contents == 0)
	  printf ("# %s: could not be stat'd.\n", dir->name);
	else if (dir->contents->files == 0)
	  printf ("# %s (device %d, inode %d): could not be opened.\n",
		  dir->name, dir->contents->dev, dir->contents->ino);
	else
	  {
	    register unsigned int f = 0, im = 0;
	    register unsigned int j;
	    register struct dirfile *df;
	    for (j = 0; j < DIRFILE_BUCKETS; ++j)
	      for (df = dir->contents->files[j]; df != 0; df = df->next)
		if (df->impossible)
		  ++im;
		else
		  ++f;
	    printf ("# %s (device %d, inode %d): ",
		    dir->name, dir->contents->dev, dir->contents->ino);
	    if (f == 0)
	      fputs ("No", stdout);
	    else
