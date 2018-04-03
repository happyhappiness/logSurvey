             DB (DB_JOBS, (_("Redirected output to %s\n"), ofile));
             ofiledsc.dsc$w_length = 0;
           }
-
+      fprintf (outfile, "$ %.*s_ = f$verify(%.*s_1)\n", tmpstrlen, tmpstr, tmpstrlen, tmpstr);
       p = sep = q = cmd;
       for (c = '\n'; c; c = *q++)
         {
