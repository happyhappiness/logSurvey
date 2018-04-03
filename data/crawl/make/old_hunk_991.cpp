	 or its dependent, FILE, is older or does not exist.  */
      d->changed |= noexist || d_mtime > this_mtime;

      if (debug_flag && !noexist)
	{
	  print_spaces (depth);
	  if (d_mtime == (FILE_TIMESTAMP) -1)
	    printf (_("Prerequisite `%s' does not exist.\n"), dep_name (d));
	  else
	    printf (_("Prerequisite `%s' is %s than target `%s'.\n"),
		    dep_name (d), d->changed ? _("newer") : _("older"), file->name);
	  fflush (stdout);
	}
    }

