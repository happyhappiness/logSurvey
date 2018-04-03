extern int errno;
#endif

#define IP4_ADDRESS_LENGTH 4

/* Mapping between known hosts and to lists of their addresses. */

struct hash_table *host_name_addresses_map;

/* Lists of addresses.  This should eventually be extended to handle
   IPv6.  */

struct address_list {
  int count;			/* number of adrresses */
  unsigned char *buffer;	/* buffer which holds all of them. */

  int refcount;			/* so we know whether to free it or
				   not. */
};

#define ADDR_LOCATION(al, index) ((al)->buffer + index * IP4_ADDRESS_LENGTH)

/* Return the number of addresses in the list. */

int
address_list_count (struct address_list *al)
{
  return al->count;
}

/* Copy address number INDEX to IP_STORE.  */

void
address_list_copy_one (struct address_list *al, int index,
		       unsigned char *ip_store)
{
  memcpy (ip_store, ADDR_LOCATION (al, index), IP4_ADDRESS_LENGTH);
}

/* Check whether two address lists have all their IPs in common.  */

int
address_list_match_all (struct address_list *al1, struct address_list *al2)
{
  if (al1 == al2)
    return 1;
  if (al1->count != al2->count)
    return 0;
  return 0 == memcmp (al1->buffer, al2->buffer,
		      al1->count * IP4_ADDRESS_LENGTH);
}

/* Create an address_list out of a NULL-terminated list of addresses,
   as returned by gethostbyname.  */

static struct address_list *
address_list_new (char **h_addr_list)
{
  int count = 0, i;

  struct address_list *al = xmalloc (sizeof (struct address_list));

  while (h_addr_list[count])
    ++count;
  assert (count > 0);
  al->count    = count;
  al->buffer   = xmalloc (count * IP4_ADDRESS_LENGTH);
  al->refcount = 1;

  for (i = 0; i < count; i++)
    memcpy (ADDR_LOCATION (al, i), h_addr_list[i], IP4_ADDRESS_LENGTH);

  return al;
}

static void
address_list_delete (struct address_list *al)
{
  xfree (al->buffer);
  xfree (al);
}

void
address_list_release (struct address_list *al)
{
  --al->refcount;
  DEBUGP (("Releasing %p (new refcount %d).\n", al, al->refcount));
  if (al->refcount <= 0)
    {
      DEBUGP (("Deleting unused %p.\n", al));
      address_list_delete (al);
    }
}

/* The same as inet_ntoa, but without the need for a cast, or for
   #including the netinet stuff.  */

char *
pretty_print_address (const unsigned char *addr)
{
  return inet_ntoa (*(struct in_addr *)addr);
}

/* Add host name HOST with the address ADDR_TEXT to the cache.
   ADDR_LIST is a NULL-terminated list of addresses, as in struct
   hostent.  */

static void
cache_host_lookup (const char *host, struct address_list *al)
{
  if (!host_name_addresses_map)
    host_name_addresses_map = make_nocase_string_hash_table (0);

  ++al->refcount;
  hash_table_put (host_name_addresses_map, xstrdup_lower (host), al);

#ifdef DEBUG
  if (opt.debug)
    {
      int i;
      debug_logprintf ("Caching %s =>", host);
      for (i = 0; i < al->count; i++)
	debug_logprintf (" %s",
			 pretty_print_address (ADDR_LOCATION (al, i)));
      debug_logprintf ("\n");
    }
#endif
}

struct address_list *
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
      unsigned char tmpstore[IP4_ADDRESS_LENGTH];
      char *lst[] = { tmpstore, NULL };

      /* ADDR is defined to be in network byte order, which is what
	 this returns, so we can just copy it to STORE_IP.  However,
	 on big endian 64-bit architectures the value will be stored
	 in the *last*, not first four bytes.  OFFSET makes sure that
	 we copy the correct four bytes.  */
      int offset;
#ifdef WORDS_BIGENDIAN
      offset = sizeof (unsigned long) - IP4_ADDRESS_LENGTH;
#else
      offset = 0;
#endif
      memcpy (tmpstore, (char *)&addr + offset, IP4_ADDRESS_LENGTH);
      return address_list_new (lst);
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

  /* Look up the host using gethostbyname().  Note that we use
     gethostbyname() rather than ngethostbyname(), because we already
     know that the address is not numerical.  */
  hptr = gethostbyname (host);
  if (!hptr)
    {
      if (!silent)
	logprintf (LOG_VERBOSE, _("failed: %s.\n"), herrmsg (h_errno));
      return NULL;
    }

  if (!silent)
    logprintf (LOG_VERBOSE, _("done.\n"));

  al = address_list_new (hptr->h_addr_list);

  /* Cache the lookup information. */
  cache_host_lookup (host, al);

  return al;
}

/* Determine whether a URL is acceptable to be followed, according to
   a list of domains to accept.  */
int
