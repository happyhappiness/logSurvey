	  logprintf (LOG_NOTQUIET, "%s: %s\n", *hs->local_file, strerror (errno));
	  CLOSE_INVALIDATE (sock); /* would be CLOSE_FINISH, but there
				      might be more bytes in the body. */
	  return FOPENERR;
	}
    }
