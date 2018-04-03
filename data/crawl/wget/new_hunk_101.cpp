{
  warc_write_start_record ();
  warc_write_header ("WARC-Type", "request");
  warc_write_header_uri ("WARC-Target-URI", url);
  warc_write_header ("Content-Type", "application/http;msgtype=request");
  warc_write_date_header (timestamp_str);
  warc_write_header ("WARC-Record-ID", record_uuid);
