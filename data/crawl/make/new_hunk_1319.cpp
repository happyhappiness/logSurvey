
      /* Make the new variable context current and define the variable.  */
      current_variable_set_list = vlist;
      v = try_variable_definition(flocp, defn, origin);
      if (!v)
        error (flocp, "Malformed per-target variable definition");
      v->per_target = 1;

      /* If it's not an override, check to see if there was a command-line
