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
      /* #### We should print the error message here. */
      logprintf (LOG_NOTQUIET,
		 _("%s: unable to resolve bind address `%s'; disabling bind.\n"),
		 exec_name, opt.bind_address);
      return 0;
    }

  /* Pick the first address in the list and use it as bind address.
     Perhaps we should try multiple addresses, but I don't think
     that's necessary in practice.  */
  sockaddr_set_data (sa, address_list_address_at (al, 0), 0);
  address_list_release (al);
  return 1;
}

