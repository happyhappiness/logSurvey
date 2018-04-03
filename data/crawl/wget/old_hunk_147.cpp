                      logprintf (LOG_NOTQUIET,
                                 "GPGME new: %s\n",
                                 gpgme_strerror (gpgerr));
                      goto gpg_cleanup_data;
                    }

                  /* Note that this will only work for Metalink-over-HTTP
                     requests (that we parse manually) due to a bug in
                     Libmetalink. Another problem with Libmetalink is that
                     it supports at most one signature per file. The below
                     line should be modified after Libmetalink resolves these
                     issues.  */
                  for (msig = mfile->signature; msig == mfile->signature; msig++)
                    {
                      gpgme_signature_t gpgsig;
                      gpgme_protocol_t gpgprot = GPGME_PROTOCOL_UNKNOWN;

                      DEBUGP (("Veryfying signature %s:\n%s\n",
                               quote (msig->mediatype),
                               msig->signature));

                      /* Check signature type.  */
                      if (!strcmp (msig->mediatype, "application/pgp-signature"))
                        gpgprot = GPGME_PROTOCOL_OpenPGP;
                      else /* Unsupported signature type.  */
                        continue;

                      gpgerr = gpgme_set_protocol (gpgctx, gpgprot);
                      if (gpgerr != GPG_ERR_NO_ERROR)
                        {
                          logprintf (LOG_NOTQUIET,
                                     "GPGME set_protocol: %s\n",
                                     gpgme_strerror (gpgerr));
                          continue;
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
                          continue;
                        }

                      /* Verify the signature.  */
                      gpgerr = gpgme_op_verify (gpgctx, gpgsigdata, gpgdata, NULL);
                      if (gpgerr != GPG_ERR_NO_ERROR)
                        {
                          logprintf (LOG_NOTQUIET,
                                     _("GPGME op_verify: %s\n"),
                                     gpgme_strerror (gpgerr));
                          gpgme_data_release (gpgsigdata);
                          continue;
                        }

                      /* Check the results.  */
                      gpgres = gpgme_op_verify_result (gpgctx);
                      if (!gpgres)
                        {
                          logputs (LOG_NOTQUIET,
                                   _("GPGME op_verify_result: NULL\n"));
                          gpgme_data_release (gpgsigdata);
                          continue;
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

                      if (sig_status != 0)
                        break;
                    } /* Iterate over signatures.  */

                  gpgme_release (gpgctx);
gpg_cleanup_data:
                  gpgme_data_release (gpgdata);
gpg_cleanup_fd:
                  close (fd);
                } /* endif (mfile->signature) */
gpg_skip_verification:
#endif
              /* Stop if file was downloaded with success.  */
              if (sig_status >= 0)
