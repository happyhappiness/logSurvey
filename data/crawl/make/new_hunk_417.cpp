
  DB (DB_VERBOSE, (_("Loading symbol %s from %s\n"), symname, *ldname));

  /* Load it!  */
  symp = load_object(flocp, noerror, *ldname, symname);
  if (! symp)
    return 0;

  /* Invoke the symbol.  */
  r = (*symp) (flocp);

  /* If it succeeded, add the load file to the loaded variable.  */
  if (r > 0)
    do_variable_definition (flocp, ".LOADED", *ldname, o_default, f_append, 0);

  return r;
}

#else
