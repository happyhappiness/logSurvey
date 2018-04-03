                 time_came_from_head = true;
             }
       
-          /* The time-stamping section.  */
-          if (opt.timestamping)
+          if (send_head_first)
             {
-              if (hstat.orig_file_name) /* Perform the following checks only 
-                                           if the file we're supposed to 
-                                           download already exists. */
+              /* The time-stamping section.  */
+              if (opt.timestamping)
                 {
-                  if (hstat.remote_time && 
-                      tmr != (time_t) (-1))
+                  if (hstat.orig_file_name) /* Perform the following
+                                               checks only if the file
+                                               we're supposed to
+                                               download already exists.  */
                     {
-                      /* Now time-stamping can be used validly.  Time-stamping
-                         means that if the sizes of the local and remote file
-                         match, and local file is newer than the remote file,
-                         it will not be retrieved.  Otherwise, the normal
-                         download procedure is resumed.  */
-                      if (hstat.orig_file_tstamp >= tmr)
+                      if (hstat.remote_time && 
+                          tmr != (time_t) (-1))
                         {
-                          if (hstat.contlen == -1 
-                              || hstat.orig_file_size == hstat.contlen)
+                          /* Now time-stamping can be used validly.
+                             Time-stamping means that if the sizes of
+                             the local and remote file match, and local
+                             file is newer than the remote file, it will
+                             not be retrieved.  Otherwise, the normal
+                             download procedure is resumed.  */
+                          if (hstat.orig_file_tstamp >= tmr)
                             {
-                              logprintf (LOG_VERBOSE, _("\
+                              if (hstat.contlen == -1 
+                                  || hstat.orig_file_size == hstat.contlen)
+                                {
+                                  logprintf (LOG_VERBOSE, _("\
 Server file no newer than local file `%s' -- not retrieving.\n\n"),
-                                         hstat.orig_file_name);
-                              ret = RETROK;
-                              goto exit;
-                            }
-                          else
-                            {
-                              logprintf (LOG_VERBOSE, _("\
+                                             hstat.orig_file_name);
+                                  ret = RETROK;
+                                  goto exit;
+                                }
+                              else
+                                {
+                                  logprintf (LOG_VERBOSE, _("\
 The sizes do not match (local %s) -- retrieving.\n"),
-                                         number_to_static_string (hstat.orig_file_size));
+                                             number_to_static_string (hstat.orig_file_size));
+                                }
                             }
-                        }
-                      else
-                        logputs (LOG_VERBOSE,
-                                 _("Remote file is newer, retrieving.\n"));
+                          else
+                            logputs (LOG_VERBOSE,
+                                     _("Remote file is newer, retrieving.\n"));
 
-                      logputs (LOG_VERBOSE, "\n");
+                          logputs (LOG_VERBOSE, "\n");
+                        }
                     }
+                  
+                  /* free_hstat (&hstat); */
+                  hstat.timestamp_checked = true;
                 }
               
-              /* free_hstat (&hstat); */
-              hstat.timestamp_checked = true;
-              restart_loop = true;
-            }
-          
-          if (opt.spider)
-            {
-              if (opt.recursive)
+              if (opt.spider)
                 {
-                  if (*dt & TEXTHTML)
+                  if (opt.recursive)
                     {
-                      logputs (LOG_VERBOSE, _("\
+                      if (*dt & TEXTHTML)
+                        {
+                          logputs (LOG_VERBOSE, _("\
 Remote file exists and could contain links to other resources -- retrieving.\n\n"));
-                      restart_loop = true;
+                        }
+                      else 
+                        {
+                          logprintf (LOG_VERBOSE, _("\
+Remote file exists but does not contain any link -- not retrieving.\n\n"));
+                          ret = RETROK; /* RETRUNNEEDED is not for caller. */
+                          goto exit;
+                        }
                     }
-                  else 
+                  else
                     {
                       logprintf (LOG_VERBOSE, _("\
-Remote file exists but does not contain any link -- not retrieving.\n\n"));
+Remote file exists but recursion is disabled -- not retrieving.\n\n"));
                       ret = RETROK; /* RETRUNNEEDED is not for caller. */
                       goto exit;
                     }
                 }
-              else
-                {
-                  logprintf (LOG_VERBOSE, _("\
-Remote file exists but recursion is disabled -- not retrieving.\n\n"));
-                  ret = RETROK; /* RETRUNNEEDED is not for caller. */
-                  goto exit;
-                }
-            }
 
-          if (send_head_first)
-            {
               got_name = true;
-              restart_loop = true;
-            }
-          
-          got_head = true;    /* no more time-stamping */
-          *dt &= ~HEAD_ONLY;
-          count = 0;          /* the retrieve count for HEAD is reset */
-
-          if (restart_loop) 
-            continue;
-        }
+              *dt &= ~HEAD_ONLY;
+              count = 0;          /* the retrieve count for HEAD is reset */
+              continue;
+            } /* send_head_first */
+        } /* !got_head */
           
       if ((tmr != (time_t) (-1))
           && ((hstat.len == hstat.contlen) ||
