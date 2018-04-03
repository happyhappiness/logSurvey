
  l2u = iconv_open ("UTF-8", opt.locale);
  if (l2u != (iconv_t)(-1))
    {
      logprintf (LOG_VERBOSE, _("Conversion from %s to %s isn't supported\n"),
                 quote (opt.locale), quote ("UTF-8"));
      return str;
