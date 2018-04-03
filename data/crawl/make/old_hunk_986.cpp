	  }
#endif

	  if (debug_flag)
	    {
	      char **p;
	      fputs (_("Re-executing:"), stdout);
	      for (p = nargv; *p != 0; ++p)
		printf (" %s", *p);
	      puts ("");
	    }

	  fflush (stdout);
