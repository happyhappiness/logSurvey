  return true;
}

/* Do the conversion according to the passed conversion descriptor cd. *out
   will contain the transcoded string on success. *out content is
   unspecified otherwise. */
static bool
do_conversion (const char *tocode, const char *fromcode, char *in, size_t inlen, char **out)
{
  iconv_t cd;
  /* sXXXav : hummm hard to guess... */
  size_t len, done, outlen;
  int invalid = 0, tooshort = 0;
  char *s, *in_org, *in_save;

  cd = iconv_open (tocode, fromcode);
  if (cd == (iconv_t)(-1))
    {
      logprintf (LOG_VERBOSE, _("Conversion from %s to %s isn't supported\n"),
                 quote (opt.locale), quote ("UTF-8"));
      return false;
    }

  /* iconv() has to work on an unescaped string */
  in_org = in;
  in_save = in = strndup(in, inlen);
  url_unescape(in);
  inlen = strlen(in);

  len = outlen = inlen * 2;
  *out = s = xmalloc (outlen + 1);
  done = 0;

  for (;;)
