            f = f->double_colon;

          initialize_file_variables (f, 1);
          fname = f->name;

          current_variable_set_list = f->variables;
          v = try_variable_definition (flocp, defn, origin, 1);
          if (!v)
            error (flocp, _("Malformed target-specific variable definition"));
          current_variable_set_list = global;
        }

      /* Set up the variable to be *-specific.  */
      v->origin = origin;
      v->per_target = 1;
      if (exported)
        v->export = v_export;
