  warc_write_header ("WARC-Record-ID", response_uuid);
  warc_write_header ("WARC-Warcinfo-ID", warc_current_warcinfo_uuid_str);
  warc_write_header ("WARC-Concurrent-To", concurrent_to_uuid);
  warc_write_header_uri ("WARC-Target-URI", url);
  warc_write_date_header (timestamp_str);
  warc_write_ip_header (ip);
  warc_write_header ("WARC-Block-Digest", block_digest);
