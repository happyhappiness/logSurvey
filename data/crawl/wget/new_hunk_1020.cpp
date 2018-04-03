  return true;
}

/* Try opening an iconv_t descriptor for conversion from locale to UTF-8 */
static bool
open_locale_to_utf8 (void)
{
  if (locale2utf8)
    return true;

  /* sXXXav : That shouldn't happen, just in case */
  if (!opt.locale)
    {
      logprintf (LOG_VERBOSE, "open_locale_to_utf8: locale is unset\n");
      opt.locale = find_locale ();
    }

  if (!opt.locale)
    return false;

  locale2utf8 = iconv_open ("UTF-8", opt.locale);
  if (locale2utf8 != (iconv_t)(-1))
    return true;

  logprintf (LOG_VERBOSE, "Conversion from %s to %s isn't supported\n",
             quote (opt.locale), quote("UTF-8"));
  locale2utf8 = NULL;
  return false;
}

/* Return a new string */
const char *
locale_to_utf8 (const char *str)
{
  char *new;

  if (!strcasecmp (opt.locale, "utf-8"))
    return str;

  if (!open_locale_to_utf8 ())
    return str;

  if (do_conversion (locale2utf8, (char *) str, strlen ((char *) str), &new))
    return (const char *) new;

  return str;
}

/* */
static bool
do_conversion (iconv_t cd, char *in, size_t inlen, char **out)
{
  /* sXXXav : hummm hard to guess... */
  size_t len, done, outlen = inlen * 2;
  int invalid = 0, tooshort = 0;
  char *s;

  s = xmalloc (outlen + 1);
  *out = s;
  len = outlen;
  done = 0;

  /* sXXXav : put a maximum looping factor ??? */
  for (;;)
    {
      if (iconv (cd, &in, &inlen, out, &outlen) != (size_t)(-1))
        {
          *out = s;
          *(s + len - outlen - done) = '\0';
          return true;
        }

      /* Incomplete or invalid multibyte sequence */
      if (errno == EINVAL || errno == EILSEQ)
        {
          invalid++;
          **out = *in;
          in++;
          inlen--;
          (*out)++;
          outlen--;
        }
      else if (errno == E2BIG) /* Output buffer full */ 
        {
          char *new;

          tooshort++;
          done = len;
          outlen = done + inlen * 2;
          new = xmalloc (outlen + 1);
          memcpy (new, s, done);
          xfree (s);
          s = new;
          len = outlen;
          *out = s + done;
        }
      else /* Weird, we got an unspecified error */
        {
          logprintf (LOG_VERBOSE, "Unhandled errno %d\n", errno);
          break;
        }
    }

    return false;
}

/* Try to encode UTF-8 host to ASCII. Return the new domain on success or NULL
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
    }

  return new;
}

