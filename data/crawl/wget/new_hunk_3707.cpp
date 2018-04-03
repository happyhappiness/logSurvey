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
			 u->local);
	      CLOSE (csock);
	      closeport (dtsock);
	      rbuf_uninitialize (&con->rbuf);
	      return CONTNOTSUPPORTED;
	    }
	  logputs (LOG_VERBOSE, _("\nREST failed, starting from scratch.\n"));
	  restval = 0L;
	  break;
