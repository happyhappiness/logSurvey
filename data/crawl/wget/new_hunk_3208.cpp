	      fd_close (csock);
	      fd_close (dtsock);
	      fd_close (local_sock);
	      return CONTNOTSUPPORTED;
	    }
	  logputs (LOG_VERBOSE, _("\nREST failed, starting from scratch.\n"));
