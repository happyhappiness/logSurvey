    /* Whether we need to print the host header with braces around
       host, e.g. "Host: [3ffe:8100:200:2::2]:1234" instead of the
       usual "Host: symbolic-name:1234". */
    int squares = strchr (u->host, ':') != NULL;
    if (u->port == scheme_default_port (u->scheme))
      request_set_header (req, "Host",
			  aprintf (squares ? "[%s]" : "%s", u->host),
