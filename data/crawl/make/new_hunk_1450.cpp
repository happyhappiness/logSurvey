		fatal ("Couldn't change back to original directory.");
	    }

#ifndef _AMIGA
	  for (p = environ; *p != 0; ++p)
	    if (!strncmp (*p, "MAKELEVEL=", 10))
	      {
