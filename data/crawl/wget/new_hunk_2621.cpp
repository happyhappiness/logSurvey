              got_name = true;
              restart_loop = true;
            }
          
          if (opt.spider)
            {
              if (opt.recursive)
                {
                  if (*dt & TEXTHTML)
                    {
                      logputs (LOG_VERBOSE, _("\
Remote file exists and could contain links to other resources -- retrieving.\n\n"));
                      restart_loop = true;
                    }
                  else 
                    {
                      logprintf (LOG_VERBOSE, _("\
Remote file exists but does not contain any link -- not retrieving.\n\n"));
                      ret = RETRUNNEEDED;
                      goto exit;
                    }
                }
              else
                {
                  logprintf (LOG_VERBOSE, _("\
Remote file exists but recursion is disabled -- not retrieving.\n\n"));
                  ret = RETRUNNEEDED;
                  goto exit;
                }
            }

          got_head = true;    /* no more time-stamping */
          *dt &= ~HEAD_ONLY;
