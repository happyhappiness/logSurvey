		      ++count;
		    else if (*p == closeparen && --count < 0)
		      break;
		  }
		/* If COUNT is >= 0, there were unmatched opening parens
		   or braces, so we go to the simple case of a variable name
		   such as `$($(a)'.  */
		if (count < 0)
		  {
		    beg = expand_argument (beg, p); /* Expand the name.  */
		    free_beg = 1; /* Remember to free BEG when finished.  */
		    end = index (beg, '\0');
		  }
	      }
	    else
	      /* Advance P to the end of this reference.  After we are
                 finished expanding this one, P will be incremented to
                 continue the scan.  */
	      p = end;

	    /* This is not a reference to a built-in function and
	       any variable references inside are now expanded.
	       Is the resultant text a substitution reference?  */

	    colon = index (beg, ':');
	    if (colon != 0)
	      {
		/* This looks like a substitution reference: $(FOO:A=B).  */
		char *subst_beg, *subst_end, *replace_beg, *replace_end;

		subst_beg = colon + 1;
		subst_end = index (subst_beg, '=');
		if (subst_end == 0)
		  /* There is no = in sight.  Punt on the substitution
		     reference and treat this as a variable name containing
		     a colon, in the code below.  */
		  colon = 0;
		else
		  {
		    replace_beg = subst_end + 1;
		    replace_end = end;

		    /* Extract the variable name before the colon
		       and look up that variable.  */
		    v = lookup_variable (beg, colon - beg);
		    if (v == 0)
		      warn_undefined (beg, colon - beg);

		    if (v != 0 && *v->value != '\0')
		      {
			char *value = (v->recursive ? recursively_expand (v)
				       : v->value);
			char *pattern, *percent;
			if (free_beg)
			  {
			    *subst_end = '\0';
			    pattern = subst_beg;
			  }
			else
			  {
			    pattern = alloca (subst_end - subst_beg + 1);
			    bcopy (subst_beg, pattern, subst_end - subst_beg);
			    pattern[subst_end - subst_beg] = '\0';
			  }
			percent = find_percent (pattern);
			if (percent != 0)
			  {
			    char *replace;
			    if (free_beg)
			      {
				*replace_end = '\0';
				replace = replace_beg;
			      }
			    else
			      {
				replace = alloca (replace_end - replace_beg
						  + 1);
				bcopy (replace_beg, replace,
				       replace_end - replace_beg);
				replace[replace_end - replace_beg] = '\0';
			      }
			    
			    o = patsubst_expand (o, value, pattern, replace,
						 percent, (char *) 0);
			  }
			else
			  o = subst_expand (o, value,
					    pattern, replace_beg,
					    strlen (pattern),
					    end - replace_beg,
					    0, 1);
			if (v->recursive)
			  free (value);
		      }
		  }
	      }

	    if (colon == 0)
	      /* This is an ordinary variable reference.
		 Look up the value of the variable.  */
		o = reference_variable (o, beg, end - beg);

	  if (free_beg)
	    free (beg);
	  }
	  break;

