	  logputs (LOG_NOTQUIET, _("\
Error in server response, closing control connection.\n"));
	  fd_close (csock);
	  return err;
	  break;
	case FTPOK:
