              if (*dt & RETROKF)
                {
                  logprintf (LOG_VERBOSE,
                             _("%s (%s) - `%s' saved [%s]\n\n"),
                             tms, tmrate, hstat.local_file,
                             number_to_static_string (hstat.len));
                  logprintf (LOG_NONVERBOSE,
                             "%s URL:%s [%s] -> \"%s\" [%d]\n",
