                      logprintf (LOG_NONVERBOSE, 
                                 _("%s URL:%s %2d %s\n"), 
                                 tms, u->url, hstat.statcode,
                                 hstat.message ? escnonprint (hstat.message) : "");
                      goto exit;
                    }
                }
