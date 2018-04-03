		  p = strchr (p2, '\0');
		  while (isblank ((unsigned char)p[-1]))
		    --p;
		  do_define (p2, p - p2, o_override, ebuf);
		}
	    }
	  else if (!ignoring
		   && !try_variable_definition (fstart, p2, o_override, 0))
	    error (fstart, _("invalid `override' directive"));

	  continue;
	}

      if (ignoring)
	/* Ignore the line.  We continue here so conditionals
	   can appear in the middle of a rule.  */
	continue;

      if (word1eq ("export"))
	{
          /* 'export' by itself causes everything to be exported. */
	  if (*p2 == '\0')
            export_all_variables = 1;
          else
            {
              struct variable *v;

              v = try_variable_definition (fstart, p2, o_file, 0);
              if (v != 0)
                v->export = v_export;
              else
                {
                  unsigned int len;
                  for (p = find_next_token (&p2, &len); p != 0;
                       p = find_next_token (&p2, &len))
                    {
                      v = lookup_variable (p, len);
                      if (v == 0)
                        v = define_variable_loc (p, len, "", o_file, 0,
                                                 fstart);
                      v->export = v_export;
                    }
                }
            }
          goto rule_complete;
	}

      if (word1eq ("unexport"))
	{
	  if (*p2 == '\0')
	    export_all_variables = 0;
          else
            {
              unsigned int len;
              struct variable *v;
              for (p = find_next_token (&p2, &len); p != 0;
                   p = find_next_token (&p2, &len))
                {
                  v = lookup_variable (p, len);
                  if (v == 0)
                    v = define_variable_loc (p, len, "", o_file, 0, fstart);
                  v->export = v_noexport;
                }
            }
          goto rule_complete;
	}

 skip_conditionals:
      if (word1eq ("vpath"))
	{
	  char *pattern;
	  unsigned int len;
	  p2 = variable_expand (p2);
	  p = find_next_token (&p2, &len);
	  if (p != 0)
	    {
