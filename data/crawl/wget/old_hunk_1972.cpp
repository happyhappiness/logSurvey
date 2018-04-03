                    }
                  else
                    {
                      logprintf (LOG_VERBOSE, _("\
Remote file exists but recursion is disabled -- not retrieving.\n\n"));
                      ret = RETROK; /* RETRUNNEEDED is not for caller. */
                      goto exit;
                    }
