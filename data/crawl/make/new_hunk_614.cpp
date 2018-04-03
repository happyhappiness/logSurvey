      definition[idx++] = '\n';
    }

  /* We've got what we need; define the variable.  */
  if (idx == 0)
    definition[0] = '\0';
  else
    definition[idx - 1] = '\0';

  v = do_variable_definition (&defstart, name, definition, origin, flavor, 0);
  free (definition);
  free (var);
  return (v);
}

/* Interpret conditional commands "ifdef", "ifndef", "ifeq",
