	    f = f->next;
	}
    }
  /* Remove all files with possible harmful names */
  f = orig;
  while (f)
    {
      if (has_insecure_name_p(f->name))
	{
	  logprintf (LOG_VERBOSE, _("Rejecting `%s'.\n"), f->name);
	  f = delelement (f, &start);
	}
      else
	f = f->next;
    }
  /* Now weed out the files that do not match our globbing pattern.
     If we are dealing with a globbing pattern, that is.  */
  if (*u->file && (action == GLOBALL || action == GETONE))
    {
      int matchres = 0;

      f = start;
      while (f)
	{
	  matchres = fnmatch (u->file, f->name, 0);
