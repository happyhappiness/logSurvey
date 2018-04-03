  ret = idna_to_unicode_8zlz (host, &new, IDNA_FLAGS);
  if (ret != IDNA_SUCCESS)
    {
      logprintf (LOG_VERBOSE, _("idn_decode failed (%d): %s\n"), ret,
                 quote (idna_strerror (ret)));
      return NULL;
    }
