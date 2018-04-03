static int msock = -1;
static struct sockaddr *addr;

/* A kludge, but still better than passing the host name all the way
   to connect_to_one.  */
static const char *connection_host_name;

void
set_connection_host_name (const char *host)
{
  if (host)
    assert (connection_host_name == NULL);
  else
    assert (connection_host_name != NULL);

  connection_host_name = host;
}

/* Connect to a remote host whose address has been resolved. */
static int
connect_to_one (unsigned char *addr, unsigned short port, int silent)
{
  struct sockaddr_in sock_name;
  int sock, save_errno;

  /* Set port and protocol */
  sock_name.sin_family = AF_INET;
  sock_name.sin_port = htons (port);
  memcpy ((unsigned char *)&sock_name.sin_addr, addr, 4);

  if (!silent)
    {
      char *pretty_addr = pretty_print_address (addr);
      if (connection_host_name
	  && 0 != strcmp (connection_host_name, pretty_addr))
	logprintf (LOG_VERBOSE, _("Connecting to %s[%s]:%hu... "),
		   connection_host_name, pretty_addr, port);
      else
	logprintf (LOG_VERBOSE, _("Connecting to %s:%hu... "),
		   pretty_addr, port);
    }

  /* Make an internet socket, stream type.  */
  sock = socket (AF_INET, SOCK_STREAM, 0);
  if (sock < 0)
    goto out;

  if (opt.bind_address)
    {
      /* Bind the client side to the requested address. */
      if (bind (sock, (struct sockaddr *)opt.bind_address,
		sizeof (*opt.bind_address)))
	{
	  close (sock);
	  sock = -1;
	  goto out;
	}
    }

  /* Connect the socket to the remote host.  */
  if (connect (sock, (struct sockaddr *)&sock_name, sizeof (sock_name)) < 0)
    {
      close (sock);
      sock = -1;
      goto out;
    }

 out:
  if (sock >= 0)
    {
      /* Success. */
      if (!silent)
	logprintf (LOG_VERBOSE, _("connected.\n"));
      DEBUGP (("Created socket %d.\n", sock));
    }
  else
    {
      save_errno = errno;
      if (!silent)
	logprintf (LOG_VERBOSE, "failed: %s.\n", strerror (errno));
      errno = save_errno;
    }

  return sock;
}

/* Connect to a remote host whose address has been resolved. */
int
connect_to_many (struct address_list *al, unsigned short port, int silent)
{
  int i;

  for (i = 0; i < address_list_count (al); i++)
    {
      unsigned char addr[4];
      int sock;
      address_list_copy_one (al, i, addr);

      sock = connect_to_one (addr, port, silent);
      if (sock >= 0)
	return sock;

      /* Perhaps we should have a way of removing the failing entry
	 from the address list?  */

      /* The attempt to connect has failed.  Continue with the loop
	 and try next address. */
    }

  return -1;
}

int
