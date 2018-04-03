	    }
  	}

      fwrite (p, 1, q - p, outfile);
      fputc ('\n', outfile);

      fclose (outfile);

      sprintf (cmd, "$ @%s", comname);

      DB (DB_JOBS, (_("Executing %s instead\n"), cmd));
    }
