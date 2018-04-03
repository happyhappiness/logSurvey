			dir->contents->ino[0], dir->contents->ino[1],
			dir->contents->ino[2]);
#else
	    printf ("# %s (device %ld, inode %ld): ",
		    dir->name,
                    (long)dir->contents->dev, (long)dir->contents->ino);
#endif
#endif /* WINDOWS32 */
	    if (f == 0)
