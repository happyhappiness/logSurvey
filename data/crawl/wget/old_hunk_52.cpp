                  continue;
                }

              logprintf (LOG_VERBOSE, _("Computing size for %s\n"), quote (destname));

              if (!mfile->size)
                {
                  logprintf (LOG_VERBOSE, _("File size not declared. Skipping check.\n"));
                }
              else
