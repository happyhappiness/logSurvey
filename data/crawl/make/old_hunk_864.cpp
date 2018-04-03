  var[namelen] = '\0';
  var = variable_expand (var);

  initbuffer (&lb);
  while (!feof (infile))
    {
      unsigned int len;

      flocp->lineno += nlines;
      nlines = readline (&lb, infile, flocp);

      collapse_continuations (lb.buffer);

      p = next_token (lb.buffer);
      len = strlen (p);
      if ((len == 5 || (len > 5 && isblank ((unsigned char)p[5])))
          && strneq (p, "endef", 5))
	{
	  p += 5;
	  remove_comments (p);
	  if (*next_token (p) != '\0')
	    error (flocp, _("Extraneous text after `endef' directive"));
	  /* Define the variable.  */
	  if (idx == 0)
	    definition[0] = '\0';
	  else
	    definition[idx - 1] = '\0';
	  (void) define_variable_loc (var, strlen (var), definition, origin,
                                      1, flocp);
	  free (definition);
	  freebuffer (&lb);
	  return;
	}
      else
	{
          len = strlen (lb.buffer);
	  /* Increase the buffer size if necessary.  */
	  if (idx + len + 1 > length)
	    {
	      length = (idx + len) * 2;
	      definition = (char *) xrealloc (definition, length + 1);
	    }

	  bcopy (lb.buffer, &definition[idx], len);
	  idx += len;
	  /* Separate lines with a newline.  */
	  definition[idx++] = '\n';
	}
    }

  /* No `endef'!!  */
  fatal (flocp, _("missing `endef', unterminated `define'"));

  /* NOTREACHED */
  return;
