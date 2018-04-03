	    }
	}
    }

  beg = next_token (line);
  while (end > beg && isblank ((unsigned char)end[-1]))
    --end;
  p = next_token (p);

  /* Expand the name, so "$(foo)bar = baz" works.  */
  name = (char *) alloca (end - beg + 1);
  bcopy (beg, name, end - beg);
  name[end - beg] = '\0';
  expanded_name = allocated_variable_expand (name);

  if (expanded_name[0] == '\0')
    fatal (flocp, _("empty variable name"));

  v = do_variable_definition (flocp, expanded_name, p,
                              origin, flavor, target_var);

  free (expanded_name);

  return v;
}

/* Print information for variable V, prefixing it with PREFIX.  */
