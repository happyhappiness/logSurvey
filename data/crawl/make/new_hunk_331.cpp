    {
      /* Copy all following uninteresting chars all at once to the
         variable output buffer, and skip them.  Uninteresting chars end
         at the next $ or the end of the input.  */

      p1 = strchr (p, '$');

      o = variable_buffer_output (o, p, p1 != 0 ? (unsigned int)(p1 - p) : strlen (p) + 1);

      if (p1 == 0)
        break;
      p = p1 + 1;

      /* Dispatch on the char that follows the $.  */

      switch (*p)
        {
        case '$':
          /* $$ seen means output one $ to the variable output buffer.  */
          o = variable_buffer_output (o, p, 1);
          break;

        case '(':
        case '{':
          /* $(...) or ${...} is the general case of substitution.  */
          {
            char openparen = *p;
            char closeparen = (openparen == '(') ? ')' : '}';
            const char *begp;
            const char *beg = p + 1;
            char *op;
            char *abeg = NULL;
            const char *end, *colon;

            op = o;
            begp = p;
            if (handle_function (&op, &begp))
              {
                o = op;
                p = begp;
                break;
              }

            /* Is there a variable reference inside the parens or braces?
               If so, expand it before expanding the entire reference.  */

            end = strchr (beg, closeparen);
            if (end == 0)
              /* Unterminated variable reference.  */
              fatal (*expanding_var, _("unterminated variable reference"));
            p1 = lindex (beg, end, '$');
            if (p1 != 0)
              {
                /* BEG now points past the opening paren or brace.
                   Count parens or braces until it is matched.  */
                int count = 0;
                for (p = beg; *p != '\0'; ++p)
                  {
                    if (*p == openparen)
                      ++count;
                    else if (*p == closeparen && --count < 0)
                      break;
                  }
                /* If COUNT is >= 0, there were unmatched opening parens
                   or braces, so we go to the simple case of a variable name
                   such as '$($(a)'.  */
                if (count < 0)
                  {
                    abeg = expand_argument (beg, p); /* Expand the name.  */
                    beg = abeg;
                    end = strchr (beg, '\0');
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

            colon = lindex (beg, end, ':');
            if (colon)
              {
                /* This looks like a substitution reference: $(FOO:A=B).  */
                const char *subst_beg, *subst_end, *replace_beg, *replace_end;

                subst_beg = colon + 1;
                subst_end = lindex (subst_beg, end, '=');
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

                    /* If the variable is not empty, perform the
                       substitution.  */
                    if (v != 0 && *v->value != '\0')
                      {
                        char *pattern, *replace, *ppercent, *rpercent;
                        char *value = (v->recursive
                                       ? recursively_expand (v)
                                       : v->value);

                        /* Copy the pattern and the replacement.  Add in an
                           extra % at the beginning to use in case there
