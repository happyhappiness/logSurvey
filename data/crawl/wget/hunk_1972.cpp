                     }
                   else
                     {
-                      logprintf (LOG_VERBOSE, _("\
-Remote file exists but recursion is disabled -- not retrieving.\n\n"));
+                      if (*dt & TEXTHTML)
+                        {
+                          logprintf (LOG_VERBOSE, _("\
+Remote file exists and could contain further links,\n\
+but recursion is disabled -- not retrieving.\n\n"));
+                        }
+                      else 
+                        {
+                          logprintf (LOG_VERBOSE, _("\
+Remote file exists.\n\n"));
+                        }
                       ret = RETROK; /* RETRUNNEEDED is not for caller. */
                       goto exit;
                     }
