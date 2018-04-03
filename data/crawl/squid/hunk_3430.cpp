         if ((input_token.length >= sizeof ntlmProtocol + 1) &&
                 (!memcmp(input_token.value, ntlmProtocol, sizeof ntlmProtocol))) {
             if (debug)
-                fprintf(stderr, "%s| %s: received type %d NTLM token\n",
+                fprintf(stderr, "%s| %s: WARNING: received type %d NTLM token\n",
                         LogTime(), PROGRAM,
                         (int) *((unsigned char *) input_token.value +
                                 sizeof ntlmProtocol));
