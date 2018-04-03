              return err;
            case FTPNSFOD:
              logputs (LOG_VERBOSE, "\n");
              logprintf (LOG_NOTQUIET, _("No such directory %s.\n\n"),
                         quote (escnonprint (u->dir)));
              fd_close (csock);
              con->csock = -1;
              return err;
