void
print_dir_data_base ()
{
  register unsigned int i, dirs, files, impossible;
  register struct directory *dir;

  puts (_("\n# Directories\n"));

  dirs = files = impossible = 0;
  for (i = 0; i < DIRECTORY_BUCKETS; ++i)
    for (dir = directories[i]; dir != 0; dir = dir->next)
      {
	++dirs;
	if (dir->contents == 0)
	  printf (_("# %s: could not be stat'd.\n"), dir->name);
	else if (dir->contents->files == 0)
#ifdef WINDOWS32
          printf (_("# %s (key %s, mtime %d): could not be opened.\n"),
                  dir->name, dir->contents->path_key,dir->contents->mtime);
#else  /* WINDOWS32 */
#ifdef VMS
	  printf (_("# %s (device %d, inode [%d,%d,%d]): could not be opened.\n"),
		  dir->name, dir->contents->dev,
		  dir->contents->ino[0], dir->contents->ino[1],
		  dir->contents->ino[2]);
#else
	  printf (_("# %s (device %ld, inode %ld): could not be opened.\n"),
		  dir->name, (long int) dir->contents->dev,
		  (long int) dir->contents->ino);
#endif
#endif /* WINDOWS32 */
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
#ifdef WINDOWS32
            printf (_("# %s (key %s, mtime %d): "),
                    dir->name, dir->contents->path_key, dir->contents->mtime);
#else  /* WINDOWS32 */
#ifdef VMS
	    printf (_("# %s (device %d, inode [%d,%d,%d]): "),
		    dir->name, dir->contents->dev,
			dir->contents->ino[0], dir->contents->ino[1],
			dir->contents->ino[2]);
#else
	    printf (_("# %s (device %ld, inode %ld): "),
		    dir->name,
                    (long)dir->contents->dev, (long)dir->contents->ino);
#endif
#endif /* WINDOWS32 */
	    if (f == 0)
	      fputs (_("No"), stdout);
	    else
	      printf ("%u", f);
	    fputs (_(" files, "), stdout);
	    if (im == 0)
	      fputs (_("no"), stdout);
	    else
	      printf ("%u", im);
	    fputs (_(" impossibilities"), stdout);
	    if (dir->contents->dirstream == 0)
	      puts (".");
	    else
	      puts (_(" so far."));
	    files += f;
	    impossible += im;
	  }
      }

  fputs ("\n# ", stdout);
  if (files == 0)
