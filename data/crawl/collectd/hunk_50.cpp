   uint8_t pwhash[32] = {0};
   gcry_md_hash_buffer(GCRY_MD_SHA256, pwhash, password, strlen(password));
 
-  fprintf(stderr, "sizeof(iv) = %zu\n", sizeof(iv));
+  fprintf(stderr, "sizeof(iv) = %" PRIsz "\n", sizeof(iv));
   if (gcry_cipher_setkey(cipher, pwhash, sizeof(pwhash)) ||
       gcry_cipher_setiv(cipher, iv, iv_size) ||
       gcry_cipher_decrypt(cipher, b->data, b->len, /* in = */ NULL,
