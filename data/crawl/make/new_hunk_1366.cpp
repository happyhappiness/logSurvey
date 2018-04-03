	{
	  error ("Circular %s <- %s dependency dropped.",
		 file->name, d->file->name);
	  /* We cannot free D here because our the caller will still have
	     a reference to it when we were called recursively via
	     check_dep below.  */
	  if (lastd == 0)
	    file->deps = d->next;
	  else
	    lastd->next = d->next;
	  d = d->next;
	  continue;
	}

