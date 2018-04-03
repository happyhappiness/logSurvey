          abort ();
        }
        if (!opt.server_response)
          logprintf (LOG_VERBOSE, expected_bytes ? "%s\n" : _("done.\n"),
                     number_to_static_string (expected_bytes));
    }

  /* If anything is to be retrieved, PORT (or PASV) must be sent.  */
