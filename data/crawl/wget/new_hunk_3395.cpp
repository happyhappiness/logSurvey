  return path_matches (path, cookie_path);
}

/* Process the HTTP `Set-Cookie' header.  This results in storing the
   cookie or discarding a matching one, or ignoring it completely, all
   depending on the contents.  */

void
cookie_jar_process_set_cookie (struct cookie_jar *jar,
			       const char *host, int port,
			       const char *path, const char *set_cookie)
{
  struct cookie *cookie;
  cookies_now = time (NULL);

  cookie = parse_set_cookies (set_cookie);
  if (!cookie)
    goto out;

  /* Sanitize parts of cookie. */

  if (!cookie->domain)
    {
    copy_domain:
      cookie->domain = xstrdup (host);
      cookie->port = port;
    }
  else
    {
      if (!check_domain_match (cookie->domain, host))
	{
	  logprintf (LOG_NOTQUIET,
		     "Cookie coming from %s attempted to set domain to %s\n",
		     host, cookie->domain);
	  goto copy_domain;
	}
    }
  if (!cookie->path)
    cookie->path = xstrdup (path);
  else
    {
      if (!check_path_match (cookie->path, path))
	{
	  DEBUGP (("Attempt to fake the path: %s, %s\n",
		   cookie->path, path));
	  goto out;
	}
    }

  if (cookie->discard_requested)
    {
      discard_matching_cookie (jar, cookie);
      delete_cookie (cookie);
    }

  store_cookie (jar, cookie);
  return;

 out:
  if (cookie)
    delete_cookie (cookie);
}

/* Support for sending out cookies in HTTP requests, based on
