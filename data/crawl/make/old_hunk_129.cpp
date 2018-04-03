      if (ofile[0])
        if (have_append)
          {
            fprintf (outfile, "$ set noon\n");
            fprintf (outfile, "$ define sys$output %.*s\n", comnamelen-3, child->comname);
            DB (DB_JOBS, (_("Append output to %s\n"), ofile));
            ofiledsc.dsc$w_length = 0;
          }
