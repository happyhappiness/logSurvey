             fprintf(stdout, "BH Invalid negotiate request\n");
             continue;
         }
-        input_token.length = (size_t)base64_decode_len(buf+3);
+        const uint8_t *b64Token = reinterpret_cast<const uint8_t*>(buf+3);
+        input_token.length = BASE64_DECODE_LENGTH(strlen(buf+3));
         debug((char *) "%s| %s: DEBUG: Decode '%s' (decoded length: %d).\n",
-              LogTime(), PROGRAM, buf + 3, (int) input_token.length);
+              LogTime(), PROGRAM, b64Token, (int) input_token.length);
         input_token.value = xmalloc(input_token.length);
 
-        input_token.length = (size_t)base64_decode((char *) input_token.value, (unsigned int)input_token.length, buf+3);
+        struct base64_decode_ctx ctx;
+        base64_decode_init(&ctx);
+        size_t dstLen = 0;
+        if (!base64_decode_update(&ctx, &dstLen, static_cast<uint8_t*>(input_token.value), input_token.length, b64Token) ||
+                !base64_decode_final(&ctx)) {
+            debug((char *) "%s| %s: ERROR: Invalid base64 token [%s]\n", LogTime(), PROGRAM, b64Token);
+            fprintf(stdout, "BH Invalid negotiate request token\n");
+            continue;
+        }
+        input_token.length = dstLen;
 
         if ((input_token.length >= sizeof ntlmProtocol + 1) &&
                 (!memcmp(input_token.value, ntlmProtocol, sizeof ntlmProtocol))) {
