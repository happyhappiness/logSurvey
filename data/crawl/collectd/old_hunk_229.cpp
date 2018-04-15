  char ident_str[1024] = "";
  int timeout = -1;
  char hostname[1024];
  char c;

  static struct option long_options[] =
    {
      {"help", no_argument, 0, 'h'},
      {"socket", required_argument, 0, 's'},
      {"plugin", required_argument, 0, 'p'},
      {"identifier", required_argument, 0, 'i'},
      {"timeout", required_argument, 0, 't'}
    };
  int option_index = 0;


  while ((c = getopt_long (argc, argv, "s:p:i:ht:", long_options, &option_index)) != -1) {
    switch (c) {
      case 's':
        snprintf (address, sizeof (address), "unix:%s", optarg);
        break;
      case 'p':
        plugin = optarg;
        break;
      case 'i':
        if(charoccurences(optarg, '/') == 1) {
          /* The user has omitted the hostname part of the identifier
           * (there is only one '/' in the identifier)
           * Let's add the local hostname */
          if(gethostname(hostname, sizeof(hostname)) != 0) {
            fprintf (stderr, "Could not get local hostname: %s", strerror(errno));
            return 1;
          }
          /* Make sure hostname is zero-terminated */
          hostname[sizeof(hostname)-1] = '\0';
          snprintf (ident_str, sizeof (ident_str), "%s/%s", hostname, optarg);
          /* Make sure ident_str is zero terminated */
          ident_str[sizeof(ident_str)-1] = '\0';
        } else {
          strncpy(ident_str, optarg, sizeof (ident_str));
          /* Make sure identifier is zero terminated */
          ident_str[sizeof(ident_str)-1] = '\0';
        }
        break;
      case 't':
        timeout = atoi (optarg);
        break;
      case 'h':
        exit_usage (argv[0], 0);
      default:
        exit_usage (argv[0], 1);
    }
