  if (fh == NULL)
    return (-1);

  while (fgets (buffer, sizeof (buffer), fh) != NULL)
  {
    buffer_len = strchomp (buffer);