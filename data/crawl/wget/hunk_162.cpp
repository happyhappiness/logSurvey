                            const char *refers_to, const ip_address *ip, FILE *body)
 {
   char revisit_uuid [48];
-  char *block_digest = NULL;
+  char block_digest[BASE32_LENGTH(SHA1_DIGEST_SIZE) + 1 + 5];
   char sha1_res_block[SHA1_DIGEST_SIZE];
 
   warc_uuid_str (revisit_uuid);
 
   sha1_stream (body, sha1_res_block);
-  block_digest = warc_base32_sha1_digest (sha1_res_block);
+  warc_base32_sha1_digest (sha1_res_block, block_digest, sizeof(block_digest));
 
   warc_write_start_record ();
   warc_write_header ("WARC-Type", "revisit");
