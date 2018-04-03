                       logprintf (LOG_NOTQUIET,
                                  "GPGME data_new_from_fd: %s\n",
                                  gpgme_strerror (gpgerr));
-                      goto gpg_cleanup_fd;
+                      goto gpg_skip_verification;
                     }
 
                   /* Prepare new GPGME context.  */
