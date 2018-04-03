        notice_finished_file (c->file);

      if (debug_flag)
        printf (_("Removing child 0x%08lx PID %ld %s from chain.\n"),
                (unsigned long int) c, (long) c->pid,
                c->remote ? _(" (remote)") : "");

      /* Block fatal signals while frobnicating the list, so that
