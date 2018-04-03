       || field_num_record_id == -1)
     {
       if (field_num_original_url == -1)
-        logprintf (LOG_NOTQUIET, _("CDX file does not list original urls. (Missing column 'a'.)\n"));
+        logprintf (LOG_NOTQUIET,
+_("CDX file does not list original urls. (Missing column 'a'.)\n"));
       if (field_num_checksum == -1)
-        logprintf (LOG_NOTQUIET, _("CDX file does not list checksums. (Missing column 'k'.)\n"));
+        logprintf (LOG_NOTQUIET,
+_("CDX file does not list checksums. (Missing column 'k'.)\n"));
       if (field_num_record_id == -1)
-        logprintf (LOG_NOTQUIET, _("CDX file does not list record ids. (Missing column 'u'.)\n"));
+        logprintf (LOG_NOTQUIET,
+_("CDX file does not list record ids. (Missing column 'u'.)\n"));
     }
   else
     {
       /* Initialize the table. */
-      warc_cdx_dedup_table = hash_table_new (1000, warc_hash_sha1_digest, warc_cmp_sha1_digest);
+      warc_cdx_dedup_table = hash_table_new (1000, warc_hash_sha1_digest,
+                                             warc_cmp_sha1_digest);
 
       do
         {
           line_length = getline (&lineptr, &n, f);
           if (line_length != -1)
-            warc_process_cdx_line (lineptr, field_num_original_url, field_num_checksum, field_num_record_id);
+            {
+              warc_process_cdx_line (lineptr, field_num_original_url,
+                            field_num_checksum, field_num_record_id);
+            }
 
         }
       while (line_length != -1);
