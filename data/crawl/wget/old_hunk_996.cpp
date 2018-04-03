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
             quote (opt.locale), quote ("UTF-8"));
  locale2utf8 = NULL;
  return false;
}

/* Try converting string str from locale to UTF-8. Return a new string
