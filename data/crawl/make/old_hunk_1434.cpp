	if (dir->contents == 0)
	  printf ("# %s: could not be stat'd.\n", dir->name);
	else if (dir->contents->files == 0)
#ifdef VMS
	  printf ("# %s (device %d, inode [%d,%d,%d]): could not be opened.\n",
		  dir->name, dir->contents->dev,
