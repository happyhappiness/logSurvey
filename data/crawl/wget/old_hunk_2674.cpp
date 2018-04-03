      const char *e = resp->headers[i + 1];
      /* Skip CRLF */
      if (b < e && e[-1] == '\n')
	--e;
      if (b < e && e[-1] == '\r')
	--e;
      /* This is safe even on printfs with broken handling of "%.<n>s"
	 because resp->headers ends with \0.  */
      logprintf (LOG_VERBOSE, "%s%.*s\n", prefix, e - b, b);
    }
}
