{
  FILE *fp;
  char *upwd;
  char *htclfile;		/* HTML-clean file name */

  if (!output_stream)
    {
      fp = fopen (file, "wb");
      if (!fp)
	{
	  logprintf (LOG_NOTQUIET, "%s: %s\n", file, strerror (errno));
	  return FOPENERR;
	}
    }
  else
    fp = output_stream;
