
/* Try to ASCII encode UTF-8 host. Return the new domain on success or NULL
   on error. */
char *idn_encode (char *host)
{
  char *new;
  int ret;

  /* toASCII UTF-8 NULL terminated string */
  ret = idna_to_ascii_8z (host, &new, 0);
  if (ret != IDNA_SUCCESS)
    {
      logprintf (LOG_VERBOSE, "idn_encode failed (%d): %s\n", ret,
                 quote (idna_strerror (ret)));
      return NULL;
