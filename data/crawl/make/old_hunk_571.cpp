
      if (ofile[0])
	{
	  fprintf (outfile, "$ define sys$output %s\n", ofile);
	  DB (DB_JOBS, (_("Redirected output to %s\n"), ofile));
	  ofiledsc.dsc$w_length = 0;
	}

      p = sep = q = cmd;
