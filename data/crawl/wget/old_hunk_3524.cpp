static int
cmd_address (const char *com, const char *val, void *closure)
{
  struct sockaddr_in sin;
  struct sockaddr_in **target = (struct sockaddr_in **)closure;

  memset (&sin, '\0', sizeof (sin));

  if (!lookup_host (val, (unsigned char *)&sin.sin_addr))
    {
      fprintf (stderr, _("%s: %s: Cannot convert `%s' to an IP address.\n"),
	       exec_name, com, val);
      return 0;
    }
  sin.sin_family = AF_INET;
  sin.sin_port = 0;

