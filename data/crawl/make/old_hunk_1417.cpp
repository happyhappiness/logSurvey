	    {
	      char **p;
	      fputs ("Re-executing:", stdout);
	      for (p = argv; *p != 0; ++p)
		printf (" %s", *p);
	      puts ("");
	    }
