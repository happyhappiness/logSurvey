{
  int status;

  LCC_DEBUG ("send:    --> %s\n", command);

  status = fprintf (c->fh, "%s\r\n", command);
  if (status < 0)
