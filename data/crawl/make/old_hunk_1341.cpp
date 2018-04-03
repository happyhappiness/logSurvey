			dir->contents->ino[0], dir->contents->ino[1],
			dir->contents->ino[2]);
#else
	    printf ("# %s (device %d, inode %d): ",
		    dir->name, dir->contents->dev, dir->contents->ino);
#endif
#endif /* WINDOWS32 */
	    if (f == 0)
