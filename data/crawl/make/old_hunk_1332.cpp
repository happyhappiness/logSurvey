	    {
	      if (d->file->updating)
		{
		  error ("Circular %s <- %s dependency dropped.",
			 file->name, d->file->name);
		  if (lastd == 0)
		    {
