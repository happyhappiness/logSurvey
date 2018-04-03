        goto http;

      /* Turn "foo.bar.com:path" to "ftp://foo.bar.com/path". */
      if ((ret = aprintf ("ftp://%s", url)) != NULL)
        ret[6 + (p - url)] = '/';
    }
  else
    {
