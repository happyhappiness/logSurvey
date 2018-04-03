             fprintf(stdout, "BH Invalid negotiate request\n");
             continue;
         }
-        length = base64_decode_len(buf+3);
+        length = BASE64_DECODE_LENGTH(strlen(buf+3));
         if (debug)
             fprintf(stderr, "%s| %s: Decode '%s' (decoded length: %d).\n",
                     LogTime(), PROGRAM, buf + 3, (int) length);
 
-        if ((token = (char *)xmalloc(length)) == NULL) {
+        if ((token = static_cast<uint8_t *>(xmalloc(length))) == NULL) {
             fprintf(stderr, "%s| %s: Error allocating memory for token\n", LogTime(), PROGRAM);
             return 1;
         }
 
-        length = base64_decode(token, length, buf+3);
+        struct base64_decode_ctx ctx;
+        base64_decode_init(&ctx);
+        size_t dstLen = 0;
+        if (!base64_decode_update(&ctx, &dstLen, token, strlen(buf+3), reinterpret_cast<const uint8_t*>(buf+3)) ||
+                !base64_decode_final(&ctx)) {
+            if (debug)
+                fprintf(stderr, "%s| %s: Invalid base64 token [%s]\n", LogTime(), PROGRAM, buf+3);
+            fprintf(stdout, "BH Invalid negotiate request token\n");
+            continue;
+        }
+        length = dstLen;
+        token[dstLen] = '\0';
 
         if ((static_cast<size_t>(length) >= sizeof(ntlmProtocol) + 1) &&
                 (!memcmp(token, ntlmProtocol, sizeof ntlmProtocol))) {
