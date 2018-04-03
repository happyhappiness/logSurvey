 
 
         if (output_token.length) {
-#if !HAVE_SPNEGO
-            if (spnego_flag) {
-                if ((rc = makeNegTokenTarg((const unsigned char*)output_token.value,
-                                           output_token.length,
-                                           &spnegoToken, &spnegoTokenLength)) != 0) {
-                    if (debug)
-                        fprintf(stderr,
-                                "%s| %s: makeNegTokenTarg failed with rc=%d\n",
-                                LogTime(), PROGRAM, rc);
-                    fprintf(stdout, "BH makeNegTokenTarg failed with rc=%d\n",
-                            rc);
-                    goto cleanup;
-                }
-            } else {
-                spnegoToken = (const unsigned char*)output_token.value;
-                spnegoTokenLength = output_token.length;
-            }
-#else
             spnegoToken = (const unsigned char*)output_token.value;
             spnegoTokenLength = output_token.length;
-#endif
             token = (char*)xmalloc(ska_base64_encode_len(spnegoTokenLength));
             if (token == NULL) {
                 if (debug)
