
/* This is the function registered with make  */
static char *
func_guile (const char *funcname UNUSED, int argc UNUSED, char **argv)
{
  if (argv[0] && argv[0][0] != '\0')
    return scm_with_guile (internal_guile_eval, argv[0]);

  return NULL;
}

/* ----- Public interface ----- */
