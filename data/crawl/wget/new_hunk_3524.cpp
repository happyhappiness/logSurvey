static int
cmd_address (const char *com, const char *val, void *closure)
{
  struct address_list *al;
  struct sockaddr_in sin;
  struct sockaddr_in **target = (struct sockaddr_in **)closure;

  memset (&sin, '\0', sizeof (sin));

  al = lookup_host (val, 1);
  if (!al)
    {
      fprintf (stderr, _("%s: %s: Cannot convert `%s' to an IP address.\n"),
	       exec_name, com, val);
      return 0;
    }
  address_list_copy_one (al, 0, (unsigned char *)&sin.sin_addr);
  address_list_release (al);

  sin.sin_family = AF_INET;
  sin.sin_port = 0;

