Remote file exists.\n\n"));
                        }
                      ret = RETROK; /* RETRUNNEEDED is not for caller. */
                    }
                  
                  if (finished)
                    {
                      logprintf (LOG_NONVERBOSE, 
                                 _("%s URL:%s %2d %s\n"), 
                                 tms, u->url, hstat.statcode,
                                 hstat.message ? escnonprint (hstat.message) : "");
                      goto exit;
                    }
                }
