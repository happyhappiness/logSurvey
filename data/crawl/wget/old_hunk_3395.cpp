  return path_matches (path, cookie_path);
}

/* Parse the `Set-Cookie' header and, if the cookie is legal, store it
   to memory.  */

int
set_cookie_header_cb (const char *hdr, void *closure)
{
  struct url *u = (struct url *)closure;
  struct cookie *cookie;

  cookies_now = time (NULL);

  cookie = parse_set_cookies (hdr);
  if (!cookie)
    goto out;

  /* Sanitize parts of cookie. */

  if (!cookie->domain)
    cookie->domain = xstrdup (u->host);
  else
    {
      if (!check_domain_match (cookie->domain, u->host))
	{
	  DEBUGP (("Attempt to fake the domain: %s, %s\n",
		   cookie->domain, u->host));
	  goto out;
	}
    }
  if (!cookie->path)
    cookie->path = xstrdup (u->path);
  else
    {
      if (!check_path_match (cookie->path, u->path))
	{
	  DEBUGP (("Attempt to fake the path: %s, %s\n",
		   cookie->path, u->path));
	  goto out;
	}
    }

  cookie->port = u->port;

  if (cookie->discard_requested)
    {
      discard_matching_cookie (cookie);
      delete_cookie (cookie);
      return 1;
    }

  store_cookie (cookie);
  return 1;

 out:
  if (cookie)
    delete_cookie (cookie);
  return 1;
}

/* Support for sending out cookies in HTTP requests, based on
