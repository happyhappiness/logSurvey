
      if (opt.enable_iri && (name = idn_decode ((char *) host)) != NULL)
        {
          str = aprintf ("%s (%s)", name, host);
          xfree (name);
        }

      logprintf (LOG_VERBOSE, _("Resolving %s... "),
