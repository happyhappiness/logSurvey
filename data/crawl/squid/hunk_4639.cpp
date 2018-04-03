 static void
 authenticateBasicStats(StoreEntry * sentry)
 {
-    storeAppendPrintf(sentry, "Basic Authenticator Statistics:\n");
-    helperStats(sentry, basicauthenticators);
+    helperStats(sentry, basicauthenticators, "Basic Authenticator Statistics");
 }
 
 CBDATA_TYPE(AuthenticateStateData);
