      collapse_continuations (collapsed);
      remove_comments (collapsed);

      /* See if this is a variable assignment.  We need to do this early, to
         allow variables with names like 'ifdef', 'export', 'private', etc.  */
      p = parse_var_assignment(collapsed, &vmod);
      if (vmod.assign_v)
        {
          struct variable *v;
          enum variable_origin origin = vmod.override_v ? o_override : o_file;

          /* If we're ignoring then we're done now.  */
	  if (ignoring)
            {
              if (vmod.define_v)
                in_ignored_define = 1;
              continue;
            }

          /* If it's a multi-line define / endef, manage that.  */
          if (vmod.define_v)
            {
              if (*p == '\0')
                fatal (fstart, _("empty variable name"));

              /* Let the variable name be the whole rest of the line,
                 with trailing blanks stripped (comments have already been
                 removed), so it could be a complex variable/function
                 reference that might contain blanks.  */
              p2 = p + strlen (p);
              while (isblank ((unsigned char)p2[-1]))
                --p2;
              v = do_define (p, p2 - p, origin, ebuf);
            }
          else
            {
              v = try_variable_definition (fstart, p, origin, 0);
              assert (v != NULL);
            }

          if (vmod.export_v)
            v->export = v_export;
          if (vmod.private_v)
            v->private_var = 1;

          /* This line has been dealt with.  */
          goto rule_complete;
        }

      /* If this line is completely empty, ignore it.  */
      if (*p == '\0')
	continue;

      p2 = end_of_token (p);
      wlen = p2 - p;
      p2 = next_token (p2);

      /* If we're in an ignored define, skip this line (but maybe get out).  */
      if (in_ignored_define)
	{
          /* See if this is an endef line (plus optional comment).  */
          if (word1eq ("endef") && (*p2 == '\0' || *p2 == '#'))
            in_ignored_define = 0;

	  continue;
	}

      /* Check for conditional state changes.  */
      {
        int i = conditional_line (p, wlen, fstart);
        if (i != -2)
          {
            if (i == -1)
              fatal (fstart, _("invalid syntax in conditional"));

            ignoring = i;
            continue;
          }
      }

      /* Nothing to see here... move along.  */
      if (ignoring)
	continue;

      /* Manage the "export" keyword used outside of variable assignment
         as well as "unexport".  */
      if (word1eq ("export") || word1eq ("unexport"))
	{
          int exporting = *p == 'u' ? 0 : 1;

          /* (un)export by itself causes everything to be (un)exported. */
	  if (*p2 == '\0')
            export_all_variables = exporting;
          else
            {
              unsigned int l;
              const char *cp;
              char *ap;

              /* Expand the line so we can use indirect and constructed
                 variable names in an (un)export command.  */
              cp = ap = allocated_variable_expand (p2);

              for (p = find_next_token (&cp, &l); p != 0;
                   p = find_next_token (&cp, &l))
                {
                  struct variable *v = lookup_variable (p, l);
                  if (v == 0)
                    v = define_variable_loc (p, l, "", o_file, 0, fstart);
                  v->export = exporting ? v_export : v_noexport;
                }

              free (ap);
