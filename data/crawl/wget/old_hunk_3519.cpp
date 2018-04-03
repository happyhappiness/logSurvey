static int msock = -1;
static struct sockaddr *addr;


/* Create an internet connection to HOSTNAME on PORT.  The created
   socket will be stored to *SOCK.  */
uerr_t
make_connection (int *sock, char *hostname, unsigned short port)
{
  struct sockaddr_in sock_name;

  if (!lookup_host (hostname, (unsigned char *)&sock_name.sin_addr))
    return HOSTERR;

  /* Set port and protocol */
  sock_name.sin_family = AF_INET;
  sock_name.sin_port = htons (port);

  /* Make an internet socket, stream type.  */
  if ((*sock = socket (AF_INET, SOCK_STREAM, 0)) == -1)
    return CONSOCKERR;

  if (opt.bind_address != NULL)
    {
      /* Bind the client side to the requested address. */
      if (bind (*sock, (struct sockaddr *) opt.bind_address,
		sizeof (*opt.bind_address)))
	return CONSOCKERR;
    }

  /* Connect the socket to the remote host.  */
  if (connect (*sock, (struct sockaddr *) &sock_name, sizeof (sock_name)))
    {
      if (errno == ECONNREFUSED)
	return CONREFUSED;
      else
	return CONERROR;
    }
  DEBUGP (("Created fd %d.\n", *sock));
  return NOCONERROR;
}

int
