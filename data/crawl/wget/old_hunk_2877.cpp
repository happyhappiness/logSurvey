  struct file_memory *fm = read_file (filename);
  if (!fm)
    {
      logprintf (LOG_NOTQUIET, "Cannot open %s: %s",
		 filename, strerror (errno));
      return NULL;
    }
