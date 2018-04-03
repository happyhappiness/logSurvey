        default:
          abort ();
        }

#ifdef HAVE_SSL
      if (using_control_security)
        {
          /* Send the PBSZ and PROT commands, in that order.
           * If we are here it means that the server has already accepted
           * some form of FTPS. Thus, these commands must work.
           * If they don't work, that's an error. There's no sense in honoring
           * --ftps-fallback-to-ftp or similar options. */
          if (u->scheme == SCHEME_FTPS)
            {
              if (!opt.server_response)
                logputs (LOG_VERBOSE, "==> PBSZ 0 ... ");
              if ((err = ftp_pbsz (csock, 0)) == FTPNOPBSZ)
                {
                  logputs (LOG_NOTQUIET, _("Server did not accept the 'PBSZ 0' command.\n"));
                  return err;
                }
              if (!opt.server_response)
                logputs (LOG_VERBOSE, "done.");

              if (!opt.server_response)
                logprintf (LOG_VERBOSE, "  ==> PROT %c ... ", prot);
              if ((err = ftp_prot (csock, prot)) == FTPNOPROT)
                {
                  logprintf (LOG_NOTQUIET, _("Server did not accept the 'PROT %c' command.\n"), prot);
                  return err;
                }
              if (!opt.server_response)
                logputs (LOG_VERBOSE, "done.\n");

              if (prot != PROT_CLEAR)
                {
                  using_data_security = true;
                  con->st |= DATA_CHANNEL_SECURITY;
                }
            }
        }
#endif

      /* Third: Get the system type */
      if (!opt.server_response)
        logprintf (LOG_VERBOSE, "==> SYST ... ");
