            {
            failed_tunnel:
              logprintf (LOG_NOTQUIET, _("Proxy tunneling failed: %s"),
                         message ? quotearg_style (escape_quoting_style, message) : "?");
              xfree_null (message);
              return CONSSLERR;
            }
