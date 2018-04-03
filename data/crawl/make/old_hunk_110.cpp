         verify". However, the prolog and epilog commands are not shown. Also,
         if output redirection is used, the verification output is redirected
         into that file as well. */
      fprintf (outfile, "$ %.*s_1 = \"''f$verify(0)'\"\n", tmpstrlen, tmpstr);
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
        if (have_append)
          {
            fprintf (outfile, "$ define sys$output %.*s\n", comnamelen-3, child->comname);
            fprintf (outfile, "$ on error then $ goto %.*s\n", tmpstrlen, tmpstr);
            DB (DB_JOBS, (_("Append output to %s\n"), ofile));
            ofiledsc.dsc$w_length = 0;
          }
        else
          {
            fprintf (outfile, "$ define sys$output %s\n", ofile);
            DB (DB_JOBS, (_("Redirected output to %s\n"), ofile));
            ofiledsc.dsc$w_length = 0;
          }

      /* Export the child environment into DCL symbols */
      if (vms_always_use_cmd_file || (child->environment != 0))
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

      fprintf (outfile, "$ %.*s_ = f$verify(%.*s_1)\n", tmpstrlen, tmpstr, tmpstrlen, tmpstr);

      /* TODO: give 78 a name! Whether 78 is a good number is another question.
         Trim, split and write the command lines.
         Splitting of a command is done after 78 output characters at an
         appropriate place (after strings, after comma or space and
         before slash): appending a hyphen indicates that the DCL command
         is being continued.
         Trimming is to skip any whitespace around - including - a
         leading $ from the command to ensure writing exactly one "$ "
         at the beginning of the line of the output file. Trimming is
         done when a new command is seen, indicated by a '\n' (outside
         of a string).
         The buffer so far is written and reset, when a new command is
         seen, when a split was done and at the end of the command.
         Only for ONESHELL there will be several commands separated by
         '\n'. But there can always be multiple continuation lines. */
      p = sep = q = cmd;
      for (c = '\n'; c; c = *q++)
        {
          switch (c)
          {
          case '\n':
            if (q > p)
              {
                fwrite(p, 1, q - p, outfile);
                p = q;
              }
            fputc('$', outfile);
            fputc(' ', outfile);
            while (isspace((unsigned char) *p))
              p++;
            if (*p == '$')
              p++;
            while (isspace((unsigned char) *p))
              p++;
            q = sep = p;
            break;
          case '"':
            q = vms_handle_apos(q);
            sep = q;
            break;
          case ',':
          case ' ':
            sep = q;
            break;
          case '/':
          case '\0':
            sep = q - 1;
            break;
          default:
            break;
          }
          if (sep - p > 78)
            {
              /* Enough stuff for a line. */
              fwrite(p, 1, sep - p, outfile);
              p = sep;
              if (*sep)
                {
                  /* The command continues.  */
                  fputc('-', outfile);
                }
              fputc('\n', outfile);
            }
        }

      if (*p)
        {
          fwrite(p, 1, --q - p, outfile);
          fputc('\n', outfile);
        }

      if (have_append)
        {
          fprintf (outfile, "$ %.*s: ! 'f$verify(0)\n", tmpstrlen, tmpstr);
          fprintf (outfile, "$ %.*s_2 = $status\n", tmpstrlen, tmpstr);
          fprintf (outfile, "$ on error then $ exit\n");
          fprintf (outfile, "$ deassign sys$output\n");
          if (efile[0])
            fprintf (outfile, "$ deassign sys$error\n");
          fprintf (outfile, "$ append:=append\n");
          fprintf (outfile, "$ delete:=delete\n");
          fprintf (outfile, "$ append/new %.*s %s\n", comnamelen-3, child->comname, ofile);
          fprintf (outfile, "$ delete %.*s;*\n", comnamelen-3, child->comname);
          fprintf (outfile, "$ exit '%.*s_2 + (0*f$verify(%.*s_1))\n", tmpstrlen, tmpstr, tmpstrlen, tmpstr);
          DB (DB_JOBS, (_("Append %.*s and cleanup\n"), comnamelen-3, child->comname));
        }

      fclose (outfile);

      sprintf (cmd, "$ @%s", child->comname);

      DB (DB_JOBS, (_("Executing %s instead\n"), cmd));
    }

  cmddsc.dsc$w_length = strlen(cmd);
  cmddsc.dsc$a_pointer = cmd;
  cmddsc.dsc$b_dtype = DSC$K_DTYPE_T;
  cmddsc.dsc$b_class = DSC$K_CLASS_S;

  child->efn = 0;
  while (child->efn < 32 || child->efn > 63)
    {
      status = lib$get_ef ((unsigned long *)&child->efn);
      if (!(status & 1))
        {
          if (child->comname)
            {
