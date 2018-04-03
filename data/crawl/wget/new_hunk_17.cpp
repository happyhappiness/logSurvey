  int ln;
  int errcnt = 0;

  fp = fopen_stat (file, "r", flstats);
  if (!fp)
    {
      fprintf (stderr, _("%s: Cannot read %s (%s).\n"), exec_name,
