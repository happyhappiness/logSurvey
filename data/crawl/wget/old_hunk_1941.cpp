                      else
                        sz = -1;
                      logprintf (LOG_NOTQUIET,
                                 _("Wrote HTML-ized index to `%s' [%s].\n"),
                                 filename, number_to_static_string (sz));
                    }
                  else
                    logprintf (LOG_NOTQUIET,
                               _("Wrote HTML-ized index to `%s'.\n"),
                               filename);
                }
              xfree (filename);
            }
