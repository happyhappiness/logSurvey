      else
        con->csock = -1;

      /* Second: Login with proper USER/PASS sequence.  */
      logprintf (LOG_VERBOSE, _("Logging in as %s ... "),
                 quotearg_style (escape_quoting_style, user));
