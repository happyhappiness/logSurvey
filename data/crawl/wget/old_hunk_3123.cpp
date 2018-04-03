	  return err;
	  break;
	case FTPRESTFAIL:
	  /* If `-c' is specified and the file already existed when
	     Wget was started, it would be a bad idea for us to start
	     downloading it from scratch, effectively truncating it.  */
	  if (opt.always_rest && (cmd & NO_TRUNCATE))
	    {
	      logprintf (LOG_NOTQUIET,
			 _("\nREST failed; will not truncate `%s'.\n"),
			 con->target);
	      fd_close (csock);
	      con->csock = -1;
	      fd_close (dtsock);
	      fd_close (local_sock);
	      return CONTNOTSUPPORTED;
	    }
	  logputs (LOG_VERBOSE, _("\nREST failed, starting from scratch.\n"));
	  restval = 0L;
	  break;
	case FTPOK:
	  /* fine and dandy */
