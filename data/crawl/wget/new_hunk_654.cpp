
/* Try to ASCII encode UTF-8 host. Return the new domain on success or NULL
   on error. */
char *
idn_encode (char *host, bool utf8_encoded)
{
  char *new;
  int ret;

  /* Encode to UTF-8 if not done using current remote */
  if (!utf8_encoded)
    {
      if (!remote_to_utf8 ((const char *) host, (const char **) &new))
        {
          /* Nothing to encode or an error occured */
          return NULL;
        }

      host = new;
    }

  /* toASCII UTF-8 NULL terminated string */
  ret = idna_to_ascii_8z (host, &new, 0);
  if (ret != IDNA_SUCCESS)
    {
      /* sXXXav : free new when needed ! */
      logprintf (LOG_VERBOSE, "idn_encode failed (%d): %s\n", ret,
                 quote (idna_strerror (ret)));
      return NULL;
