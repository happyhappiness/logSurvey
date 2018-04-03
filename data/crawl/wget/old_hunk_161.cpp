      if (warc_sha1_stream_with_payload (file, sha1_res_block,
          sha1_res_payload, payload_offset) == 0)
        {
          char *digest;

          digest = warc_base32_sha1_digest (sha1_res_block);
          warc_write_header ("WARC-Block-Digest", digest);
          xfree (digest);

          if (payload_offset >= 0)
            {
              digest = warc_base32_sha1_digest (sha1_res_payload);
              warc_write_header ("WARC-Payload-Digest", digest);
              xfree (digest);
            }
        }
    }
}
