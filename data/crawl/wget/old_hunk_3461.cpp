    {
      if (!file_exists_p (env))
	{
	  fprintf (stderr, "%s: %s: %s.\n", exec_name, file, strerror (errno));
	  exit (1);
	}
      return xstrdup (env);
