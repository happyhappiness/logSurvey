	  break;
	}

      /* Print the header if requested.  */
      if (opt.server_response && hcount != 1)
	logprintf (LOG_VERBOSE, "\n%2d %s", hcount, hdr);

      /* Try getting content-length.  */
      if (contlen == -1 && !opt.ignore_length)
	if (header_process (hdr, "Content-Length", header_extract_number,
