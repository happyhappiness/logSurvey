	    (void) tmpnam (name);
#endif

            if (stdin_nm)
              fatal("Makefile from standard input specified twice.");

	    outfile = fopen (name, "w");
	    if (outfile == 0)
	      pfatal_with_name ("fopen (temporary file)");
