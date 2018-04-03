      /* Incomplete or invalid multibyte sequence */
      if (errno == EINVAL || errno == EILSEQ)
        {
          if (!invalid)
            logprintf (LOG_VERBOSE,
                      "Incomplete or invalide multibyte sequence encountered\n");

          invalid++;
          **out = *in;
          in++;
