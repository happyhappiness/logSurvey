   Trailing semicolon is optional; spaces are allowed between all
   tokens.  Additionally, values may be quoted.

   A new cookie is returned upon success, NULL otherwise.

   The first name-value pair will be used to set the cookie's
   attribute name and value.  Subsequent parameters will be checked
   against field names such as `domain', `path', etc.  Recognized
   fields will be parsed and the corresponding members of COOKIE
   filled.  */

static struct cookie *
parse_set_cookie (const char *set_cookie, bool silent)
{
  const char *ptr = set_cookie;
  struct cookie *cookie = cookie_new ();
  param_token name, value;

  if (!extract_param (&ptr, &name, &value))
    goto error;
  if (!value.b)
    goto error;
  cookie->attr = strdupdelim (name.b, name.e);
  cookie->value = strdupdelim (value.b, value.e);

  while (extract_param (&ptr, &name, &value))
    {
      if (TOKEN_IS (name, "domain"))
	{
	  if (!TOKEN_NON_EMPTY (value))
	    goto error;
	  xfree_null (cookie->domain);
	  /* Strictly speaking, we should set cookie->domain_exact if the
	     domain doesn't begin with a dot.  But many sites set the
	     domain to "foo.com" and expect "subhost.foo.com" to get the
	     cookie, and it apparently works in browsers.  */
	  if (*value.b == '.')
	    ++value.b;
	  cookie->domain = strdupdelim (value.b, value.e);
	}
      else if (TOKEN_IS (name, "path"))
	{
	  if (!TOKEN_NON_EMPTY (value))
	    goto error;
	  xfree_null (cookie->path);
	  cookie->path = strdupdelim (value.b, value.e);
	}
      else if (TOKEN_IS (name, "expires"))
	{
	  char *value_copy;
	  time_t expires;

	  if (!TOKEN_NON_EMPTY (value))
	    goto error;
	  BOUNDED_TO_ALLOCA (value.b, value.e, value_copy);

	  expires = http_atotm (value_copy);
	  if (expires != (time_t) -1)
	    {
	      cookie->permanent = 1;
	      cookie->expiry_time = expires;
	    }
	  else
	    /* Error in expiration spec.  Assume default (cookie doesn't
	       expire, but valid only for this session.)  */
	    ;

	  /* According to netscape's specification, expiry time in the
	     past means that discarding of a matching cookie is
	     requested.  */
	  if (cookie->expiry_time < cookies_now)
	    cookie->discard_requested = 1;
	}
      else if (TOKEN_IS (name, "max-age"))
	{
	  double maxage = -1;
	  char *value_copy;

	  if (!TOKEN_NON_EMPTY (value))
	    goto error;
	  BOUNDED_TO_ALLOCA (value.b, value.e, value_copy);

	  sscanf (value_copy, "%lf", &maxage);
	  if (maxage == -1)
	    /* something went wrong. */
	    goto error;
	  cookie->permanent = 1;
	  cookie->expiry_time = cookies_now + maxage;

	  /* According to rfc2109, a cookie with max-age of 0 means that
	     discarding of a matching cookie is requested.  */
	  if (maxage == 0)
	    cookie->discard_requested = 1;
	}
      else if (TOKEN_IS (name, "secure"))
	{
	  /* ignore value completely */
	  cookie->secure = 1;
	}
      else
	/* Ignore unrecognized attribute. */
	;
    }
  if (*ptr)
    /* extract_param has encountered a syntax error */
    goto error;

  /* The cookie has been successfully constructed; return it. */
  return cookie;

 error:
  if (!silent)
    logprintf (LOG_NOTQUIET,
	       _("Syntax error in Set-Cookie: %s at position %d.\n"),
	       escnonprint (set_cookie), (int) (ptr - set_cookie));
  delete_cookie (cookie);
  return NULL;
}

#undef TOKEN_IS
#undef TOKEN_NON_EMPTY

/* Sanity checks.  These are important, otherwise it is possible for
   mailcious attackers to destroy important cookie information and/or
