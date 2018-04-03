        }

      outfile = output_tmpfile (&child->comname, "sys$scratch:CMDXXXXXX.COM");
      if (outfile == 0)
        pfatal_with_name (_("fopen (temporary file)"));
      comnamelen = strlen (child->comname);

      if (ifile[0])
        {
          fprintf (outfile, "$ assign/user %s sys$input\n", ifile);
