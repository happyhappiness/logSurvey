       if (warc_sha1_stream_with_payload (file, sha1_res_block,
           sha1_res_payload, payload_offset) == 0)
         {
-          char *digest;
+          char digest[BASE32_LENGTH(SHA1_DIGEST_SIZE) + 1 + 5];
 
-          digest = warc_base32_sha1_digest (sha1_res_block);
-          warc_write_header ("WARC-Block-Digest", digest);
-          xfree (digest);
+          warc_write_header ("WARC-Block-Digest",
+              warc_base32_sha1_digest (sha1_res_block, digest, sizeof(digest)));
 
           if (payload_offset >= 0)
-            {
-              digest = warc_base32_sha1_digest (sha1_res_payload);
-              warc_write_header ("WARC-Payload-Digest", digest);
-              xfree (digest);
-            }
+              warc_write_header ("WARC-Payload-Digest",
+                  warc_base32_sha1_digest (sha1_res_payload, digest, sizeof(digest)));
         }
     }
 }
