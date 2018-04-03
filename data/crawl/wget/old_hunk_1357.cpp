          if (*dt & RETROKF)
            {
              logprintf (LOG_VERBOSE,
                         _("%s (%s) - `%s' saved [%s/%s]\n\n"),
                         tms, tmrate, hstat.local_file,
                         number_to_static_string (hstat.len),
                         number_to_static_string (hstat.contlen));
              logprintf (LOG_NONVERBOSE,
