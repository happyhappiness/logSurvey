	    printf ("# %s (device %d, inode %d): ",
		    dir->name, dir->contents->dev, dir->contents->ino);
#endif
	    if (f == 0)
	      fputs ("No", stdout);
	    else
