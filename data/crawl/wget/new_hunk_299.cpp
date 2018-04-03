  warc_write_header ("Content-Type", content_type);
  warc_write_block_from_file (body);
  warc_write_end_record ();

  fclose (body);

  return warc_write_ok;
}
