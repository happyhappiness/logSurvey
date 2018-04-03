        continue;

      if (debug_flag)
        printf (_("Reaping %s child 0x%08lx PID %ld token %c%s\n"),
                child_failed ? _("losing") : _("winning"),
                (unsigned long int) c, (long) c->pid, c->job_token,
                c->remote ? _(" (remote)") : "");

      if (c->sh_batch_file) {
