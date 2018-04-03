  if (redirect_location == NULL || strlen(redirect_location) == 0)
    redirect_location = "-";

  char offset_string[22];
  number_to_string (offset_string, offset);

  /* Print the CDX line. */
  fprintf (warc_current_cdx_file, "%s %s %s %s %d %s %s - %s %s %s\n", url,
           timestamp_str_cdx, url, mime_type, response_code, checksum,
           redirect_location, offset_string, warc_current_filename,
           response_uuid);
  fflush (warc_current_cdx_file);

  return true;
