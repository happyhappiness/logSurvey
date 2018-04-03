          current_variable_set_list = f->variables;
          v = try_variable_definition (flocp, defn, origin, 1);
          if (!v)
            fatal (flocp, _("Malformed target-specific variable definition"));
          current_variable_set_list = global;
        }

      /* Set up the variable to be *-specific.  */
      v->origin = origin;
      v->per_target = 1;
      v->private_var = vmod->private_v;
      v->export = vmod->export_v ? v_export : v_default;

      /* If it's not an override, check to see if there was a command-line
         setting.  If so, reset the value.  */
