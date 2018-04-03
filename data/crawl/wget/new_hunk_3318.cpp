
/* Variables shared by bindport and acceptport: */
static int msock = -1;
/*static struct sockaddr *addr;*/

static int
resolve_bind_address (int flags, ip_address *addr)
{
  struct address_list *al = NULL;
  int bind_address_resolved = 0;

  if (opt.bind_address != NULL)
    {
      al = lookup_host (opt.bind_address, flags | LH_SILENT | LH_PASSIVE);

      if (al == NULL)
        {
          logprintf (LOG_NOTQUIET,
		     _("Unable to convert `%s' to a bind address.  Reverting to ANY.\n"),
		     opt.bind_address);
	}
      else 
        bind_address_resolved = 1;
    }

  if (al == NULL)
    {
      const char *unspecified_address = "0.0.0.0";
#ifdef ENABLE_IPV6
      if (flags & BIND_ON_IPV6_ONLY)
	unspecified_address = "::";
#endif
      al = lookup_host (unspecified_address, LH_SILENT | LH_PASSIVE);
    }

  assert (al != NULL);

  address_list_copy_one (al, 0, addr);
  address_list_release (al);

  return bind_address_resolved;
}

struct cwt_context {
