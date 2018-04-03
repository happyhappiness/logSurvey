    exit_usage (argv[0], 1);
  }

  if (strcasecmp (argv[optind], "flush") == 0)
    status = flush (address, argc - optind, argv + optind);
  else {
    fprintf (stderr, "%s: invalid command: %s\n", argv[0], argv[optind]);
    return (1);
  }

  if (status != 0)
    return (status);
  return (0);