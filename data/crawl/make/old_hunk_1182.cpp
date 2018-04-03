	    {
	      if (d->file->updating)
		{
		  error (NILF, "Circular %s <- %s dependency dropped.",
			 file->name, d->file->name);
		  if (lastd == 0)
		    {
