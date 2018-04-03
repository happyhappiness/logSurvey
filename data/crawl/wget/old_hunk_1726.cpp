
  /* TODO: Ick! This code is now in both gethttp and http_loop, and is
   * screaming for some refactoring. */
  if (got_name && file_exists_p (hstat.local_file) && opt.noclobber)
    {
      /* If opt.noclobber is turned on and file already exists, do not
         retrieve the file */
      logprintf (LOG_VERBOSE, _("\
File `%s' already there; not retrieving.\n\n"), 
                 hstat.local_file);
