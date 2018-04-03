        if (!EINTR_SET)
          pfatal_with_name (_("write jobserver"));

      DB (DB_JOBS, (_("Released token for child 0x%08lx (%s).\n"),
                    (unsigned long int) child, child->file->name));
    }

  if (handling_fatal_signal) /* Don't bother free'ing if about to die.  */
