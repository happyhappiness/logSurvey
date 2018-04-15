   return ret;
 }
 
+static int test_verify_sha256() {
+  int ret = 0;
+
+  int status = verify_sha256(
+      (char[]){'c', 'o', 'l', 'l', 'e', 'c', 't', 'd'}, 8, "admin", "admin",
+      (uint8_t[]){
+          0xcd, 0xa5, 0x9a, 0x37, 0xb0, 0x81, 0xc2, 0x31, 0x24, 0x2a, 0x6d,
+          0xbd, 0xfb, 0x44, 0xdb, 0xd7, 0x41, 0x2a, 0xf4, 0x29, 0x83, 0xde,
+          0xa5, 0x11, 0x96, 0xd2, 0xe9, 0x30, 0x21, 0xae, 0xc5, 0x45,
+      });
+  if (status != 0) {
+    fprintf(stderr, "verify_sha256() = %d, want 0\n", status);
+    ret = -1;
+  }
+
+  status = verify_sha256(
+      (char[]){'c', 'o', 'l', 'l', 'E', 'c', 't', 'd'}, 8, "admin", "admin",
+      (uint8_t[]){
+          0xcd, 0xa5, 0x9a, 0x37, 0xb0, 0x81, 0xc2, 0x31, 0x24, 0x2a, 0x6d,
+          0xbd, 0xfb, 0x44, 0xdb, 0xd7, 0x41, 0x2a, 0xf4, 0x29, 0x83, 0xde,
+          0xa5, 0x11, 0x96, 0xd2, 0xe9, 0x30, 0x21, 0xae, 0xc5, 0x45,
+      });
+  if (status != 1) {
+    fprintf(stderr, "verify_sha256() = %d, want 1\n", status);
+    ret = -1;
+  }
+
+  return ret;
+}
+
+static int test_decrypt_aes256() {
+  char const *iv_str = "4cbe2a747c9f9dcfa0e66f0c2fa74875";
+  uint8_t iv[16] = {0};
+  size_t iv_len = sizeof(iv);
+
+  char const *ciphertext_str =
+      "8f023b0b15178f8428da1221a5f653e840f065db4aff032c22e5a3df";
+  uint8_t ciphertext[28] = {0};
+  size_t ciphertext_len = sizeof(ciphertext);
+
+  if (decode_string(iv_str, iv, &iv_len) ||
+      decode_string(ciphertext_str, ciphertext, &ciphertext_len)) {
+    fprintf(stderr, "test_decrypt_aes256: decode_string failed.\n");
+    return -1;
+  }
+  assert(iv_len == sizeof(iv));
+  assert(ciphertext_len == sizeof(ciphertext));
+
+  int status = decrypt_aes256(
+      &(buffer_t){
+          .data = ciphertext, .len = ciphertext_len,
+      },
+      iv, iv_len, "admin");
+  if (status != 0) {
+    fprintf(stderr, "decrypt_aes256() = %d, want 0\n", status);
+    return -1;
+  }
+
+  char const *want = "collectd";
+  char got[9] = {0};
+  memmove(got, &ciphertext[20], sizeof(got) - 1);
+  if (strcmp(got, want) != 0) {
+    fprintf(stderr, "decrypt_aes256() = \"%s\", want \"%s\"\n", got, want);
+    return -1;
+  }
+
+  return 0;
+}
+
 int main(void) {
   int ret = 0;
 
