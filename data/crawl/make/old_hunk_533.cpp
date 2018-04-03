  return cvt_scm_to_str (scm_c_eval_string (arg));
}

/* ----- Public interface ----- */

/* This is the make interface for passing programs to Guile.  */
char *
guile_eval_string (char *str)
{
  return scm_with_guile (internal_guile_eval, str);
}

void
setup_guile ()
{
  scm_with_guile (guile_init, NULL);

  /* Add 'guile' to the list of features. */
  do_variable_definition (NILF, ".FEATURES", "guile", o_default, f_append, 0);
}
