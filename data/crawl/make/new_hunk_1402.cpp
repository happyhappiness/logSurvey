		  ++im;
		else
		  ++f;
#ifdef WINDOWS32
            printf ("# %s (key %s, mtime %d): ",
                    dir->name, dir->contents->path_key, dir->contents->mtime);
#else  /* WINDOWS32 */
#ifdef VMS
	    printf ("# %s (device %d, inode [%d,%d,%d]): ",
		    dir->name, dir->contents->dev,
