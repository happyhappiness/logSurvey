			aprintf ("bytes=%s-",
				 number_to_static_string (hs->restval)),
			rel_value);
  SET_USER_AGENT (req);
  request_set_header (req, "Accept", "*/*", rel_none);

  /* Find the username and password for authentication. */
