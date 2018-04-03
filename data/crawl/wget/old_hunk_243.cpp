          abort ();
        }
        if (!opt.server_response)
          logprintf (LOG_VERBOSE, expected_bytes ? "%s\n" : _("done.\n"),
                     number_to_static_string (expected_bytes));
    }

  if (cmd & DO_RETR && restval > 0 && restval == expected_bytes)
