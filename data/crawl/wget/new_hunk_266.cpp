  fflush (warc_tmp_fp);
  fprintf (warc_tmp_fp, "%s\n", program_argstring);

  warc_write_resource_record (NULL,
                   "metadata://gnu.org/software/wget/warc/wget_arguments.txt",
                              NULL, manifest_uuid, NULL, "text/plain",
                              warc_tmp_fp, -1);
  /* warc_write_resource_record has closed warc_tmp_fp. */

