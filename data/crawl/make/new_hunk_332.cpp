  for ( ; file_slot < file_end; file_slot++)
    if (! HASH_VACANT (*file_slot))
      {
        struct file *f = *file_slot;
        /* Is this file eligible for automatic deletion?
           Yes, IFF: it's marked intermediate, it's not secondary, it wasn't
           given on the command line, and it's either a -include makefile or
           it's not precious.  */
        if (f->intermediate && (f->dontcare || !f->precious)
            && !f->secondary && !f->cmd_target)
          {
            int status;
            if (f->update_status == -1)
              /* If nothing would have created this file yet,
                 don't print an "rm" command for it.  */
              continue;
            if (just_print_flag)
              status = 0;
            else
              {
                status = unlink (f->name);
                if (status < 0 && errno == ENOENT)
                  continue;
              }
            if (!f->dontcare)
              {
                if (sig)
                  error (NILF, _("*** Deleting intermediate file '%s'"), f->name);
                else
                  {
                    if (! doneany)
                      DB (DB_BASIC, (_("Removing intermediate files...\n")));
                    if (!silent_flag)
                      {
                        if (! doneany)
                          {
                            fputs ("rm ", stdout);
                            doneany = 1;
                          }
                        else
                          putchar (' ');
                        fputs (f->name, stdout);
                        fflush (stdout);
                      }
                  }
                if (status < 0)
                  perror_with_name ("unlink: ", f->name);
              }
          }
      }

  if (doneany && !sig)
