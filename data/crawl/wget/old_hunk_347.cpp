  windows_main ((char **) &exec_name);
#endif

  /* Set option defaults; read the system wgetrc and ~/.wgetrc.  */
  initialize ();

  init_switches ();
  longindex = -1;
  while ((ret = getopt_long (argc, argv,
                             short_options, long_options, &longindex)) != -1)
