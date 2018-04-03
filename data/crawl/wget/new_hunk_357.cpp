
  printf (_("GNU Wget %s, a non-interactive network retriever.\n"),
          version_string);
  print_usage (0);

  for (i = 0; i < countof (help); i++)
    fputs (_(help[i]), stdout);
