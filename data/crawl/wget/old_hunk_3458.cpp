lookup_host (const char *host, int silent)
{
  struct address_list *al = NULL;
  unsigned long addr;
  struct hostent *hptr;

  /* If the address is of the form d.d.d.d, no further lookup is
     needed.  */
  addr = (unsigned long)inet_addr (host);
  if ((int)addr != -1)
    {
      /* ADDR is defined to be in network byte order, which is what
	 this returns, so we can just copy it to STORE_IP.  However,
	 on big endian 64-bit architectures the value will be stored
	 in the *last*, not first four bytes.  OFFSET makes sure that
	 we copy the correct four bytes.  */
      int offset;
#ifdef WORDS_BIGENDIAN
      offset = sizeof (unsigned long) - sizeof (ipv4_address);
#else
      offset = 0;
#endif
      return address_list_new_one ((char *)&addr + offset);
    }

  /* By now we know that the host name we got is not of the form
     d.d.d.d.  Try to find it in our cache of host names.  */
  if (host_name_addresses_map)
    al = hash_table_get (host_name_addresses_map, host);

  if (al)
    {
      DEBUGP (("Found %s in host_name_addresses_map (%p)\n", host, al));
      ++al->refcount;
      return al;
    }

  if (!silent)
    logprintf (LOG_VERBOSE, _("Resolving %s... "), host);

  /* Look up the host using gethostbyname().  */
  hptr = gethostbyname (host);
  if (!hptr)
    {
      if (!silent)
	logprintf (LOG_VERBOSE, _("failed: %s.\n"), herrmsg (h_errno));
      return NULL;
    }

  if (!silent)
    logprintf (LOG_VERBOSE, _("done.\n"));

  /* Do all systems have h_addr_list, or is it a newer thing?  If the
     latter, use address_list_new_one.  */
  al = address_list_new (hptr->h_addr_list);

  /* Cache the lookup information. */
  cache_host_lookup (host, al);

