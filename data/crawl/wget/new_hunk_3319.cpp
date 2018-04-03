int
connect_to_one (ip_address *addr, unsigned short port, int silent)
{
  struct sockaddr_storage ss;
  struct sockaddr *sa = (struct sockaddr *)&ss;
  int sock, save_errno;

  /* Set port and protocol */
  sockaddr_set_address (sa, port, addr);

  if (!silent)
    {
      const char *pretty_addr = pretty_print_address (addr);
      if (connection_host_name
	  && 0 != strcmp (connection_host_name, pretty_addr))
	logprintf (LOG_VERBOSE, _("Connecting to %s[%s]:%hu... "),
