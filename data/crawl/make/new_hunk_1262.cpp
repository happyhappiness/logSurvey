	  if (!f->dontcare)
	    {
	      if (sig)
		error (NILF, "*** Deleting intermediate file `%s'", f->name);
	      else if (!silent_flag)
		{
		  if (! doneany)
