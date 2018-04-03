   return 0;
 }
 
-int lcc_network_parse(void *data, size_t data_size, lcc_value_list_writer_t w) {
+static int verify_sha256(void *payload, size_t payload_size,
+                         char const *username, char const *password,
+                         uint8_t hash_provided[32]) {
+  gcry_md_hd_t hd = NULL;
+
+  gcry_error_t err = gcry_md_open(&hd, GCRY_MD_SHA256, GCRY_MD_FLAG_HMAC);
+  if (err != 0) {
+    /* TODO(octo): use gcry_strerror(err) to create an error string. */
+    return -1;
+  }
+
+  err = gcry_md_setkey(hd, password, strlen(password));
+  if (err != 0) {
+    gcry_md_close(hd);
+    return -1;
+  }
+
+  gcry_md_write(hd, username, strlen(username));
+  gcry_md_write(hd, payload, payload_size);
+
+  unsigned char *hash_calculated = gcry_md_read(hd, GCRY_MD_SHA256);
+  if (!hash_calculated) {
+    gcry_md_close(hd);
+    return -1;
+  }
+
+  int ret = memcmp(hash_provided, hash_calculated, 32);
+
+  gcry_md_close(hd);
+  hash_calculated = NULL;
+
+  return !!ret;
+}
+
+static int parse_sign_sha256(void *signature, size_t signature_len,
+                             void *payload, size_t payload_size,
+                             lcc_network_parse_options_t const *opts) {
+  if (opts->password_lookup == NULL) {
+    /* TODO(octo): print warning */
+    return network_parse(payload, payload_size, NONE, opts);
+  }
+
+  buffer_t *b = &(buffer_t){
+      .data = signature, .len = signature_len,
+  };
+
+  uint8_t hash[32];
+  if (buffer_next(b, hash, sizeof(hash)))
+    return EINVAL;
+
+  char username[b->len + 1];
+  memset(username, 0, sizeof(username));
+  if (buffer_next(b, username, sizeof(username) - 1)) {
+    return EINVAL;
+  }
+
+  char const *password = opts->password_lookup(username);
+  if (!password)
+    return network_parse(payload, payload_size, NONE, opts);
+
+  int status = verify_sha256(payload, payload_size, username, password, hash);
+  if (status != 0)
+    return status;
+
+  return network_parse(payload, payload_size, SIGN, opts);
+}
+
+static int decrypt_aes256(buffer_t *b, void *iv, size_t iv_size,
+                          char const *password) {
+  gcry_cipher_hd_t cipher = NULL;
+
+  if (gcry_cipher_open(&cipher, GCRY_CIPHER_AES256, GCRY_CIPHER_MODE_OFB,
+                       /* flags = */ 0))
+    return -1;
+
+  uint8_t pwhash[32] = {0};
+  gcry_md_hash_buffer(GCRY_MD_SHA256, pwhash, password, strlen(password));
+
+  fprintf(stderr, "sizeof(iv) = %zu\n", sizeof(iv));
+  if (gcry_cipher_setkey(cipher, pwhash, sizeof(pwhash)) ||
+      gcry_cipher_setiv(cipher, iv, iv_size) ||
+      gcry_cipher_decrypt(cipher, b->data, b->len, /* in = */ NULL,
+                          /* in_size = */ 0)) {
+    gcry_cipher_close(cipher);
+    return -1;
+  }
+
+  gcry_cipher_close(cipher);
+  return 0;
+}
+
+static int parse_encrypt_aes256(void *data, size_t data_size,
+                                lcc_network_parse_options_t const *opts) {
+  if (opts->password_lookup == NULL) {
+    /* TODO(octo): print warning */
+    return ENOENT;
+  }
+
+  buffer_t *b = &(buffer_t){
+      .data = data, .len = data_size,
+  };
+
+  uint16_t username_len;
+  if (buffer_uint16(b, &username_len))
+    return EINVAL;
+  if ((size_t)username_len > data_size)
+    return ENOMEM;
+  char username[((size_t)username_len) + 1];
+  memset(username, 0, sizeof(username));
+  if (buffer_next(b, username, sizeof(username)))
+    return EINVAL;
+
+  char const *password = opts->password_lookup(username);
+  if (!password)
+    return ENOENT;
+
+  uint8_t iv[16];
+  if (buffer_next(b, iv, sizeof(iv)))
+    return EINVAL;
+
+  int status = decrypt_aes256(b, iv, sizeof(iv), password);
+  if (status != 0)
+    return status;
+
+  uint8_t hash_provided[20];
+  if (buffer_next(b, hash_provided, sizeof(hash_provided))) {
+    return -1;
+  }
+
+  uint8_t hash_calculated[20];
+  gcry_md_hash_buffer(GCRY_MD_SHA1, hash_calculated, b->data, b->len);
+
+  if (memcmp(hash_provided, hash_calculated, sizeof(hash_provided)) != 0) {
+    return -1;
+  }
+
+  return network_parse(b->data, b->len, ENCRYPT, opts);
+}
+
+static int network_parse(void *data, size_t data_size, lcc_security_level_t sl,
+                         lcc_network_parse_options_t const *opts) {
   buffer_t *b = &(buffer_t){
       .data = data, .len = data_size,
   };
