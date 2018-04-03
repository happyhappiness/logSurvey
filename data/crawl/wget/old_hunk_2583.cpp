
      /* Skip leading whitespace.  */
      while (*p && ISSPACE (*p))
	p ++;

      /* If the line is empty, then end any macro definition.  */
      if (last_token == tok_macdef && !*p)
	/* End of macro if the line is empty.  */
	last_token = tok_nothing;

      /* If we are defining macros, then skip parsing the line.  */
      while (*p && last_token != tok_macdef)
	{
	  /* Skip any whitespace.  */
	  while (*p && ISSPACE (*p))
	    p ++;

	  /* Discard end-of-line comments; also, stop processing if
	     the above `while' merely skipped trailing whitespace.  */
	  if (*p == '#' || !*p)
	    break;

	  /* If the token starts with quotation mark, note this fact,
	     and squash the quotation character */
	  if (*p == '"'){
	    quote = 1;
	    shift_left (p);
	  }

	  tok = p;

	  /* Find the end of the token, handling quotes and escapes.  */
	  while (*p && (quote ? *p != '"' : !ISSPACE (*p))){
	    if (*p == '\\')
	      shift_left (p);
	    p ++;
	  }

	  /* If field was quoted, squash the trailing quotation mark
	     and reset quote flag.  */
	  if (quote)
	    {
	      shift_left (p);
	      quote = 0;
	    }

	  /* Null-terminate the token, if it isn't already.  */
	  if (*p)
	    *p ++ = '\0';

	  switch (last_token)
	    {
	    case tok_login:
	      if (current)
		current->acc = xstrdup (tok);
	      else
		premature_token = "login";
	      break;

	    case tok_machine:
	      /* Start a new machine entry.  */
	      maybe_add_to_list (&current, &retval);
	      current->host = xstrdup (tok);
	      break;

	    case tok_password:
	      if (current)
		current->passwd = xstrdup (tok);
	      else
		premature_token = "password";
	      break;

	      /* We handle most of tok_macdef above.  */
	    case tok_macdef:
	      if (!current)
		premature_token = "macdef";
	      break;

	      /* We don't handle the account keyword at all.  */
	    case tok_account:
	      if (!current)
		premature_token = "account";
	      break;

	      /* We handle tok_nothing below this switch.  */
	    case tok_nothing:
	      break;
	    }

	  if (premature_token)
	    {
	      fprintf (stderr, _("\
%s: %s:%d: warning: \"%s\" token appears before any machine name\n"),
		       exec_name, path, ln, premature_token);
	      premature_token = NULL;
	    }

	  if (last_token != tok_nothing)
	    /* We got a value, so reset the token state.  */
	    last_token = tok_nothing;
	  else
	    {
	      /* Fetch the next token.  */
	      if (!strcmp (tok, "account"))
		last_token = tok_account;
	      else if (!strcmp (tok, "default"))
		{
		  maybe_add_to_list (&current, &retval);
		}
	      else if (!strcmp (tok, "login"))
		last_token = tok_login;

	      else if (!strcmp (tok, "macdef"))
		last_token = tok_macdef;

	      else if (!strcmp (tok, "machine"))
		last_token = tok_machine;

	      else if (!strcmp (tok, "password"))
		last_token = tok_password;

	      else
		fprintf (stderr, _("%s: %s:%d: unknown token \"%s\"\n"),
			 exec_name, path, ln, tok);
	    }
	}

      xfree (line);
    }
