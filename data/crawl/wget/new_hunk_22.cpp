  warc_write_header ("WARC-Refers-To", refers_to);
  warc_write_header ("WARC-Profile", "http://netpreserve.org/warc/1.0/revisit/identical-payload-digest");
  warc_write_header ("WARC-Truncated", "length");
  warc_write_header_uri ("WARC-Target-URI", url);
  warc_write_date_header (timestamp_str);
  warc_write_ip_header (ip);
  warc_write_header ("Content-Type", "application/http;msgtype=response");
