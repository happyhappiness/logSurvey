		fatal (NILF, _("Couldn't change back to original directory."));
	    }

          ++restarts;

	  if (ISDB (DB_BASIC))
	    {
	      char **p;
	      printf (_("Re-executing[%u]:"), restarts);
	      for (p = nargv; *p != 0; ++p)
		printf (" %s", *p);
	      putchar ('\n');
	    }

#ifndef _AMIGA
	  for (p = environ; *p != 0; ++p)
            {
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
                }
              if (strneq (*p, "MAKE_RESTARTS=", 14))
                {
                  char *sgi_loses;
                  sgi_loses = (char *) alloca (40);
                  *p = sgi_loses;
                  sprintf (*p, "MAKE_RESTARTS=%u", restarts);
                  restarts = 0;
                }
            }
#else /* AMIGA */
	  {
	    char buffer[256];

            sprintf (buffer, "%u", makelevel);
            SetVar (MAKELEVEL_NAME, buffer, -1, GVF_GLOBAL_ONLY);

            sprintf (buffer, "%u", restarts);
            SetVar ("MAKE_RESTARTS", buffer, -1, GVF_GLOBAL_ONLY);
            restarts = 0;
	  }
#endif

          /* If we didn't set the restarts variable yet, add it.  */
          if (restarts)
            {
              char *b = alloca (40);
              sprintf (b, "MAKE_RESTARTS=%u", restarts);
              putenv (b);
            }

	  fflush (stdout);
	  fflush (stderr);
