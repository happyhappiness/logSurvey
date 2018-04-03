   Calling this function will close body.
   Returns true on success, false on error. */
bool
warc_write_request_record (char *url, char *timestamp_str, char *record_uuid,
                           ip_address *ip, FILE *body, off_t payload_offset)
{
  warc_write_start_record ();
  warc_write_header ("WARC-Type", "request");
