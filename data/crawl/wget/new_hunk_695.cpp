      return URLERROR;
    }

  DEBUGP (("[IRI Retrieving %s with %s (UTF-8=%d)\n", quote (url),
             quote (iri->uri_encoding), iri->utf8_encode));

  if (!refurl)
    refurl = opt.referer;
