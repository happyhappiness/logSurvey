  noexist = this_mtime == NONEXISTENT_MTIME;
  if (noexist)
    DBF (DB_BASIC, _("File `%s' does not exist.\n"));
  else
    {
#ifndef NO_ARCHIVES
      /* Avoid spurious rebuilds of archive members due to their
         timestamp resolution being only one second.  */
      if (1 < FILE_TIMESTAMPS_PER_S && ar_name (file->name))
	this_mtime += FILE_TIMESTAMPS_PER_S - 1;
#endif
    }

  must_make = noexist;
