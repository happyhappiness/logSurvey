
  ++jobserver_tokens;

  /* The job is now primed.  Start it running.
     (This will notice if there is in fact no recipe.)  */
  if (cmds->fileinfo.filenm)
    DB (DB_BASIC, (_("Invoking recipe from %s:%lu to update target `%s'.\n"),
                   cmds->fileinfo.filenm, cmds->fileinfo.lineno,
                   c->file->name));
  else
    DB (DB_BASIC, (_("Invoking builtin recipe to update target `%s'.\n"),
                   c->file->name));


  start_waiting_job (c);

  if (job_slots == 1 || not_parallel)
