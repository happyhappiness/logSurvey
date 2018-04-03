          * challenge - release the helper and use the existing auth_user 
          * details. */
 
-        if (strncmp("NTLM ", proxy_auth, 5) == 0) {
-            ntlm_request->ntlmauthenticate = xstrdup(proxy_auth);
-        } else {
-            fatal("Incorrect scheme in auth header\n");
-            /* TODO: more fault tolerance.. reset the auth scheme here */
-        }
+        ntlm_request->ntlmauthenticate = xstrdup(proxy_auth);
 
         /* cache entries have authenticateauthheaderchallengestring */
         snprintf(ntlmhash, sizeof(ntlmhash) - 1, "%s%s",