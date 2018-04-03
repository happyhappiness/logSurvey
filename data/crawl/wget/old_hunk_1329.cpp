              
              if (opt.spider)
                {
                  if (opt.recursive)
                    {
                      if (*dt & TEXTHTML)
                        {
                          logputs (LOG_VERBOSE, _("\
Remote file exists and could contain links to other resources -- retrieving.\n\n"));
                        }
                      else 
                        {
                          logprintf (LOG_VERBOSE, _("\
Remote file exists but does not contain any link -- not retrieving.\n\n"));
                          ret = RETROK; /* RETRUNNEEDED is not for caller. */
                          goto exit;
                        }
                    }
                  else
