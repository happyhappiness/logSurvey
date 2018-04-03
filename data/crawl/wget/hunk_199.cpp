 warc_write_date_header (const char *timestamp)
 {
   char current_timestamp[21];
-  if (timestamp == NULL)
-    {
-      warc_timestamp (current_timestamp);
-      timestamp = current_timestamp;
-    }
-  return warc_write_header ("WARC-Date", timestamp);
+
+  return warc_write_header ("WARC-Date", timestamp ? timestamp :
+                            warc_timestamp (current_timestamp, sizeof(current_timestamp)));
 }
 
 /* Writes the WARC-IP-Address header for the given IP to
