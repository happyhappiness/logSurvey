        notice_finished_file (c->file);

      if (debug_flag)
        printf ("Removing child 0x%08lx PID %ld token %c%s from chain.\n",
                (unsigned long int) c, (long) c->pid, c->job_token,
                c->remote ? " (remote)" : "");

      /* Block fatal signals while frobnicating the list, so that
         children and job_slots_used are always consistent.  Otherwise
