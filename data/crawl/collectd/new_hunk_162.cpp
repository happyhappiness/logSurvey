{
  int status;

  lcc_tracef ("send:    --> %s\n", command);

  status = fprintf (c->fh, "%s\r\n", command);
  if (status < 0)
