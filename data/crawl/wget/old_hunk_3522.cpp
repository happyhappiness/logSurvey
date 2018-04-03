extern int errno;
#endif

/* Mapping between all known hosts to their addresses (n.n.n.n). */

/* #### We should map to *lists* of IP addresses. */

struct hash_table *host_name_address_map;

#if 0

/* This function is no longer used. */

/* The same as gethostbyname, but supports internet addresses of the
   form `N.N.N.N'.  On some systems gethostbyname() knows how to do
   this automatically.  */
struct hostent *
ngethostbyname (const char *name)
{
  struct hostent *hp;
  unsigned long addr;

  addr = (unsigned long)inet_addr (name);
  if ((int)addr != -1)
    hp = gethostbyaddr ((char *)&addr, sizeof (addr), AF_INET);
  else
    hp = gethostbyname (name);
  return hp;
}
#endif

/* Add host name HOST with the address ADDR_TEXT to the cache.  */

static void
add_host_to_cache (const char *host, const char *addr_text)
{
  DEBUGP (("Caching %s => %s\n", host, addr_text));

  if (!host_name_address_map)
    host_name_address_map = make_nocase_string_hash_table (0);

  hash_table_put (host_name_address_map,
		  xstrdup_lower (host), xstrdup (addr_text));
}

/* Store the address of HOSTNAME, internet-style (four octets in
   network order), to WHERE.  First try to get the address from the
   cache; if it is not available, call the DNS functions and update
   the cache.

   Return 1 on successful finding of the hostname, 0 otherwise.  */
int
lookup_host (const char *hostname, unsigned char *store_ip)
{
  unsigned long addr;
  char *addr_text = NULL;
  struct hostent *hptr;
  struct in_addr in;
  char *inet_s;

  /* If the address is of the form d.d.d.d, no further lookup is
     needed.  */
  addr = (unsigned long)inet_addr (hostname);
  if ((int)addr != -1)
    {
      /* ADDR is defined to be in network byte order, which is what
	 this returns, so we can just copy it to STORE_IP.  However,
	 on big endian 64-bit architectures the value will be stored
	 in the *last*, not first four bytes.  OFFSET makes sure that
	 we copy the correct four bytes.  */
      int offset;
    have_addr:
#ifdef WORDS_BIGENDIAN
      offset = sizeof (unsigned long) - 4;
#else
      offset = 0;
#endif
      memcpy (store_ip, (char *)&addr + offset, 4);
      return 1;
    }

  /* By now we know that the host name we got is not of the form
     d.d.d.d.  Try to find it in our cache of host names.  */
  if (host_name_address_map)
    addr_text = hash_table_get (host_name_address_map, hostname);

  if (addr_text)
    {
      DEBUGP (("Found %s in host_name_address_map: %s\n",
	       hostname, addr_text));
      addr = (unsigned long)inet_addr (addr_text);
      goto have_addr;
    }

  /* Look up the host using gethostbyname().  Note that we use
     gethostbyname() rather than ngethostbyname(), because we already
     know that the address is not numerical.  */
  hptr = gethostbyname (hostname);
  if (!hptr)
    return 0;

  /* Store the IP address to the desired location. */
  assert (hptr->h_length == 4);
  memcpy (store_ip, hptr->h_addr_list[0], hptr->h_length);

  /* Now that we've successfully looked up the host, store this
     information in the cache.  */

  /* Originally, we copied to in.s_addr, but it appears to be missing
     on some systems.  */
  memcpy (&in, *hptr->h_addr_list, sizeof (in));
  inet_s = inet_ntoa (in);
  add_host_to_cache (hostname, inet_s);

  return 1;
}

/* Determine whether a URL is acceptable to be followed, according to
   a list of domains to accept.  */
int
