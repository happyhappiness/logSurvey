	      logputs (LOG_NOTQUIET, _("\
Error in server response, closing control connection.\n"));
	      CLOSE (csock);
	      closeport (dtsock);
	      rbuf_uninitialize (&con->rbuf);
	      return err;
	      break;
