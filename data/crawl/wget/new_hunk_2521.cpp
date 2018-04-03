    {
    copy_domain:
      /* If the domain was not provided, we use the one we're talking
         to, and set exact match.  */
      cookie->domain = xstrdup (host);
      cookie->domain_exact = 1;
      /* Set the port, but only if it's non-default. */
      if (port != 80 && port != 443)
        cookie->port = port;
    }
  else
    {
      if (!check_domain_match (cookie->domain, host))
        {
          logprintf (LOG_NOTQUIET,
                     _("Cookie coming from %s attempted to set domain to %s\n"),
                     escnonprint (host), escnonprint (cookie->domain));
          xfree (cookie->domain);
          goto copy_domain;
        }
    }

  if (!cookie->path)
    {
      /* The cookie doesn't set path: set it to the URL path, sans the
         file part ("/dir/file" truncated to "/dir/").  */
      char *trailing_slash = strrchr (path, '/');
      if (trailing_slash)
        cookie->path = strdupdelim (path, trailing_slash + 1);
      else
        /* no slash in the string -- can this even happen? */
        cookie->path = xstrdup (path);
    }
  else
    {
      /* The cookie sets its own path; verify that it is legal. */
      if (!check_path_match (cookie->path, path))
        {
          DEBUGP (("Attempt to fake the path: %s, %s\n",
                   cookie->path, path));
          goto out;
        }
    }

  /* Now store the cookie, or discard an existing cookie, if
