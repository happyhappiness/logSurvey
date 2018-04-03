extern int errno;
#endif


/**
  * sockaddr_set_data
  *
  * This function takes a sockaddr struct and fills in the protocol
  * type, the port number and the address.  If ENABLE_IPV6 is defined,
  * SA should really point to struct sockaddr_storage; otherwise, it
  * should point to struct sockaddr_in.
  *
  * Input:
  * struct sockaddr*	The space to be filled
  * const ip_address	The IP address
  * int			The port
  *
  * Return:
  * -			Only modifies 1st parameter.
  */
static void
sockaddr_set_data (struct sockaddr *sa, const ip_address *addr, int port)
{
  if (addr->type == IPV4_ADDRESS)
    {
      struct sockaddr_in *sin = (struct sockaddr_in *)sa;
      sin->sin_family = AF_INET;
      sin->sin_port = htons (port);
      if (addr == NULL)
	sin->sin_addr.s_addr = INADDR_ANY;
      else
	sin->sin_addr = ADDRESS_IPV4_IN_ADDR (addr);
    }
#ifdef ENABLE_IPV6
  else if (addr->type == IPV6_ADDRESS) 
    {
      struct sockaddr_in6 *sin6 = (struct sockaddr_in6 *)sa;
      sin6->sin6_family = AF_INET6;
      sin6->sin6_port = htons (port);
      /* #### How can ADDR be NULL?  We have dereferenced it above by
	 accessing addr->type!  */
      if (addr == NULL)
	{
	  sin6->sin6_addr = in6addr_any;
	  /* #### Should we set the scope_id here? */
	}
      else
	{
	  sin6->sin6_addr = ADDRESS_IPV6_IN6_ADDR (addr);
#ifdef HAVE_SOCKADDR_IN6_SCOPE_ID
	  sin6->sin6_scope_id = ADDRESS_IPV6_SCOPE (addr);
#endif
	}
    }
#endif /* ENABLE_IPV6 */
  else
    abort ();
}

/* Get the data of SA, specifically the IP address and the port.  If
   you're not interested in one or the other information, pass NULL as
   the pointer.  */

void
sockaddr_get_data (const struct sockaddr *sa, ip_address *ip, int *port)
{
  if (sa->sa_family == AF_INET)
    {
      struct sockaddr_in *sin = (struct sockaddr_in *)sa;
      if (ip)
	{
	  ip->type = IPV4_ADDRESS;
	  ADDRESS_IPV4_IN_ADDR (ip) = sin->sin_addr;
	}
      if (port)
	*port = ntohs (sin->sin_port);
    }
#ifdef ENABLE_IPV6
  else if (sa->sa_family == AF_INET6) 
    {
      struct sockaddr_in6 *sin6 = (struct sockaddr_in6 *)sa;
      if (ip)
	{
	  ip->type = IPV6_ADDRESS;
	  ADDRESS_IPV6_IN6_ADDR (ip) = sin6->sin6_addr;
#ifdef HAVE_SOCKADDR_IN6_SCOPE_ID
	  ADDRESS_IPV6_SCOPE (ip) = sin6->sin6_scope_id;
#endif
	}
      if (port)
	*port = ntohs (sin6->sin6_port);
    }
#endif  
  else
    abort ();
}

/* Return the size of the sockaddr structure depending on its
   family.  */

static socklen_t
sockaddr_size (const struct sockaddr *sa)
{
  switch (sa->sa_family)
    {
    case AF_INET:
      return sizeof (struct sockaddr_in);
#ifdef ENABLE_IPV6
    case AF_INET6:
      return sizeof (struct sockaddr_in6);
#endif
    default:
      abort ();
      return 0;			/* so the compiler shuts up. */
    }
}

static int
resolve_bind_address (const char *host, struct sockaddr *sa, int flags)
{
  struct address_list *al;

  /* #### Shouldn't we do this only once?  opt.bind_address won't
     change during a Wget run!  */

  al = lookup_host (host, flags | LH_SILENT | LH_PASSIVE);
  if (al == NULL)
    {
      logprintf (LOG_NOTQUIET,
		 _("Unable to convert `%s' to a bind address.  Reverting to ANY.\n"),
		 opt.bind_address);
      return 0;
    }

  /* Pick the first address in the list and use it as bind address.
     Perhaps we should try multiple addresses, but I don't think
     that's necessary in practice.  */
  sockaddr_set_data (sa, address_list_address_at (al, 0), 0);
  address_list_release (al);
  return 1;
}

struct cwt_context {
