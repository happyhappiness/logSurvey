	}
    }

  if (statcode == HTTP_STATUS_RANGE_NOT_SATISFIABLE)
    {
      /* If `-c' is in use and the file has been fully downloaded (or
	 the remote file has shrunk), Wget effectively requests bytes
	 after the end of file and the server response with 416.  */
      logputs (LOG_VERBOSE, _("\
\n    The file is already fully retrieved; nothing to do.\n\n"));
      /* In case the caller inspects. */
      hs->len = contlen;
      hs->res = 0;
      /* Mark as successfully retrieved. */
      *dt |= RETROKF;
      xfree_null (type);
      CLOSE_INVALIDATE (sock);	/* would be CLOSE_FINISH, but there
				   might be more bytes in the body. */
      return RETRUNNEEDED;
    }
  if ((contrange != 0 && contrange != hs->restval)
      || (H_PARTIAL (statcode) && !contrange))
    {
      /* The Range request was somehow misunderstood by the server.
	 Bail out.  */
      xfree_null (type);
      CLOSE_INVALIDATE (sock);
      return RANGEERR;
