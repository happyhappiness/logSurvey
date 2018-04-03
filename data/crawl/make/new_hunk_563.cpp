
  ++jobserver_tokens;

  /* Trace the build.
     Use message here so that changes to working directories are logged.  */
  if (trace_flag)
    {
      char *newer = allocated_variable_expand_for_file ("$?", c->file);
      char *nm;

      if (! cmds->fileinfo.filenm)
        nm = _("<builtin>");
      else
        {
          nm = alloca (strlen (cmds->fileinfo.filenm) + 1 + 11 + 1);
          sprintf (nm, "%s:%lu", cmds->fileinfo.filenm, cmds->fileinfo.lineno);
        }

      if (newer[0] == '\0')
        message (0, _("%s: target `%s' does not exist"), nm, c->file->name);
      else
        message (0, _("%s: update target `%s' due to: %s"), nm,
                 c->file->name, newer);

      free (newer);
    }


  /* The job is now primed.  Start it running.
     (This will notice if there is in fact no recipe.)  */
  start_waiting_job (c);

  if (job_slots == 1 || not_parallel)
