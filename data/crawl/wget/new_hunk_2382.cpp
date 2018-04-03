                time_came_from_head = true;
            }
      
          if (send_head_first)
            {
              /* The time-stamping section.  */
              if (opt.timestamping)
                {
                  if (hstat.orig_file_name) /* Perform the following
                                               checks only if the file
                                               we're supposed to
                                               download already exists.  */
                    {
                      if (hstat.remote_time && 
                          tmr != (time_t) (-1))
                        {
                          /* Now time-stamping can be used validly.
                             Time-stamping means that if the sizes of
                             the local and remote file match, and local
                             file is newer than the remote file, it will
                             not be retrieved.  Otherwise, the normal
                             download procedure is resumed.  */
                          if (hstat.orig_file_tstamp >= tmr)
                            {
                              if (hstat.contlen == -1 
                                  || hstat.orig_file_size == hstat.contlen)
                                {
                                  logprintf (LOG_VERBOSE, _("\
Server file no newer than local file `%s' -- not retrieving.\n\n"),
                                             hstat.orig_file_name);
                                  ret = RETROK;
                                  goto exit;
                                }
                              else
                                {
                                  logprintf (LOG_VERBOSE, _("\
The sizes do not match (local %s) -- retrieving.\n"),
                                             number_to_static_string (hstat.orig_file_size));
                                }
                            }
                          else
                            logputs (LOG_VERBOSE,
                                     _("Remote file is newer, retrieving.\n"));

                          logputs (LOG_VERBOSE, "\n");
                        }
                    }
                  
                  /* free_hstat (&hstat); */
                  hstat.timestamp_checked = true;
                }
              
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
                    {
                      logprintf (LOG_VERBOSE, _("\
Remote file exists but recursion is disabled -- not retrieving.\n\n"));
                      ret = RETROK; /* RETRUNNEEDED is not for caller. */
                      goto exit;
                    }
                }

              got_name = true;
              *dt &= ~HEAD_ONLY;
              count = 0;          /* the retrieve count for HEAD is reset */
              continue;
            } /* send_head_first */
        } /* !got_head */
          
      if ((tmr != (time_t) (-1))
          && ((hstat.len == hstat.contlen) ||
