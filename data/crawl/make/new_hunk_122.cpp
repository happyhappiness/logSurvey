            DB (DB_JOBS, (_("Redirected output to %s\n"), ofile));
            ofiledsc.dsc$w_length = 0;
          }
#ifdef USE_DCL_COM_FILE
      /* Export the child environment into DCL symbols */
      if (child->environment != 0)
        {
          char **ep = child->environment;
          char *valstr;
          while (*ep != 0)
            {
              valstr = strchr(*ep, '=');
              if (valstr == NULL)
                continue;
              fprintf(outfile, "$ %.*s=\"%s\"\n", valstr - *ep, *ep,
                  valstr + 1);
              ep++;
            }
        }
#endif
      fprintf (outfile, "$ %.*s_ = f$verify(%.*s_1)\n", tmpstrlen, tmpstr, tmpstrlen, tmpstr);
      p = sep = q = cmd;
      for (c = '\n'; c; c = *q++)
