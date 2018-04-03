  if (opt.enable_iri)
    {
      if (!opt.locale)
        {
          opt.locale = getenv ("CHARSET");

          if (opt.locale == NULL)
            opt.locale = nl_langinfo(CODESET);
        }
      else
        {
          /* sXXXav : check given locale */
          logprintf (LOG_VERBOSE, "Check the locale...\n");
        }
    }
#else
  if (opt.enable_iri || opt.locale || opt.encoding_remote)
