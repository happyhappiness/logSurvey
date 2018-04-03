	  logprintf (LOG_NOTQUIET, "%s: %s\n", con->target, strerror (errno));
	  CLOSE (csock);
	  rbuf_uninitialize (&con->rbuf);
	  closeport (dtsock);
	  return FOPENERR;
	}
    }
