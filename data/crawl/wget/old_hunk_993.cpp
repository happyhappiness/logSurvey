      return URLERROR;
    }

  printf ("[Retrieving %s with %s (UTF-8=%d)\n", url, iri->uri_encoding, iri->utf8_encode);

  if (!refurl)
    refurl = opt.referer;
