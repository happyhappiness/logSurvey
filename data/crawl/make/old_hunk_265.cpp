
              if (is_updating (d->file))
                {
                  error (NILF, _("Circular %s <- %s dependency dropped."),
                         file->name, d->file->name);
                  if (ld == 0)
                    {
                      file->deps = d->next;
