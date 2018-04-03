        {
          logprintf (LOG_NOTQUIET,
                     _("Cookie coming from %s attempted to set domain to %s\n"),
                     quotearg_style (escape_quoting_style, host), 
                     quotearg_style (escape_quoting_style, cookie->domain));
          xfree (cookie->domain);
          goto copy_domain;
