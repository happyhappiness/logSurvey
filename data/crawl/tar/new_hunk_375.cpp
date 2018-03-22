	  && parent_device != current_stat.st_dev)
	{
	  if (verbose_option)
	    WARN ((0, 0, _("%s is on a different filesystem; not dumped"),
		   quote (p)));
	  return;
	}

      /* Now output all the files in the directory.  */

      /* FIXME: Should speed this up by cd-ing into the dir.  */

      while (errno = 0, (entry = readdir (directory)))
	{
	  /* Skip `.', `..', and excluded file names.  */

