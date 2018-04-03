                      logprintf (LOG_NOTQUIET,
                                 "GPGME data_new_from_fd: %s\n",
                                 gpgme_strerror (gpgerr));
                      goto gpg_cleanup_fd;
                    }

                  /* Prepare new GPGME context.  */
