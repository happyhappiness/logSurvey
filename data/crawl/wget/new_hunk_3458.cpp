lookup_host (const char *host, int silent)
{
  struct address_list *al = NULL;
  unsigned long addr_ipv4;	/* #### use a 32-bit type here. */
  ip_address addr;

  /* First, try to check whether the address is already a numeric
     address.  */

#ifdef INET6
  if (inet_pton (AF_INET6, host, &addr) > 0)
    return address_list_new_one (&addr);
#endif

  addr_ipv4 = (unsigned long)inet_addr (host);
  if ((int)addr_ipv4 != -1)
    {
      /* ADDR is defined to be in network byte order, which is what
	 this returns, so we can just copy it to STORE_IP.  However,
	 on big endian 64-bit architectures the value will be stored
	 in the *last*, not first four bytes.  OFFSET makes sure that
	 we copy the correct four bytes.  */
      int offset = 0;
#ifdef WORDS_BIGENDIAN
      offset = sizeof (unsigned long) - sizeof (ip_address);
#endif
      map_ipv4_to_ip ((ip4_address *)((char *)&addr_ipv4 + offset), &addr);
      return address_list_new_one (&addr);
    }

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

  if (!silent)
    logprintf (LOG_VERBOSE, _("Resolving %s... "), host);

#ifdef INET6
  {
    struct addrinfo hints, *ai;
    int err;

    memset (&hints, 0, sizeof (hints));
    hints.ai_family   = PF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    err = getaddrinfo (host, NULL, &hints, &ai);

    if (err != 0 || ai == NULL)
      {
        if (!silent)
	  logprintf (LOG_VERBOSE, _("failed: %s.\n"), gai_strerror (err));
        return NULL;
      }
    al = address_list_from_addrinfo (ai);
    freeaddrinfo (ai);
  }
#else
  {
    struct hostent *hptr = gethostbyname (host);
    if (!hptr)
      {
	if (!silent)
	  logprintf (LOG_VERBOSE, _("failed: %s.\n"), herrmsg (h_errno));
	return NULL;
      }
    /* Do all systems have h_addr_list, or is it a newer thing?  If
       the latter, use address_list_new_one.  */
    al = address_list_new (hptr->h_addr_list);
  }
#endif

  if (!silent)
    logprintf (LOG_VERBOSE, _("done.\n"));

  /* Cache the lookup information. */
  cache_host_lookup (host, al);

