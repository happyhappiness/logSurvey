	      goto done_header;
	    }
	}
    done_header:
      free (hdr);
    }

  logputs (LOG_VERBOSE, "\n");

  if ((statcode == HTTP_STATUS_UNAUTHORIZED)
      && authenticate_h)
    {
