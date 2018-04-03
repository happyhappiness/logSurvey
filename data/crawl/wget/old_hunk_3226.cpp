  }
#endif

  /* Try to find the host in the cache. */

  if (host_name_addresses_map)
    {
      al = hash_table_get (host_name_addresses_map, host);
      if (al)
	{
	  DEBUGP (("Found %s in host_name_addresses_map (%p)\n", host, al));
	  ++al->refcount;
	  return al;
	}
    }

  /* No luck with the cache; resolve the host name. */

  if (!silent)
    logprintf (LOG_VERBOSE, _("Resolving %s... "), host);
