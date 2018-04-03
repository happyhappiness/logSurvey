                  continue;
                }

              logprintf (LOG_VERBOSE, _("Computing size for %s\n"), quote (filename));

              if (!mfile->size)
                {
                  logprintf (LOG_VERBOSE, _("File size not declared. Skipping check.\n"));
                }
              else
                {
                  wgint local_file_size = file_size (filename);

                  if (local_file_size == -1)
                    {
                      logprintf (LOG_NOTQUIET, _("Could not get downloaded file's size.\n"));
                      fclose (local_file);
                      local_file = NULL;
                      continue;
                    }

                  /* FIXME: what about int64?  */
                  DEBUGP (("Declared size: %lld\n", mfile->size));
                  DEBUGP (("Computed size: %lld\n", (long long) local_file_size));

                  if (local_file_size != (wgint) mfile->size)
                    {
                      logprintf (LOG_NOTQUIET, _("Size mismatch for file %s.\n"), quote (filename));
                      fclose (local_file);
                      local_file = NULL;
                      continue;
                    }
                  else
                    {
                      logputs (LOG_VERBOSE, _("Size matches.\n"));
                    }
                }

              for (mchksum_ptr = mfile->checksums; *mchksum_ptr; mchksum_ptr++)
                {
                  char md2[MD2_DIGEST_SIZE];
