               || c_strcasecmp (opt.method, "patch") == 0)
        request_set_header (req, "Content-Length", "0", rel_none);
    }

 retry_with_auth:
  /* We need to come back here when the initial attempt to retrieve
     without authorization header fails.  (Expected to happen at least
