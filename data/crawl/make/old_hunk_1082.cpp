		else
		  ++f;
#ifdef WINDOWS32
            printf ("# %s (key %s, mtime %d): ",
                    dir->name, dir->contents->path_key, dir->contents->mtime);
#else  /* WINDOWS32 */
#ifdef VMS
	    printf ("# %s (device %d, inode [%d,%d,%d]): ",
		    dir->name, dir->contents->dev,
			dir->contents->ino[0], dir->contents->ino[1],
			dir->contents->ino[2]);
#else
	    printf ("# %s (device %ld, inode %ld): ",
		    dir->name,
                    (long)dir->contents->dev, (long)dir->contents->ino);
#endif
#endif /* WINDOWS32 */
	    if (f == 0)
	      fputs ("No", stdout);
	    else
	      printf ("%u", f);
	    fputs (" files, ", stdout);
	    if (im == 0)
	      fputs ("no", stdout);
	    else
	      printf ("%u", im);
	    fputs (" impossibilities", stdout);
	    if (dir->contents->dirstream == 0)
	      puts (".");
	    else
	      puts (" so far.");
	    files += f;
	    impossible += im;
	  }
