       else if (size >= FMT_MAX_LENGTH)  /* We have a huge buffer, */
         {                               /* maybe we have some wrong
                                            format string? */
-          logprintf (LOG_ALWAYS, 
+          logprintf (LOG_ALWAYS,
                      _("%s: aprintf: text buffer is too big (%ld bytes), "
                        "aborting.\n"),
                      exec_name, size);  /* printout a log message */
