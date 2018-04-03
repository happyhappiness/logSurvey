           Ignore it; it was inherited from our invoker.  */
        continue;

      if (debug_flag)
        printf (_("Reaping %s child 0x%08lx PID %ld %s\n"),
                child_failed ? _("losing") : _("winning"),
                (unsigned long int) c, (long) c->pid,
                c->remote ? _(" (remote)") : "");

      if (c->sh_batch_file) {
        if (debug_flag)
          printf (_("Cleaning up temp batch file %s\n"), c->sh_batch_file);

        /* just try and remove, don't care if this fails */
        remove (c->sh_batch_file);
