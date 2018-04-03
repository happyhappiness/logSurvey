	  request_free (connreq);
	  if (write_error < 0)
	    {
	      CLOSE_INVALIDATE (sock);
	      return WRITEFAILED;
	    }
