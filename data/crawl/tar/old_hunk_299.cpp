  /* Convert the character to UTF-8.  */
  count = utf8_wctomb ((unsigned char *) inbuf, code);
  if (count < 0)
    error (1, 0, _("U+%04X: character out of range"), code);

  if (is_utf8)
    {
      callback (inbuf, count, callback_arg);
    }
  else
    {
