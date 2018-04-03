     debug(29, 2) ("authenticateDigestDone: Digest authentication shut down.\n");
 }
 
-static void
-authDigestCfgDump(StoreEntry * entry, const char *name, authScheme * scheme)
+void
+AuthDigestConfig::dump(StoreEntry * entry, const char *name, AuthConfig * scheme)
 {
-    auth_digest_config *config = static_cast < auth_digest_config * >(scheme->scheme_data);
-    wordlist *list = config->authenticate;
+    wordlist *list = authenticate;
     debug(29, 9) ("authDigestCfgDump: Dumping configuration\n");
     storeAppendPrintf(entry, "%s %s", name, "digest");
 
