		      ++count;
		    else if (*p == closeparen && --count < 0)
		      break;
		    else if (colon == 0 && count == 0 && *p == ':')
		      /* Record where we found a colon, which
			 indicates a substitution reference.
			 We want to expand the text before the
			 reference only.  */
		      colon = p;
		  }
		/* If COUNT is >= 0, there were unmatched opening parens
		   or braces, so we go to the simple case of a variable name
		   such as `$($(a)'.  */
		if (count < 0)
		  {
		    char *name = expand_argument (beg, colon == 0 ? p : colon);
		    unsigned int namelen = strlen (name);
		    if (colon == 0)
		      {
			/* This is a simple reference to the expanded name.  */
			o = reference_variable (o, name, namelen);
			free (name);
			break;
		      }
		    else
		      {
			/* This is a substitution reference to the expanded
			   name.  We replace the pending text with a copy
			   containing the expanded name in place of the
			   original name, and then fall through to
			   the normal substitution reference code below.  */
			unsigned int restlen = strlen (colon) + 1;
			beg = (char *) alloca (namelen + restlen);
			bcopy (name, beg, namelen);
			bcopy (colon, &beg[namelen], restlen);
			/* Point COLON into the new copy.  */
			colon = &beg[namelen];
		      }
		  }
	      }

	    /* This is not a reference to a built-in function and
	       it does not contain any variable references inside.
	       There are several things it could be.  */

	    if (colon == 0)
	      colon = index (beg, ':');
	    if (colon != 0 && lindex (beg, colon, closeparen) == 0)
	      {
		/* This is a substitution reference: $(FOO:A=B).  */
		int count;
		char *subst_beg, *subst_end, *replace_beg, *replace_end;

		v = lookup_variable (beg, colon - beg);
		if (v == 0)
		  warn_undefined (beg, colon - beg);

		subst_beg = colon + 1;
		count = 0;
		for (p = subst_beg; *p != '\0'; ++p)
		  {
		    if (*p == openparen)
		      ++count;
		    else if (*p == closeparen)
		      --count;
		    else if (*p == '=' && count <= 0)
		      break;
		  }
		if (count > 0)
		  /* There were unmatched opening parens.  */
		  return initialize_variable_output ();
		subst_end = p;

		replace_beg = p + 1;
		count = 0;
		for (p = replace_beg; *p != '\0'; ++p)
		  {
		    if (*p == openparen)
		      ++count;
		    else if (*p == closeparen && --count < 0)
		      break;
		  }
		if (count > 0)
		  /* There were unmatched opening parens.  */
		  return initialize_variable_output ();
		end = p;
		replace_end = p;

		p = expand_argument (subst_beg, subst_end);
		p1 = expand_argument (replace_beg, replace_end);

		if (v != 0 && *v->value != '\0')
		  {
		    char *value = (v->recursive ? recursively_expand (v)
				   : v->value);
		    char *percent = find_percent (p);
		    if (percent != 0)
		      o = patsubst_expand (o, value, p, p1,
					   percent, (char *) 0);
		    else
		      o = subst_expand (o, value,
					p, p1, strlen (p), strlen (p1),
					0, 1);
		    if (v->recursive)
		      free (value);
		  }

		free (p);
		free (p1);
	      }

	    /* No, this must be an ordinary variable reference.  */
	    else
	      {
		/* Look up the value of the variable.  */
		end = index (beg, closeparen);
		if (end == 0)
		  {
		    /* Unterminated variable reference.  */
		    if (reading_filename != 0)
		      makefile_fatal (reading_filename, *reading_lineno_ptr,
				      "unterminated variable reference");
		    else
		      fatal ("unterminated variable reference");
		  }
		o = reference_variable (o, beg, end - beg);
	      }

	    /* Advance p past the variable reference to resume scan.  */
	    p = end;
	  }
	  break;

