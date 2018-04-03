            DB (DB_JOBS, (_("Redirected output to %s\n"), ofile));
            ofiledsc.dsc$w_length = 0;
          }

      p = sep = q = cmd;
      for (c = '\n'; c; c = *q++)
        {
