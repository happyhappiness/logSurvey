#endif

            if (stdin_nm)
              fatal (NILF, _("Makefile from standard input specified twice."));

	    outfile = fopen (name, "w");
	    if (outfile == 0)
	      pfatal_with_name (_("fopen (temporary file)"));
	    while (!feof (stdin))
	      {
		char buf[2048];
		unsigned int n = fread (buf, 1, sizeof(buf), stdin);
		if (n > 0 && fwrite (buf, 1, n, outfile) != n)
		  pfatal_with_name (_("fwrite (temporary file)"));
	      }
	    (void) fclose (outfile);

