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

/* Do the conversion according to the passed conversion descriptor cd. *out
   will containes the transcoded string on success. *out content is
   unspecified otherwise. */
static bool
do_conversion (iconv_t cd, char *in, size_t inlen, char **out)
