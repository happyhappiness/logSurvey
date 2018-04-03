 static void
 authenticateDigestStats(StoreEntry * sentry)
 {
-    storeAppendPrintf(sentry, "Digest Authenticator Statistics:\n");
-    helperStats(sentry, digestauthenticators);
+    helperStats(sentry, digestauthenticators, "Digest Authenticator Statistics");
 }
 
 /* NonceUserUnlink: remove the reference to auth_user and unlink the node from the list */
