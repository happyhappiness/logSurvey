
          if (is_updating (d->file))
            {
              OSS (error, NILF, _("Circular %s <- %s dependency dropped."),
                   file->name, d->file->name);
              /* We cannot free D here because our the caller will still have
                 a reference to it when we were called recursively via
                 check_dep below.  */
