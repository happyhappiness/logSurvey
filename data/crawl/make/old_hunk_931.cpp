	  d = file->deps;
	  while (d != 0)
	    {
	      if (d->file->updating)
		{
		  error (NILF, _("Circular %s <- %s dependency dropped."),
			 file->name, d->file->name);
