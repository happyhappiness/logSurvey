
        if (read (job_rfd, &token, 1) == 1)
          {
            DB (DB_JOBS, (_("Obtained token for child 0x%08lx (%s).\n"),
                          (unsigned long int) c, c->file->name));
            break;
          }
