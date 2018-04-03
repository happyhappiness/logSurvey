                                 }
                             }
                           else
-                            logputs (LOG_VERBOSE,
-                                     _("Remote file is newer, retrieving.\n"));
+                            {
+                              force_full_retrieve = true;
+                              logputs (LOG_VERBOSE,
+                                       _("Remote file is newer, retrieving.\n"));
+                            }
 
                           logputs (LOG_VERBOSE, "\n");
                         }
