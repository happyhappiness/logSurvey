                    {
                      logprintf (LOG_NOTQUIET,
                                 _("Checksum mismatch for file %s.\n"),
                                 quote (destname));
                    }

                  /* Stop as soon as we checked the supported checksum.  */
