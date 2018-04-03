      exit (1);
    }

#ifdef ENABLE_IRI
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
#endif

  if (opt.ask_passwd)
    {
      opt.passwd = prompt_for_password ();
