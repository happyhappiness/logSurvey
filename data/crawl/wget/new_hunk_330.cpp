
  size_t i;

  if (printf (_("GNU Wget %s, a non-interactive network retriever.\n"),
              version_string))
    exit (3);
  if (print_usage (0) < 0)
    exit (3);

  for (i = 0; i < countof (help); i++)
    if (fputs (_(help[i]), stdout) < 0)
      exit (3);

  exit (0);
}
