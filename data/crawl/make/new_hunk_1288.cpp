#endif

            if (stdin_nm)
              fatal (NILF, "Makefile from standard input specified twice.");

	    outfile = fopen (name, "w");
	    if (outfile == 0)
