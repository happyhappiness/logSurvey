     content_type = "application/octet-stream";
 
   warc_write_start_record ();
-  warc_write_header ("WARC-Type", "resource");
+  warc_write_header ("WARC-Type", record_type);
   warc_write_header ("WARC-Record-ID", resource_uuid);
   warc_write_header ("WARC-Warcinfo-ID", warc_current_warcinfo_uuid_str);
   warc_write_header ("WARC-Concurrent-To", concurrent_to_uuid);
