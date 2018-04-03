  /* ...to a buffer.  */
  load_file (fp, &buf, &size);
  fclose (fp);
  /* Now open the file for writing.  */
  fp = fopen (file, "wb");
  if (!fp)
