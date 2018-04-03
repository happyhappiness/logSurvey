 static void
 authenticateNTLMStats(StoreEntry * sentry)
 {
-    storeAppendPrintf(sentry, "NTLM Authenticator Statistics:\n");
-    helperStatefulStats(sentry, ntlmauthenticators);
+    helperStatefulStats(sentry, ntlmauthenticators, "NTLM Authenticator Statistics");
 }
 
 
