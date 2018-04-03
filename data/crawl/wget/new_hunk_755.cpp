
  /* sXXXav: could strdupdelim return NULL ? */
  charset = strdupdelim (str, charset);

  /* Do a minimum check on the charset value */
  if (!check_encoding_name (charset))
    {
      xfree (charset);
      return NULL;
    }

  logprintf (LOG_VERBOSE, "parse_charset: %s\n", quote (charset));

  return charset;
