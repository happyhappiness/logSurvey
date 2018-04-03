  int i;

  printf (_("GNU Wget %s, a non-interactive network retriever.\n"),
          VERSION_STRING);
  print_usage ();

  for (i = 0; i < countof (help); i++)
