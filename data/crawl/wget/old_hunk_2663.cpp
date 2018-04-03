   Trailing semicolon is optional; spaces are allowed between all
   tokens.  Additionally, values may be quoted.

   A new cookie is returned upon success, NULL otherwise.  The
   specified CALLBACK function (normally `update_cookie_field' is used
   to update the fields of the newly created cookie structure.  */

static struct cookie *
parse_set_cookies (const char *sc,
		   bool (*callback) (struct cookie *,
				     const char *, const char *,
				     const char *, const char *),
		   bool silent)
{
  struct cookie *cookie = cookie_new ();

  /* #### Hand-written DFAs are no fun to debug.  We'de be better off
     to rewrite this as an inline parser.  */

  enum { S_START, S_NAME, S_NAME_POST,
	 S_VALUE_PRE, S_VALUE, S_QUOTED_VALUE, S_VALUE_TRAILSPACE,
	 S_ATTR_ACTION, S_DONE, S_ERROR
  } state = S_START;

  const char *p = sc;
  char c;

  const char *name_b  = NULL, *name_e  = NULL;
  const char *value_b = NULL, *value_e = NULL;

  c = *p;

  while (state != S_DONE && state != S_ERROR)
    {
      switch (state)
	{
	case S_START:
	  if (!c)
	    state = S_DONE;
	  else if (ISSPACE (c))
	    /* Strip all whitespace preceding the name. */
	    c = *++p;
	  else if (ATTR_NAME_CHAR (c))
	    {
	      name_b = p;
	      state = S_NAME;
	    }
	  else
	    /* empty attr name not allowed */
	    state = S_ERROR;
	  break;
	case S_NAME:
	  if (!c || c == ';' || c == '=' || ISSPACE (c))
	    {
	      name_e = p;
	      state = S_NAME_POST;
	    }
	  else if (ATTR_NAME_CHAR (c))
	    c = *++p;
	  else
	    state = S_ERROR;
	  break;
	case S_NAME_POST:
	  if (!c || c == ';')
	    {
	      value_b = value_e = NULL;
	      if (c == ';')
		c = *++p;
	      state = S_ATTR_ACTION;
	    }
	  else if (c == '=')
	    {
	      c = *++p;
	      state = S_VALUE_PRE;
	    }
	  else if (ISSPACE (c))
	    /* Ignore space and keep the state. */
	    c = *++p;
	  else
	    state = S_ERROR;
	  break;
	case S_VALUE_PRE:
	  if (!c || c == ';')
	    {
	      value_b = value_e = p;
	      if (c == ';')
		c = *++p;
	      state = S_ATTR_ACTION;
	    }
	  else if (c == '"')
	    {
	      c = *++p;
	      value_b = p;
	      state = S_QUOTED_VALUE;
	    }
	  else if (ISSPACE (c))
	    c = *++p;
	  else
	    {
	      value_b = p;
	      value_e = NULL;
	      state = S_VALUE;
	    }
	  break;
	case S_VALUE:
	  if (!c || c == ';' || ISSPACE (c))
	    {
	      value_e = p;
	      state = S_VALUE_TRAILSPACE;
	    }
	  else
	    {
	      value_e = NULL;	/* no trailing space */
	      c = *++p;
	    }
	  break;
	case S_QUOTED_VALUE:
	  if (c == '"')
	    {
	      value_e = p;
	      c = *++p;
	      state = S_VALUE_TRAILSPACE;
	    }
	  else if (!c)
	    state = S_ERROR;
	  else
	    c = *++p;
	  break;
	case S_VALUE_TRAILSPACE:
	  if (c == ';')
	    {
	      c = *++p;
	      state = S_ATTR_ACTION;
	    }
	  else if (!c)
	    state = S_ATTR_ACTION;
	  else if (ISSPACE (c))
	    c = *++p;
	  else
	    state = S_VALUE;
	  break;
	case S_ATTR_ACTION:
	  {
	    bool legal = callback (cookie, name_b, name_e, value_b, value_e);
	    if (!legal)
	      {
		if (!silent)
		  {
		    char *name;
		    BOUNDED_TO_ALLOCA (name_b, name_e, name);
		    logprintf (LOG_NOTQUIET,
			       _("Error in Set-Cookie, field `%s'"),
			       escnonprint (name));
		  }
		state = S_ERROR;
		break;
	      }
	    state = S_START;
	  }
	  break;
	case S_DONE:
	case S_ERROR:
	  /* handled by loop condition */
	  break;
	}
    }
  if (state == S_DONE)
    return cookie;

  delete_cookie (cookie);
  if (state != S_ERROR)
    abort ();

  if (!silent)
    logprintf (LOG_NOTQUIET,
	       _("Syntax error in Set-Cookie: %s at position %d.\n"),
	       escnonprint (sc), (int) (p - sc));
  return NULL;
}

/* Sanity checks.  These are important, otherwise it is possible for
   mailcious attackers to destroy important cookie information and/or
