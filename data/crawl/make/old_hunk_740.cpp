		fatal (NILF, _("Couldn't change back to original directory."));
	    }

#ifndef _AMIGA
	  for (p = environ; *p != 0; ++p)
	    if (strneq (*p, MAKELEVEL_NAME, MAKELEVEL_LENGTH)
		&& (*p)[MAKELEVEL_LENGTH] == '=')
	      {
		/* The SGI compiler apparently can't understand
		   the concept of storing the result of a function
		   in something other than a local variable.  */
		char *sgi_loses;
		sgi_loses = (char *) alloca (40);
		*p = sgi_loses;
		sprintf (*p, "%s=%u", MAKELEVEL_NAME, makelevel);
		break;
	      }
#else /* AMIGA */
	  {
	    char buffer[256];
	    int len;

	    len = GetVar (MAKELEVEL_NAME, buffer, sizeof (buffer), GVF_GLOBAL_ONLY);

	    if (len != -1)
	    {
	    sprintf (buffer, "%u", makelevel);
	      SetVar (MAKELEVEL_NAME, buffer, -1, GVF_GLOBAL_ONLY);
	    }
	  }
#endif

	  if (ISDB (DB_BASIC))
	    {
	      char **p;
	      fputs (_("Re-executing:"), stdout);
	      for (p = nargv; *p != 0; ++p)
		printf (" %s", *p);
	      putchar ('\n');
	    }

	  fflush (stdout);
	  fflush (stderr);
