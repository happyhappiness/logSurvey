            {
              p += 5;
              remove_comments (p);
              if (*next_token (p) != '\0')
                error (&ebuf->floc,
                       _("Extraneous text after `endef' directive"));

              if (--nlevels == 0)
                {
                  struct variable *v;

                  /* Define the variable.  */
                  if (idx == 0)
                    definition[0] = '\0';
                  else
                    definition[idx - 1] = '\0';

                  /* Always define these variables in the global set.  */
                  v = define_variable_global (var, strlen (var), definition,
                                              origin, 1, &defstart);
                  free (definition);
                  return (v);
                }
            }
        }

      /* Otherwise add this line to the variable definition.  */
      len = strlen (line);
      if (idx + len + 1 > length)
        {
