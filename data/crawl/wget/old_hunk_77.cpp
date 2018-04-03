static bool
cmd_use_askpass (const char *com _GL_UNUSED, const char *val, void *place)
{
  char *env_name = "WGET_ASKPASS";
  char *env;

  if (val && *val)
    {
      if (!file_exists_p (val))
        {
          fprintf (stderr, _("%s does not exist.\n"), val);
          exit (WGET_EXIT_GENERIC_ERROR);
        }
      return cmd_string (com, val, place);
    }

  env = getenv (env_name);
  if (!(env && *env))
