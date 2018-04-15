  if (fh == NULL)
  {
    char errbuf[1024];
    ERROR ("open (%s) failed: %s", 
	file, sstrerror (errno, errbuf, sizeof (errbuf)));
    return (-1);
  }