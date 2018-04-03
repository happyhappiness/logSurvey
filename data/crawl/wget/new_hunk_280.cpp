                 files after downloading or we're just running a spider. */
              if (opt.delete_after || opt.spider)
                {
                  logprintf (LOG_VERBOSE, _("Removing %s.\n"), rfile);
                  if (unlink (rfile))
                      logprintf (LOG_NOTQUIET, "unlink: %s\n",
                                 strerror (errno));
