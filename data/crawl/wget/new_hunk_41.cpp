  int ret;
  char *ascii_encoded;
  char *utf8_encoded = NULL;
  const char *src;
  uint8_t *lower;
  size_t len = 0;

  /* Encode to UTF-8 if not done */
  if (!i->utf8_encode)
    {
      if (!remote_to_utf8 (i, host, &utf8_encoded))
          return NULL;  /* Nothing to encode or an error occured */
      src = utf8_encoded;
    }
  else
    src = host;

  if (!_utf8_is_valid (src))
    {
      logprintf (LOG_VERBOSE, _("Invalid UTF-8 sequence: %s\n"),
                 quote (src));
      xfree (utf8_encoded);
      return NULL;
    }

  /* we need a conversion to lowercase */
  lower = u8_tolower ((uint8_t *) src, u8_strlen ((uint8_t *) src) + 1, 0, UNINORM_NFKC, NULL, &len);
  if (!lower)
    {
      logprintf (LOG_VERBOSE, _("Failed to convert to lower: %d: %s\n"),
                 errno, quote (src));
      xfree (utf8_encoded);
      return NULL;
    }

  if ((ret = idn2_lookup_u8 (lower, (uint8_t **) &ascii_encoded, IDN2_NFC_INPUT)) != IDN2_OK)
    {
      logprintf (LOG_VERBOSE, _("idn_encode failed (%d): %s\n"), ret,
                 quote (idn2_strerror (ret)));
      ascii_encoded = NULL;
    }

  xfree (lower);

  return ascii_encoded;
}

