	  all_headers[all_length] = '\0';
	}

      /* Print the header if requested.  */
      if (opt.server_response && hcount != 1)
	logprintf (LOG_VERBOSE, "\n%d %s", hcount, hdr);

      /* Check for status line.  */
      if (hcount == 1)
	{
