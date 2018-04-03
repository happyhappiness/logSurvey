          /* Get a reference for this pattern-specific variable struct.  */
          p = create_pattern_var (name, percent);
          p->variable.fileinfo = *flocp;
          v = parse_variable_definition (&p->variable, defn);
          v->value = xstrdup (v->value);
          if (!v)
            error (flocp, _("Malformed pattern-specific variable definition"));
          fname = p->target;
        }
      else
