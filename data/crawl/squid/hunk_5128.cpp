         memPoolDestroy(&ntlm_helper_state_pool);
     }
 
-    if (ntlm_user_pool) {
-        memPoolDestroy(&ntlm_user_pool);
-    }
-
 #endif
     debug(29, 2) ("authNTLMDone: NTLM authentication Shutdown.\n");
 }
 
 /* free any allocated configuration details */
-static void
-authNTLMFreeConfig(authScheme * scheme)
+void
+AuthNTLMConfig::done()
 {
-    if (ntlmConfig == NULL)
-        return;
-
-    assert(ntlmConfig == scheme->scheme_data);
-
-    if (ntlmConfig->authenticate)
-        wordlistDestroy(&ntlmConfig->authenticate);
-
-    xfree(ntlmConfig);
-
-    ntlmConfig = NULL;
+    if (authenticate)
+        wordlistDestroy(&authenticate);
 }
 
-static void
-authNTLMCfgDump(StoreEntry * entry, const char *name, authScheme * scheme)
+void
+AuthNTLMConfig::dump(StoreEntry * entry, const char *name, AuthConfig * scheme)
 {
-    auth_ntlm_config *config = static_cast<auth_ntlm_config *>(scheme->scheme_data);
-    wordlist *list = config->authenticate;
+    wordlist *list = authenticate;
     storeAppendPrintf(entry, "%s %s", name, "ntlm");
 
     while (list != NULL) {
