     redirect_location = "-";
 
   /* Print the CDX line. */
-  fprintf (warc_current_cdx_file, "%s %s %s %s %d %s %s - %ld %s %s\n", url, timestamp_str_cdx, url, mime_type, response_code, checksum, redirect_location, offset, warc_current_filename, response_uuid);
+  fprintf (warc_current_cdx_file, "%s %s %s %s %d %s %s - %ld %s %s\n", url,
+           timestamp_str_cdx, url, mime_type, response_code, checksum,
+           redirect_location, offset, warc_current_filename, response_uuid);
   fflush (warc_current_cdx_file);
 
   return true;
