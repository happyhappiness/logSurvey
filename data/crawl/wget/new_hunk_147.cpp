                      logprintf (LOG_NOTQUIET,
                                 "GPGME new: %s\n",
                                 gpgme_strerror (gpgerr));
                      gpgme_data_release (gpgdata);
                      goto gpg_skip_verification;
                    }

                  DEBUGP (("Veryfying signature %s:\n%s\n",
                           quote (msig->mediatype),
                           msig->signature));

                  /* Check signature type.  */
                  if (!strcmp (msig->mediatype, "application/pgp-signature"))
                    gpgprot = GPGME_PROTOCOL_OpenPGP;
                  else /* Unsupported signature type.  */
                    {
                      gpgme_release (gpgctx);
                      gpgme_data_release (gpgdata);
                      goto gpg_skip_verification;
                    }

                  gpgerr = gpgme_set_protocol (gpgctx, gpgprot);
                  if (gpgerr != GPG_ERR_NO_ERROR)
                    {
                      logprintf (LOG_NOTQUIET,
                                 "GPGME set_protocol: %s\n",
                                 gpgme_strerror (gpgerr));
                      gpgme_release (gpgctx);
                      gpgme_data_release (gpgdata);
                      goto gpg_skip_verification;
                    }

                  /* Load the signature.  */
                  gpgerr = gpgme_data_new_from_mem (&gpgsigdata,
                                                    msig->signature,
                                                    strlen (msig->signature),
                                                    0);
                  if (gpgerr != GPG_ERR_NO_ERROR)
                    {
                      logprintf (LOG_NOTQUIET,
                                 _("GPGME data_new_from_mem: %s\n"),
                                 gpgme_strerror (gpgerr));
                      gpgme_release (gpgctx);
                      gpgme_data_release (gpgdata);
                      goto gpg_skip_verification;
                    }

                  /* Verify the signature.  */
                  gpgerr = gpgme_op_verify (gpgctx, gpgsigdata, gpgdata, NULL);
                  if (gpgerr != GPG_ERR_NO_ERROR)
                    {
                      logprintf (LOG_NOTQUIET,
                                 _("GPGME op_verify: %s\n"),
                                 gpgme_strerror (gpgerr));
                      gpgme_data_release (gpgsigdata);
                      gpgme_release (gpgctx);
                      gpgme_data_release (gpgdata);
                      goto gpg_skip_verification;
                    }

                  /* Check the results.  */
                  gpgres = gpgme_op_verify_result (gpgctx);
                  if (!gpgres)
                    {
                      logputs (LOG_NOTQUIET,
                               _("GPGME op_verify_result: NULL\n"));
                      gpgme_data_release (gpgsigdata);
                      gpgme_release (gpgctx);
                      gpgme_data_release (gpgdata);
                      goto gpg_skip_verification;
                    }

                  /* The list is null-terminated.  */
                  for (gpgsig = gpgres->signatures; gpgsig; gpgsig = gpgsig->next)
                    {
                      DEBUGP (("Checking signature 0x%p\n",
                               (void *) gpgsig));
                      DEBUGP (("Summary=0x%x Status=0x%x\n",
                               gpgsig->summary, gpgsig->status & 0xFFFF));

                      if (gpgsig->summary
                          & (GPGME_SIGSUM_VALID | GPGME_SIGSUM_GREEN))
                        {
                          logputs (LOG_VERBOSE,
                                   _("Signature validation suceeded.\n"));
                          sig_status = 1;
                          break;
                        }

                      if (gpgsig->summary & GPGME_SIGSUM_RED)
                        {
                          logputs (LOG_NOTQUIET,
                                   _("Invalid signature. Rejecting resource.\n"));
                          sig_status = -1;
                          break;
                        }

                      if (gpgsig->summary == 0
                          && (gpgsig->status & 0xFFFF) == GPG_ERR_NO_ERROR)
                        {
                          logputs (LOG_VERBOSE,
                                   _("Data matches signature, but signature "
                                     "is not trusted.\n"));
                        }

                      if ((gpgsig->status & 0xFFFF) != GPG_ERR_NO_ERROR)
                        {
                          logprintf (LOG_NOTQUIET,
                                     "GPGME: %s\n",
                                     gpgme_strerror (gpgsig->status & 0xFFFF));
                        }
                    }
                  gpgme_data_release (gpgsigdata);
                  gpgme_release (gpgctx);
                  gpgme_data_release (gpgdata);
gpg_skip_verification:
                  if (fd != -1)
                    close (fd);
                } /* endif (mfile->signature) */
#endif
              /* Stop if file was downloaded with success.  */
              if (sig_status >= 0)
