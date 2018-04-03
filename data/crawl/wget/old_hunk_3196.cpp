	  logputs (LOG_NOTQUIET, _("\
Error in server response, closing control connection.\n"));
	  fd_close (csock);
	  rbuf_uninitialize (&con->rbuf);
	  return err;
	  break;
	case WRITEFAILED:
