      FILE *outfile;
      char c;
      char *sep;
      int alevel = 0;	/* apostrophe level */

      if (strlen (cmd) == 0)
	{
	  printf (_("Error, empty command\n"));
	  fflush (stdout);
	  return 0;
	}

      outfile = open_tmpfile (&child->comname, "sys$scratch:CMDXXXXXX.COM");
      if (outfile == 0)
	pfatal_with_name (_("fopen (temporary file)"));
      comnamelen = strlen (child->comname);

      if (ifile[0])
	{
	  fprintf (outfile, "$ assign/user %s sys$input\n", ifile);
          DB (DB_JOBS, (_("Redirected input from %s\n"), ifile));
	  ifiledsc.dsc$w_length = 0;
	}

      if (efile[0])
	{
	  fprintf (outfile, "$ define sys$error %s\n", efile);
          DB (DB_JOBS, (_("Redirected error to %s\n"), efile));
	  efiledsc.dsc$w_length = 0;
	}

      if (ofile[0])
	{
          if (have_append)
            {
              fprintf (outfile, "$ set noon\n");
              fprintf (outfile, "$ define sys$output %.*s\n", comnamelen-3, child->comname);
              DB (DB_JOBS, (_("Append output to %s\n"), ofile));
              ofiledsc.dsc$w_length = 0;
            }
          else
            {
              fprintf (outfile, "$ define sys$output %s\n", ofile);
              DB (DB_JOBS, (_("Redirected output to %s\n"), ofile));
              ofiledsc.dsc$w_length = 0;
            }
	}

      p = sep = q = cmd;
      for (c = '\n'; c; c = *q++)
	{
	  switch (c)
	    {
            case '\n':
              /* At a newline, skip any whitespace around a leading $
                 from the command and issue exactly one $ into the DCL. */
