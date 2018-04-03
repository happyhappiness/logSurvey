		fatal ("Couldn't change back to original directory.");
	    }

	  for (p = environ; *p != 0; ++p)
	    if (!strncmp (*p, "MAKELEVEL=", 10))
	      {
