		  dir->contents->ino[0], dir->contents->ino[1],
		  dir->contents->ino[2]);
#else
	  printf ("# %s (device %d, inode %d): could not be opened.\n",
		  dir->name, dir->contents->dev, dir->contents->ino);
#endif
#endif /* WIN32 */
	else
