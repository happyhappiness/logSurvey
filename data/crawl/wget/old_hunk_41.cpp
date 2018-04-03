  int ret;
  char *ascii_encoded;
  char *utf8_encoded = NULL;

  /* Encode to UTF-8 if not done */
  if (!i->utf8_encode)
    {
      if (!remote_to_utf8 (i, host, &utf8_encoded))
          return NULL;  /* Nothing to encode or an error occured */
    }

  if (!_utf8_is_valid(utf8_encoded ? utf8_encoded : host))
    {
      logprintf (LOG_VERBOSE, _("Invalid UTF-8 sequence: %s\n"),
                 quote(utf8_encoded ? utf8_encoded : host));
      xfree (utf8_encoded);
      return NULL;
    }

  /* Store in ascii_encoded the ASCII UTF-8 NULL terminated string */
  ret = idna_to_ascii_8z (utf8_encoded ? utf8_encoded : host, &ascii_encoded, IDNA_FLAGS);
  xfree (utf8_encoded);

  if (ret != IDNA_SUCCESS)
    {
      logprintf (LOG_VERBOSE, _("idn_encode failed (%d): %s\n"), ret,
                 quote (idna_strerror (ret)));
      return NULL;
    }

  return ascii_encoded;
}

