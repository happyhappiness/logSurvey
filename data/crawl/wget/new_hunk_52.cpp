                  continue;
                }

              size_ok = false;
              logprintf (LOG_VERBOSE, _("Computing size for %s\n"), quote (destname));

              if (!mfile->size)
                {
                  size_ok = true;
                  logprintf (LOG_VERBOSE, _("File size not declared. Skipping check.\n"));
                }
              else
