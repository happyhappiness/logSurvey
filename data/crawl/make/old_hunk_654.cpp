
  argv += 1 + !result;

  if (argv[0])
    {
      char *expansion;

      expansion = expand_argument (argv[0], NULL);

      o = variable_buffer_output (o, expansion, strlen (expansion));

