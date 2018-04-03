  if (p && *p == ':')
    {
      /* Colon indicates ftp, as in foo.bar.com:path.  Check for
         special case of http port number ("localhost:10000").  */
      int digits = strspn (p + 1, "0123456789");
      if (digits && (p[1 + digits] == '/' || p[1 + digits] == '\0'))
        goto http;

      /* Turn "foo.bar.com:path" to "ftp://foo.bar.com/path". */
      ret = aprintf ("ftp://%s", url);
