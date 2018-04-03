    return result;

  /* only do this if pinnedpubkey starts with "sha256//", length 8 */
  if (strncmp (pinnedpubkey, "sha256//", 8) == 0) {
    /* compute sha256sum of public key */
    sha256sumdigest = xmalloc (SHA256_DIGEST_SIZE);
    sha256_buffer (pubkey, pubkeylen, sha256sumdigest);
    expectedsha256sumdigest = xmalloc (SHA256_DIGEST_SIZE + 1);

    /* it starts with sha256//, copy so we can modify it */
    pinkeylen = strlen (pinnedpubkey) + 1;
    pinkeycopy = xmalloc (pinkeylen);
    memcpy (pinkeycopy, pinnedpubkey, pinkeylen);

    /* point begin_pos to the copy, and start extracting keys */
    begin_pos = pinkeycopy;
    do
      {
        end_pos = strstr (begin_pos, ";sha256//");
        /*
         * if there is an end_pos, null terminate,
         * otherwise it'll go to the end of the original string
         */
        if (end_pos)
          end_pos[0] = '\0';

        /* decode base64 pinnedpubkey, 8 is length of "sha256//" */
        decoded_hash_length = wget_base64_decode (begin_pos + 8, expectedsha256sumdigest);
        /* if valid base64, compare sha256 digests directly */
        if (SHA256_DIGEST_SIZE == decoded_hash_length &&
           !memcmp (sha256sumdigest, expectedsha256sumdigest, SHA256_DIGEST_SIZE)) {
          result = true;
          break;
        }

        /*
         * change back the null-terminator we changed earlier,
         * and look for next begin
         */
        if (end_pos) {
          end_pos[0] = ';';
          begin_pos = strstr (end_pos, "sha256//");
        }
      } while (end_pos && begin_pos);

    xfree (sha256sumdigest);
    xfree (expectedsha256sumdigest);
    xfree (pinkeycopy);

    return result;
  }

  /* fall back to assuming this is a file path */
  fm = wget_read_file (pinnedpubkey);
