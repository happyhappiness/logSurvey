                  logprintf (LOG_NOTQUIET, _("When downloading signature:\n"
                                             "%s: %s.\n"), urlstr, error);
                  xfree (error);
                  iri_free (iri);
                }
              else
                {
