
/* Variables shared by bindport and acceptport: */
static int msock = -1;
static struct sockaddr *addr;

static ip_address bind_address;
static int bind_address_resolved;

static void
resolve_bind_address (void)
{
  struct address_list *al;

  if (bind_address_resolved || opt.bind_address == NULL)
    /* Nothing to do. */
    return;

  al = lookup_host (opt.bind_address, 1);
  if (!al)
    {
      logprintf (LOG_NOTQUIET,
		 _("Unable to convert `%s' to a bind address.  Reverting to ANY.\n"),
		 opt.bind_address);
      return;
    }

  address_list_copy_one (al, 0, &bind_address);
  address_list_release (al);
  bind_address_resolved = 1;
}

struct cwt_context {
