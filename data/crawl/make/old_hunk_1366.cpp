	{
	  error ("Circular %s <- %s dependency dropped.",
		 file->name, d->file->name);
	  if (lastd == 0)
	    {
	      file->deps = d->next;
	      free ((char *) d);
	      d = file->deps;
	    }
	  else
	    {
	      lastd->next = d->next;
	      free ((char *) d);
	      d = lastd->next;
	    }
	  continue;
	}

