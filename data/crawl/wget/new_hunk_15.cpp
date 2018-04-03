  char *env = getenv ("WGETRC");
  if (env && *env)
    {
      file_stats_t flstat;
      if (!file_exists_p (env, &flstat))
        {
          fprintf (stderr, _("%s: WGETRC points to %s, which couldn't be accessed because of error: %s.\n"),
                   exec_name, env, strerror(flstat.access_err));
          exit (WGET_EXIT_GENERIC_ERROR);
        }
      return xstrdup (env);
