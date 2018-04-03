	  printf ("# %s (device %d, inode %d): could not be opened.\n",
		  dir->name, dir->contents->dev, dir->contents->ino);
#endif
#endif /* WIN32 */
	else
	  {
	    register unsigned int f = 0, im = 0;
