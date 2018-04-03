            {
            failed_tunnel:
              logprintf (LOG_NOTQUIET, _("Proxy tunneling failed: %s"),
                         message ? escnonprint (message) : "?");
              xfree_null (message);
              return CONSSLERR;
            }
