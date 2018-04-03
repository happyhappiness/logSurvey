        {
          if (!invalid)
            logprintf (LOG_VERBOSE,
                      _("Incomplete or invalide multibyte sequence encountered\n"));

          invalid++;
          **out = *in;
