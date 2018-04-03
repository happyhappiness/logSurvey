
  /* sXXXav: could strdupdelim return NULL ? */
  charset = strdupdelim (str, charset);
  logprintf (LOG_VERBOSE, "parse_charset: %s\n", quote (charset));

  return charset;
