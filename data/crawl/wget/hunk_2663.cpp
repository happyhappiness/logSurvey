    Trailing semicolon is optional; spaces are allowed between all
    tokens.  Additionally, values may be quoted.
 
-   A new cookie is returned upon success, NULL otherwise.  The
-   specified CALLBACK function (normally `update_cookie_field' is used
-   to update the fields of the newly created cookie structure.  */
+   A new cookie is returned upon success, NULL otherwise.
+
+   The first name-value pair will be used to set the cookie's
+   attribute name and value.  Subsequent parameters will be checked
+   against field names such as `domain', `path', etc.  Recognized
+   fields will be parsed and the corresponding members of COOKIE
+   filled.  */
 
 static struct cookie *
-parse_set_cookies (const char *sc,
-		   bool (*callback) (struct cookie *,
-				     const char *, const char *,
-				     const char *, const char *),
-		   bool silent)
+parse_set_cookie (const char *set_cookie, bool silent)
 {
+  const char *ptr = set_cookie;
   struct cookie *cookie = cookie_new ();
+  param_token name, value;
 
-  /* #### Hand-written DFAs are no fun to debug.  We'de be better off
-     to rewrite this as an inline parser.  */
-
-  enum { S_START, S_NAME, S_NAME_POST,
-	 S_VALUE_PRE, S_VALUE, S_QUOTED_VALUE, S_VALUE_TRAILSPACE,
-	 S_ATTR_ACTION, S_DONE, S_ERROR
-  } state = S_START;
+  if (!extract_param (&ptr, &name, &value))
+    goto error;
+  if (!value.b)
+    goto error;
+  cookie->attr = strdupdelim (name.b, name.e);
+  cookie->value = strdupdelim (value.b, value.e);
 
-  const char *p = sc;
-  char c;
-
-  const char *name_b  = NULL, *name_e  = NULL;
-  const char *value_b = NULL, *value_e = NULL;
-
-  c = *p;
-
-  while (state != S_DONE && state != S_ERROR)
+  while (extract_param (&ptr, &name, &value))
     {
-      switch (state)
+      if (TOKEN_IS (name, "domain"))
 	{
-	case S_START:
-	  if (!c)
-	    state = S_DONE;
-	  else if (ISSPACE (c))
-	    /* Strip all whitespace preceding the name. */
-	    c = *++p;
-	  else if (ATTR_NAME_CHAR (c))
-	    {
-	      name_b = p;
-	      state = S_NAME;
-	    }
-	  else
-	    /* empty attr name not allowed */
-	    state = S_ERROR;
-	  break;
-	case S_NAME:
-	  if (!c || c == ';' || c == '=' || ISSPACE (c))
-	    {
-	      name_e = p;
-	      state = S_NAME_POST;
-	    }
-	  else if (ATTR_NAME_CHAR (c))
-	    c = *++p;
-	  else
-	    state = S_ERROR;
-	  break;
-	case S_NAME_POST:
-	  if (!c || c == ';')
-	    {
-	      value_b = value_e = NULL;
-	      if (c == ';')
-		c = *++p;
-	      state = S_ATTR_ACTION;
-	    }
-	  else if (c == '=')
-	    {
-	      c = *++p;
-	      state = S_VALUE_PRE;
-	    }
-	  else if (ISSPACE (c))
-	    /* Ignore space and keep the state. */
-	    c = *++p;
-	  else
-	    state = S_ERROR;
-	  break;
-	case S_VALUE_PRE:
-	  if (!c || c == ';')
-	    {
-	      value_b = value_e = p;
-	      if (c == ';')
-		c = *++p;
-	      state = S_ATTR_ACTION;
-	    }
-	  else if (c == '"')
-	    {
-	      c = *++p;
-	      value_b = p;
-	      state = S_QUOTED_VALUE;
-	    }
-	  else if (ISSPACE (c))
-	    c = *++p;
-	  else
-	    {
-	      value_b = p;
-	      value_e = NULL;
-	      state = S_VALUE;
-	    }
-	  break;
-	case S_VALUE:
-	  if (!c || c == ';' || ISSPACE (c))
-	    {
-	      value_e = p;
-	      state = S_VALUE_TRAILSPACE;
-	    }
-	  else
-	    {
-	      value_e = NULL;	/* no trailing space */
-	      c = *++p;
-	    }
-	  break;
-	case S_QUOTED_VALUE:
-	  if (c == '"')
-	    {
-	      value_e = p;
-	      c = *++p;
-	      state = S_VALUE_TRAILSPACE;
-	    }
-	  else if (!c)
-	    state = S_ERROR;
-	  else
-	    c = *++p;
-	  break;
-	case S_VALUE_TRAILSPACE:
-	  if (c == ';')
+	  if (!TOKEN_NON_EMPTY (value))
+	    goto error;
+	  xfree_null (cookie->domain);
+	  /* Strictly speaking, we should set cookie->domain_exact if the
+	     domain doesn't begin with a dot.  But many sites set the
+	     domain to "foo.com" and expect "subhost.foo.com" to get the
+	     cookie, and it apparently works in browsers.  */
+	  if (*value.b == '.')
+	    ++value.b;
+	  cookie->domain = strdupdelim (value.b, value.e);
+	}
+      else if (TOKEN_IS (name, "path"))
+	{
+	  if (!TOKEN_NON_EMPTY (value))
+	    goto error;
+	  xfree_null (cookie->path);
+	  cookie->path = strdupdelim (value.b, value.e);
+	}
+      else if (TOKEN_IS (name, "expires"))
+	{
+	  char *value_copy;
+	  time_t expires;
+
+	  if (!TOKEN_NON_EMPTY (value))
+	    goto error;
+	  BOUNDED_TO_ALLOCA (value.b, value.e, value_copy);
+
+	  expires = http_atotm (value_copy);
+	  if (expires != (time_t) -1)
 	    {
-	      c = *++p;
-	      state = S_ATTR_ACTION;
+	      cookie->permanent = 1;
+	      cookie->expiry_time = expires;
 	    }
-	  else if (!c)
-	    state = S_ATTR_ACTION;
-	  else if (ISSPACE (c))
-	    c = *++p;
 	  else
-	    state = S_VALUE;
-	  break;
-	case S_ATTR_ACTION:
-	  {
-	    bool legal = callback (cookie, name_b, name_e, value_b, value_e);
-	    if (!legal)
-	      {
-		if (!silent)
-		  {
-		    char *name;
-		    BOUNDED_TO_ALLOCA (name_b, name_e, name);
-		    logprintf (LOG_NOTQUIET,
-			       _("Error in Set-Cookie, field `%s'"),
-			       escnonprint (name));
-		  }
-		state = S_ERROR;
-		break;
-	      }
-	    state = S_START;
-	  }
-	  break;
-	case S_DONE:
-	case S_ERROR:
-	  /* handled by loop condition */
-	  break;
+	    /* Error in expiration spec.  Assume default (cookie doesn't
+	       expire, but valid only for this session.)  */
+	    ;
+
+	  /* According to netscape's specification, expiry time in the
+	     past means that discarding of a matching cookie is
+	     requested.  */
+	  if (cookie->expiry_time < cookies_now)
+	    cookie->discard_requested = 1;
+	}
+      else if (TOKEN_IS (name, "max-age"))
+	{
+	  double maxage = -1;
+	  char *value_copy;
+
+	  if (!TOKEN_NON_EMPTY (value))
+	    goto error;
+	  BOUNDED_TO_ALLOCA (value.b, value.e, value_copy);
+
+	  sscanf (value_copy, "%lf", &maxage);
+	  if (maxage == -1)
+	    /* something went wrong. */
+	    goto error;
+	  cookie->permanent = 1;
+	  cookie->expiry_time = cookies_now + maxage;
+
+	  /* According to rfc2109, a cookie with max-age of 0 means that
+	     discarding of a matching cookie is requested.  */
+	  if (maxage == 0)
+	    cookie->discard_requested = 1;
+	}
+      else if (TOKEN_IS (name, "secure"))
+	{
+	  /* ignore value completely */
+	  cookie->secure = 1;
 	}
+      else
+	/* Ignore unrecognized attribute. */
+	;
     }
-  if (state == S_DONE)
-    return cookie;
+  if (*ptr)
+    /* extract_param has encountered a syntax error */
+    goto error;
 
-  delete_cookie (cookie);
-  if (state != S_ERROR)
-    abort ();
+  /* The cookie has been successfully constructed; return it. */
+  return cookie;
 
+ error:
   if (!silent)
     logprintf (LOG_NOTQUIET,
 	       _("Syntax error in Set-Cookie: %s at position %d.\n"),
-	       escnonprint (sc), (int) (p - sc));
+	       escnonprint (set_cookie), (int) (ptr - set_cookie));
+  delete_cookie (cookie);
   return NULL;
 }
+
+#undef TOKEN_IS
+#undef TOKEN_NON_EMPTY
 
 /* Sanity checks.  These are important, otherwise it is possible for
    mailcious attackers to destroy important cookie information and/or
