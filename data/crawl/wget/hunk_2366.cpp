               if (opt.delete_after || opt.spider)
                 {
                   logprintf (LOG_VERBOSE, "Removing %s.\n", rfile);
-                  unlink (rfile);
+                  if (unlink (rfile))
+                      logprintf (LOG_NOTQUIET, "unlink: %s\n",
+                                 strerror (errno));
                 }
 
               xfree (rfile);
