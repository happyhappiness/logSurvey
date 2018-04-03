		  }
		else
		  /* This makefile was not found at all.  */
		  if (! (d->changed & RM_DONTCARE))
		    {
		      /* This is a makefile we care about.  See how much.  */
		      if (d->changed & RM_INCLUDED)
			/* An included makefile.  We don't need
			   to die, but we do want to complain.  */
			error ("Included makefile `%s' was not found.",
			       dep_name (d));
		      else
			{
			  /* A normal makefile.  We must die later.  */
			  error ("Makefile `%s' was not found", dep_name (d));
			  any_failed = 1;
			}
		    }

		free ((char *) d);
