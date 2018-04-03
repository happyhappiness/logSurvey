      {
	++dirs;
	if (dir->contents == 0)
	  printf ("# %s: could not be stat'd.\n", dir->name);
	else if (dir->contents->files == 0)
#ifdef WINDOWS32
          printf ("# %s (key %s, mtime %d): could not be opened.\n",
                  dir->name, dir->contents->path_key,dir->contents->mtime);
#else  /* WINDOWS32 */
#ifdef VMS
	  printf ("# %s (device %d, inode [%d,%d,%d]): could not be opened.\n",
		  dir->name, dir->contents->dev,
		  dir->contents->ino[0], dir->contents->ino[1],
		  dir->contents->ino[2]);
#else
	  printf ("# %s (device %ld, inode %ld): could not be opened.\n",
		  dir->name, (long int) dir->contents->dev,
		  (long int) dir->contents->ino);
#endif
