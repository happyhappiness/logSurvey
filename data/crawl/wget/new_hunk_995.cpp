
  /* Copy server URI encoding for a possible IDNA transformation, no need to
     encode the full URI in UTF-8 because "robots.txt" is plain ASCII */
  set_uri_encoding (i, iri->uri_encoding, false);
  i->utf8_encode = false;

  logputs (LOG_VERBOSE, _("Loading robots.txt; please ignore errors.\n"));
