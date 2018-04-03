    /* Do it only once.  */
    return;

  printf ("%sGNU Make %s (%s)", precede, version_string, make_host);
  if (remote_description != 0 && *remote_description != '\0')
    printf ("-%s", remote_description);

