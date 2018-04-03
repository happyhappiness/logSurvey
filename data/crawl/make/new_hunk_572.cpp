	    }
  	}

      if (*p)
        {
          fwrite (p, 1, --q - p, outfile);
      fputc ('\n', outfile);
        }

      if (have_append)
        {
          fprintf (outfile, "$ deassign sys$output ! 'f$verify(0)\n");
          fprintf (outfile, "$ append:=append\n");
          fprintf (outfile, "$ delete:=delete\n");
          fprintf (outfile, "$ append/new %.*s %s\n", comnamelen-3, child->comname, ofile);
          fprintf (outfile, "$ delete %.*s;*\n", comnamelen-3, child->comname);
          DB (DB_JOBS, (_("Append %.*s and cleanup\n"), comnamelen-3, child->comname));
        }

      fclose (outfile);

      sprintf (cmd, "$ @%s", child->comname);

      DB (DB_JOBS, (_("Executing %s instead\n"), cmd));
    }
