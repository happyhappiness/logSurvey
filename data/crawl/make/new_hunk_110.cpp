         verify". However, the prolog and epilog commands are not shown. Also,
         if output redirection is used, the verification output is redirected
         into that file as well. */
      fprintf (outfile, "$ gnv$$make_verify = \"''f$verify(0)'\"\n");
      fprintf (outfile, "$ gnv$$make_pid = f$getjpi(\"\",\"pid\")\n");
      fprintf (outfile, "$ on error then $ goto gnv$$make_error\n");

      /* Handle append redirection */
      if (append_file != NULL)
        {
          /* If file does not exist, create it */
          fprintf (outfile,
                   "$ gnv$$make_al = \"gnv$$make_append''gnv$$make_pid'\"\n");
          fprintf (outfile,
                   "$ if f$search(\"%s\") .eqs. \"\" then create %s\n",
                   append_file, append_file);

          fprintf (outfile,
                   "$ open/append 'gnv$$make_al' %s\n", append_file);

          /* define sys$output to that file */
          fprintf (outfile,
                   "$ define/user sys$output 'gnv$$make_al'\n");
          DB (DB_JOBS, (_("Append output to %s\n"), append_file));
          free(append_file);
        }

      fprintf (outfile, "$ gnv$$make_verify = f$verify(gnv$$make_verify)\n");

      /* TODO:
         Only for ONESHELL there will be several commands separated by
         '\n'. But there can always be multiple continuation lines.
      */

      fprintf (outfile, "%s\n", cmd_dsc->dsc$a_pointer);
      fprintf (outfile, "$ gnv$$make_status_2 = $status\n");
      fprintf (outfile, "$ goto gnv$$make_exit\n");

      /* Exit and clean up */
      fprintf (outfile, "$ gnv$$make_error: ! 'f$verify(0)\n");
      fprintf (outfile, "$ gnv$$make_status_2 = $status\n");

      if (append_token != -1)
        {
          fprintf (outfile, "$ deassign sys$output\n");
          fprintf (outfile, "$ close 'gnv$$make_al'\n");

          DB (DB_JOBS,
              (_("Append %.*s and cleanup\n"), comnamelen-3, child->comname));
        }
      fprintf (outfile, "$ gnv$$make_exit: ! 'f$verify(0)\n");
      fprintf (outfile,
             "$ exit 'gnv$$make_status_2' + (0*f$verify(gnv$$make_verify))\n");

      fclose (outfile);

      free (cmd_dsc->dsc$a_pointer);
      cmd_dsc->dsc$a_pointer = xmalloc (256 + 4);
      sprintf (cmd_dsc->dsc$a_pointer, "$ @%s", child->comname);
      cmd_dsc->dsc$w_length = strlen (cmd_dsc->dsc$a_pointer);

      DB (DB_JOBS, (_("Executing %s instead\n"), child->comname));
    }

  child->efn = 0;
  while (child->efn < 32 || child->efn > 63)
    {
      status = LIB$GET_EF ((unsigned long *)&child->efn);
      if (!$VMS_STATUS_SUCCESS (status))
        {
          if (child->comname)
            {
