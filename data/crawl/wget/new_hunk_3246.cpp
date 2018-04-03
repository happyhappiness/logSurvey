  windows_main_junk (&argc, (char **) argv, (char **) &exec_name);
#endif

  /* Set option defaults; read the system wgetrc and ~/.wgetrc.  */
  initialize ();

  init_switches ();
  longindex = -1;
  while ((ret = getopt_long (argc, argv,
			     short_options, long_options, &longindex)) != -1)
    {
      int val;
      struct cmdline_option *opt;
      if (ret == '?')
	{
	  print_usage ();
	  printf ("\n");
	  printf (_("Try `%s --help' for more options.\n"), exec_name);
	  exit (2);
	}

      /* If LONGINDEX is unchanged, it means RET is referring a short
	 option.  Look it up in the mapping table.  */
      if (longindex == -1)
	longindex = optmap[ret - 32];
      val = long_options[longindex].val;

      /* Use the retrieved value to locate the option in the
	 option_data array, and to see if we're dealing with the
	 negated "--no-FOO" variant of the boolean option "--foo".  */
      opt = &option_data[val & ~BOOLEAN_NEG_MARKER];
      switch (opt->type)
	{
	case OPT_VALUE:
	  setoptval (opt->handle_cmd, optarg);
	  break;
	case OPT_BOOLEAN:
	  if (optarg)
	    /* The user has specified a value -- use it. */
	    setoptval (opt->handle_cmd, optarg);
	  else
	    {
	      /* NEG is true for `--no-FOO' style boolean options. */
	      int neg = val & BOOLEAN_NEG_MARKER;
	      setoptval (opt->handle_cmd, neg ? "0" : "1");
	    }
	  break;
	case OPT__APPEND_OUTPUT:
	  setoptval ("logfile", optarg);
	  append_to_log = 1;
	  break;
	case OPT__HELP:
	  print_help ();
#ifdef WINDOWS
	  ws_help (exec_name);
#endif
	  exit (0);
	  break;
	case OPT__EXECUTE:
	  run_command (optarg);
	  break;
	case OPT__NO:
	  {
	    /* We support real --no-FOO flags now, but keep these
	       short options for convenience and backward
	       compatibility.  */
	    char *p;
	    for (p = optarg; *p; p++)
	      switch (*p)
		{
		case 'v':
		  setoptval ("verbose", "0");
		  break;
		case 'H':
		  setoptval ("addhostdir", "0");
		  break;
		case 'd':
		  setoptval ("dirstruct", "0");
		  break;
		case 'c':
		  setoptval ("noclobber", "1");
		  break;
		case 'p':
		  setoptval ("noparent", "1");
		  break;
		default:
		  printf (_("%s: illegal option -- `-n%c'\n"), exec_name, *p);
