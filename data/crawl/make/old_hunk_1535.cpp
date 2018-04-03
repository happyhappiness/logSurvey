		  }
		else
		  /* This makefile was not found at all.  */
		  switch (d->changed)
		    {
		    case 0:
		      /* A normal makefile.  We must die later.  */
		      error ("Makefile `%s' was not found", dep_name (d));
		      any_failed = 1;
		      break;
		    case 1:
		      /* A makefile from the MAKEFILES variable.
			 We don't care.  */
		      break;
		    case 2:
		      /* An included makefile.  We don't need
			 to die, but we do want to complain.  */
		      error ("Included makefile `%s' was not found.",
			     dep_name (d));
		      break;
		    }

		free ((char *) d);
