     }
 
     storeAppendPrintf(entry, "\n%s %s children %d\n%s %s max_challenge_reuses %d\n%s %s max_challenge_lifetime %d seconds\n",
-                      name, "ntlm", config->authenticateChildren,
-                      name, "ntlm", config->challengeuses,
-                      name, "ntlm", (int) config->challengelifetime);
+                      name, "ntlm", authenticateChildren,
+                      name, "ntlm", challengeuses,
+                      name, "ntlm", (int) challengelifetime);
 
 }
 
-static void
-authNTLMParse(authScheme * scheme, int n_configured, char *param_str)
+AuthNTLMConfig::AuthNTLMConfig()
 {
-    if (scheme->scheme_data == NULL) {
-        assert(ntlmConfig == NULL);
-        /* this is the first param to be found */
-        scheme->scheme_data = xmalloc(sizeof(auth_ntlm_config));
-        memset(scheme->scheme_data, 0, sizeof(auth_ntlm_config));
-        ntlmConfig = static_cast<auth_ntlm_config *>(scheme->scheme_data);
-        ntlmConfig->authenticateChildren = 5;
-        ntlmConfig->challengeuses = 0;
-        ntlmConfig->challengelifetime = 60;
-    }
-
-    ntlmConfig = static_cast<auth_ntlm_config *>(scheme->scheme_data);
+    /* TODO Move into initialisation list */
+    authenticateChildren = 5;
+    challengeuses = 0;
+    challengelifetime = 60;
+}
 
+void
+AuthNTLMConfig::parse(AuthConfig * scheme, int n_configured, char *param_str)
+{
     if (strcasecmp(param_str, "program") == 0) {
-        if (ntlmConfig->authenticate)
-            wordlistDestroy(&ntlmConfig->authenticate);
+        if (authenticate)
+            wordlistDestroy(&authenticate);
 
-        parse_wordlist(&ntlmConfig->authenticate);
+        parse_wordlist(&authenticate);
 
-        requirePathnameExists("authparam ntlm program", ntlmConfig->authenticate->key);
+        requirePathnameExists("authparam ntlm program", authenticate->key);
     } else if (strcasecmp(param_str, "children") == 0) {
-        parse_int(&ntlmConfig->authenticateChildren);
+        parse_int(&authenticateChildren);
     } else if (strcasecmp(param_str, "max_challenge_reuses") == 0) {
-        parse_int(&ntlmConfig->challengeuses);
+        parse_int(&challengeuses);
     } else if (strcasecmp(param_str, "max_challenge_lifetime") == 0) {
-        parse_time_t(&ntlmConfig->challengelifetime);
+        parse_time_t(&challengelifetime);
     } else {
         debug(28, 0) ("unrecognised ntlm auth scheme parameter '%s'\n", param_str);
     }
