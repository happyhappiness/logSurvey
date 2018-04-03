  warc_write_header ("WARC-Payload-Digest", payload_digest);
  warc_write_block_from_file (body);
  warc_write_end_record ();

  fclose (body);
  free (block_digest);

