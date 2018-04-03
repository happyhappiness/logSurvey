              if (opt.delete_after || opt.spider)
                {
                  logprintf (LOG_VERBOSE, "Removing %s.\n", rfile);
                  unlink (rfile);
                }

              xfree (rfile);
