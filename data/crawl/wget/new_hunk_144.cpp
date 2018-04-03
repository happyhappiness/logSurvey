#endif
      || (proxy_url && proxy_url->scheme == SCHEME_HTTP))
    {
#ifdef HAVE_HSTS
#ifdef TESTING
      /* we don't link against main.o when we're testing */
      hsts_store_t hsts_store = NULL;
#else
      extern hsts_store_t hsts_store;
#endif

      if (opt.hsts && hsts_store)
	{
	  if (hsts_match (hsts_store, u))
	    logprintf (LOG_VERBOSE, "URL transformed to HTTPS due to an HSTS policy\n");
	}
#endif
      result = http_loop (u, orig_parsed, &mynewloc, &local_file, refurl, dt,
                          proxy_url, iri);
    }
