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
