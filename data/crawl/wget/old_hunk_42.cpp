char *
idn_decode (const char *host)
{
  char *new;
  int ret;

  ret = idna_to_unicode_8zlz (host, &new, IDNA_FLAGS);
  if (ret != IDNA_SUCCESS)
    {
      logprintf (LOG_VERBOSE, _("idn_decode failed (%d): %s\n"), ret,
                 quote (idna_strerror (ret)));
      return NULL;
    }

  return new;
}

/* Try to transcode string str from remote encoding to UTF-8. On success, *new
