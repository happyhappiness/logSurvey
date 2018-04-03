rewrite_shorthand_url (const char *url)
{
  const char *p;

  if (url_scheme (url) != SCHEME_INVALID)
    return NULL;

  /* Look for a ':' or '/'.  The former signifies NcFTP syntax, the
     latter Netscape.  */
  for (p = url; *p && *p != ':' && *p != '/'; p++)
    ;

  if (p == url)
    return NULL;

  /* If we're looking at "://", it means the URL uses a scheme we
     don't support, which may include "https" when compiled without
     SSL support.  Don't bogusly rewrite such URLs.  */
  if (p[0] == ':' && p[1] == '/' && p[2] == '/')
    return NULL;

  if (*p == ':')
    {
      const char *pp;
      char *res;
      /* If the characters after the colon and before the next slash
	 or end of string are all digits, it's HTTP.  */
      int digits = 0;
      for (pp = p + 1; ISDIGIT (*pp); pp++)
	++digits;
      if (digits > 0 && (*pp == '/' || *pp == '\0'))
	goto http;

      /* Prepend "ftp://" to the entire URL... */
      res = xmalloc (6 + strlen (url) + 1);
      sprintf (res, "ftp://%s", url);
      /* ...and replace ':' with '/'. */
      res[6 + (p - url)] = '/';
      return res;
    }
  else
    {
      char *res;
    http:
      /* Just prepend "http://" to what we have. */
      res = xmalloc (7 + strlen (url) + 1);
      sprintf (res, "http://%s", url);
      return res;
    }
}

static void split_path (const char *, char **, char **);
