	  if (debug_flag)
	    {
	      char **p;
	      fputs ("Re-executing:", stdout);
	      for (p = nargv; *p != 0; ++p)
		printf (" %s", *p);
	      puts ("");
