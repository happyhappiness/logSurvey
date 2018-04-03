
          for (cwd_count = cwd_start; cwd_count < cwd_end; cwd_count++)
            {
          switch (cwd_count)
            {
              case 0:
                /* Step one (optional): Go to the initial directory,
                   exactly as reported by the server.
                */
                targ = con->id;
                break;

              case 1:
                /* Step two: Go to the target directory.  (Absolute or
                   relative will work now.)
                */
                targ = target;
                break;

              case 2:
                /* Step three (optional): "CWD []" to restore server
                   VMS-ness.
                */
                targ = "[]";
                break;

              default:
                logprintf (LOG_ALWAYS, _("Logically impossible section reached in getftp()"));
                logprintf (LOG_ALWAYS, _("cwd_count: %d\ncwd_start: %d\ncwd_end: %d\n"),
                                         cwd_count, cwd_start, cwd_end);
                abort ();
            }

          if (!opt.server_response)
            logprintf (LOG_VERBOSE, "==> CWD (%d) %s ... ", cwd_count,
                       quotearg_style (escape_quoting_style, target));
          err = ftp_cwd (csock, targ);
          /* FTPRERR, WRITEFAILED, FTPNSFOD */
          switch (err)
            {
            case FTPRERR:
              logputs (LOG_VERBOSE, "\n");
              logputs (LOG_NOTQUIET, _("\
Error in server response, closing control connection.\n"));
              fd_close (csock);
              con->csock = -1;
              return err;
            case WRITEFAILED:
              logputs (LOG_VERBOSE, "\n");
              logputs (LOG_NOTQUIET,
                       _("Write failed, closing control connection.\n"));
              fd_close (csock);
              con->csock = -1;
              return err;
            case FTPNSFOD:
              logputs (LOG_VERBOSE, "\n");
              logprintf (LOG_NOTQUIET, _("No such directory %s.\n\n"),
                         quote (u->dir));
              fd_close (csock);
              con->csock = -1;
              return err;
            case FTPOK:
              break;
            default:
              abort ();
            }
          if (!opt.server_response)
            logputs (LOG_VERBOSE, _("done.\n"));

        } /* for */

          /* 2004-09-20 SMS. */
          /* End of deviant indenting. */

        } /* else */
    }
