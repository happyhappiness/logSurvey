           if (res_retrieve_file (url, &rfile))
             {
               specs = res_parse_from_file (rfile);
+
+              /* Delete the robots.txt file if we chose to either delete the
+                 files after downloading or we're just running a spider. */
+              if (opt.delete_after || opt.spider)
+                {
+                  logprintf (LOG_VERBOSE, "Removing %s.\n", rfile);
+                  unlink (rfile);
+                }
+
               xfree (rfile);
             }
           else
