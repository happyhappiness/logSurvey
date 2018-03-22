  /* Convert the character to UTF-8.  */
  count = utf8_wctomb ((unsigned char *) inbuf, code);
  if (count < 0)
    {
      errno = EILSEQ;
      return failure (code, callback_arg);
    }

  if (is_utf8)
    {
      return success (inbuf, count, callback_arg);
    }
  else
    {
