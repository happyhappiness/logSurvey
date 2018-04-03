    int add_port = u->port != scheme_default_port (u->scheme);
    int add_squares = strchr (u->host, ':') != NULL;
    request_set_header (req, "Host",
			aprintf (hfmt[add_port][add_squares], u->host, u->port),
			rel_value);
  }

  if (!inhibit_keep_alive)
