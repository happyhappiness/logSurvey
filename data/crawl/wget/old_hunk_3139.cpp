	  logprintf (LOG_NOTQUIET, _("Read error (%s) in headers.\n"),
		     strerror (errno));
	  CLOSE_INVALIDATE (sock);
	  return HERR;
	}
    }
