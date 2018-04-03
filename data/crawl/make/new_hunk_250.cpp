          current_variable_set_list = f->variables;
          v = try_variable_definition (flocp, defn, origin, 1);
          if (!v)
            O (fatal, flocp, _("Malformed target-specific variable definition"));
          current_variable_set_list = global;
        }

