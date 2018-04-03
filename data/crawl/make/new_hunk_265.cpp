
              if (is_updating (d->file))
                {
                  OSS (error, NILF, _("Circular %s <- %s dependency dropped."),
                       file->name, d->file->name);
                  if (ld == 0)
                    {
                      file->deps = d->next;
