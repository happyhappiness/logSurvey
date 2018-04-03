               only hurts us.  */
            request_remove_header (req, "Authorization");
        }
      else if (host_lookup_failed)
        {
          request_free (req);
          logprintf(LOG_NOTQUIET,
