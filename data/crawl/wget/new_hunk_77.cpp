static bool
cmd_use_askpass (const char *com _GL_UNUSED, const char *val, void *place)
{
  const char *env_name = "WGET_ASKPASS";
  const char *env;

  if (val && *val)
    return cmd_string (com, val, place);

  env = getenv (env_name);
  if (!(env && *env))
