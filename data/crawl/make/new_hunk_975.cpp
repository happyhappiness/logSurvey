           Ignore it; it was inherited from our invoker.  */
        continue;

      DB (DB_JOBS, (child_failed
                    ? _("Reaping losing child 0x%08lx PID %ld %s\n")
                    : _("Reaping winning child 0x%08lx PID %ld %s\n"),
                    (unsigned long int) c, (long) c->pid,
                    c->remote ? _(" (remote)") : ""));

      if (c->sh_batch_file) {
        DB (DB_JOBS, (_("Cleaning up temp batch file %s\n"),
                      c->sh_batch_file));

        /* just try and remove, don't care if this fails */
        remove (c->sh_batch_file);
