  }
#endif

  /* Cache is normally on, but can be turned off with --no-dns-cache.
     Don't cache passive lookups under IPv6.  */
  use_cache = opt.dns_cache;
#ifdef ENABLE_IPV6
  if (flags & LH_BIND)
    use_cache = 0;
#endif

  /* Try to find the host in the cache so we don't need to talk to the
     resolver.  If LH_REFRESH is requested, remove HOST from the cache
     instead.  */
  if (use_cache)
    {
      if (!(flags & LH_REFRESH))
	{
	  al = cache_query (host);
	  if (al)
	    return al;
	}
      else
	cache_remove (host);
    }

  /* No luck with the cache; resolve HOST. */

  if (!silent)
    logprintf (LOG_VERBOSE, _("Resolving %s... "), host);
