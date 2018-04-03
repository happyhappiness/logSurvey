	    f = f->next;
	}
    }
  /* Now weed out the files that do not match our globbing pattern.
     If we are dealing with a globbing pattern, that is.  */
  if (*u->file && (action == GLOBALL || action == GETONE))
    {
      int matchres = 0;
      struct fileinfo *f = start;

      while (f)
	{
	  matchres = fnmatch (u->file, f->name, 0);
