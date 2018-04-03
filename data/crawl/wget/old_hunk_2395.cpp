      if (host_lookup_failed)
        {
          request_free (req);
          return HOSTERR;
        }

