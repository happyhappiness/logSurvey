      /* ... but some HTTP/1.0 caches doesn't implement Cache-Control.  */
      request_set_header (req, "Pragma", "no-cache", rel_none);
    }
  if (hs->restval)
    request_set_header (req, "Range",
                        aprintf ("bytes=%s-",
