         exit(1);
 }
 
+static bool
+token_decode(size_t *decodedLen, uint8_t decoded[], const char *buf)
+{
+    struct base64_decode_ctx ctx;
+    base64_decode_init(&ctx);
+    if (!base64_decode_update(&ctx, decodedLen, decoded, strlen(buf), reinterpret_cast<const uint8_t*>(buf)) ||
+            !base64_decode_final(&ctx)) {
+        SEND("BH base64 decode failed");
+        fprintf(stderr, "ERROR: base64 decoding failed for: '%s'\n", buf);
+        return false;
+    }
+    return true;
+}
+
 int
 manage_request()
 {
     char buf[HELPER_INPUT_BUFFER];
-    char decoded[HELPER_INPUT_BUFFER];
-    int decodedLen;
+    uint8_t decoded[HELPER_INPUT_BUFFER];
+    size_t decodedLen = 0;
     char helper_command[3];
     char *c;
     int status;
