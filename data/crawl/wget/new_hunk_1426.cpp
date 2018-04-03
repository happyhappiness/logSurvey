              if (matchres == -1)
                {
                  logprintf (LOG_NOTQUIET, _("Error matching %s against %s: %s\n"),
                             u->file, quotearg_style (escape_quoting_style, f->name), 
                             strerror (errno));
                  break;
                }
              if (matchres == FNM_NOMATCH)
