 static void
 authenticateNegotiateStats(StoreEntry * sentry)
 {
-    storeAppendPrintf(sentry, "NEGOTIATE Authenticator Statistics:\n");
-    helperStatefulStats(sentry, negotiateauthenticators);
+    helperStatefulStats(sentry, negotiateauthenticators, "NEGOTIATE Authenticator Statistics");
 }
 
 
