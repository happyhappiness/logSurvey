	  if (!f->dontcare)
	    {
	      if (sig)
		error (NILF, _("*** Deleting intermediate file `%s'"), f->name);
	      else if (!silent_flag)
		{
		  if (! doneany)
