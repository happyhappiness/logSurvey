     {
       /* Calculate the block and payload digests. */
       rewind (body);
-      if (warc_sha1_stream_with_payload (body, sha1_res_block, sha1_res_payload, payload_offset) == 0)
+      if (warc_sha1_stream_with_payload (body, sha1_res_block, sha1_res_payload,
+          payload_offset) == 0)
         {
           /* Decide (based on url + payload digest) if we have seen this
              data before. */
-          struct warc_cdx_record *rec_existing = warc_find_duplicate_cdx_record (url, sha1_res_payload);
+          struct warc_cdx_record *rec_existing;
+          rec_existing = warc_find_duplicate_cdx_record (url, sha1_res_payload);
           if (rec_existing != NULL)
             {
+              bool result;
+
               /* Found an existing record. */
-              logprintf (LOG_VERBOSE, _("Found exact match in CDX file. Saving revisit record to WARC.\n"));
+              logprintf (LOG_VERBOSE,
+          _("Found exact match in CDX file. Saving revisit record to WARC.\n"));
 
               /* Remove the payload from the file. */
               if (payload_offset > 0)
