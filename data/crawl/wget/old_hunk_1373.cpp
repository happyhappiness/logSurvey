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
src/ChangeLog | 1 +
src/connect.c | 8 ++++----
2 files changed, 5 insertions(+), 4 deletions(-)
