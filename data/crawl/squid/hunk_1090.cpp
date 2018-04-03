         if (output_token.length) {
             spnegoToken = (const unsigned char *) output_token.value;
             spnegoTokenLength = output_token.length;
-            token = (char *) xmalloc((size_t)base64_encode_len((int)spnegoTokenLength));
+            token = (char *) xmalloc((size_t)base64_encode_len(spnegoTokenLength));
             if (token == NULL) {
                 debug((char *) "%s| %s: ERROR: Not enough memory\n", LogTime(), PROGRAM);
                 fprintf(stdout, "BH Not enough memory\n");
                 goto cleanup;
             }
-            base64_encode_str(token, base64_encode_len((int)spnegoTokenLength),
-                              (const char *) spnegoToken, (int)spnegoTokenLength);
+            struct base64_encode_ctx tokCtx;
+            base64_encode_init(&tokCtx);
+            size_t blen = base64_encode_update(&tokCtx, reinterpret_cast<uint8_t*>(token), spnegoTokenLength, reinterpret_cast<const uint8_t*>(spnegoToken));
+            blen += base64_encode_final(&tokCtx, reinterpret_cast<uint8_t*>(token)+blen);
+            token[blen] = '\0';
 
             if (check_gss_err(major_status, minor_status, "gss_accept_sec_context()", log, 1))
                 goto cleanup;
