  VA_PRINTF (stderr, fmt, args);
  VA_END (args);

  fputs (".  Stop.\n", stderr);

  die (2);
}
