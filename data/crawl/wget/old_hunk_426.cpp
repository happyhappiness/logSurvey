          statcode = resp_status (resp, &message);
          if (statcode < 0)
            {
              logprintf (LOG_NOTQUIET, _("Invalid server response.\n"));
              CLOSE_INVALIDATE (sock);
              xfree (head);
              return HERR;
            }
