
          if (opt.enable_iri && (name = idn_decode ((char *) print)) != NULL)
            {
              str = aprintf ("%s (%s)", name, print);
              xfree (name);
            }

          logprintf (LOG_VERBOSE, _("Connecting to %s|%s|:%d... "),
