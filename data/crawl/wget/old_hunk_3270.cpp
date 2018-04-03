	  logputs (LOG_VERBOSE, "\n");
	  logputs (LOG_NOTQUIET, _("\
Error in server response, closing control connection.\n"));
	  CLOSE (csock);
	  CLOSE (dtsock);
	  CLOSE (local_sock);
	  rbuf_uninitialize (&con->rbuf);
	  return err;
	  break;
