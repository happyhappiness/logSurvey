          /* Get a reference for this pattern-specific variable struct.  */
          p = create_pattern_var (name, percent);
          p->variable.fileinfo = *flocp;
          /* I don't think this can fail since we already determined it was a
             variable definition.  */
          v = parse_variable_definition (&p->variable, defn);
          assert (v != 0);
          v->value = xstrdup (v->value);
          fname = p->target;
        }
      else
