      if (!check_domain_match (cookie->domain, host))
        {
          logprintf (LOG_NOTQUIET,
                     _("Cookie coming from %s attempted to set domain to "),
                     quotearg_style (escape_quoting_style, host));
          logprintf (LOG_NOTQUIET,
                     _("%s\n"),
                     quotearg_style (escape_quoting_style, cookie->domain));
          cookie->discard_requested = true;
        }
    }

