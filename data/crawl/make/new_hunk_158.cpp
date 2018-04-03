            if (!f->dontcare)
              {
                if (sig)
                  OS (error, NILF,
                      _("*** Deleting intermediate file '%s'"), f->name);
                else
                  {
                    if (! doneany)
