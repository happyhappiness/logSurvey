          abort ();
        }
        if (!opt.server_response)
          logprintf (LOG_VERBOSE, *len ? "%s\n" : _("done.\n"),
                     number_to_static_string (*len));
    }

  /* If anything is to be retrieved, PORT (or PASV) must be sent.  */
