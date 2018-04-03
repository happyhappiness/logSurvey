	    {
	      if (sig)
		error (NILF, _("*** Deleting intermediate file `%s'"), f->name);
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
