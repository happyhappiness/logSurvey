		if (n > 0 && fwrite (buf, 1, n, outfile) != n)
		  pfatal_with_name ("fwrite (temporary file)");
	      }
	    (void) fclose (outfile);

	    /* Replace the name that read_all_makefiles will
