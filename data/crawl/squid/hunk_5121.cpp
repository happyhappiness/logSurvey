     authenticateStateFree(r);
 }
 
-static void
-authBasicCfgDump(StoreEntry * entry, const char *name, authScheme * scheme)
+void
+AuthBasicConfig::dump(StoreEntry * entry, const char *name, AuthConfig * scheme)
 {
-    auth_basic_config *config = static_cast<auth_basic_config *>(scheme->scheme_data);
-    wordlist *list = config->authenticate;
+    wordlist *list = authenticate;
     storeAppendPrintf(entry, "%s %s", name, "basic");
 
     while (list != NULL) {
