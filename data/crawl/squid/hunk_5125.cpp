     }
 
     storeAppendPrintf(entry, "\n%s %s realm %s\n%s %s children %d\n%s %s nonce_max_count %d\n%s %s nonce_max_duration %d seconds\n%s %s nonce_garbage_interval %d seconds\n",
-                      name, "digest", config->digestAuthRealm,
-                      name, "digest", config->authenticateChildren,
-                      name, "digest", config->noncemaxuses,
-                      name, "digest", (int) config->noncemaxduration,
-                      name, "digest", (int) config->nonceGCInterval);
-}
-
-void
-authSchemeSetup_digest(authscheme_entry_t * authscheme)
-{
-    assert(!authdigest_initialised);
-    authscheme->Active = authenticateDigestActive;
-    authscheme->configured = authDigestConfigured;
-    authscheme->parse = authDigestParse;
-    authscheme->freeconfig = authDigestFreeConfig;
-    authscheme->dump = authDigestCfgDump;
-    authscheme->init = authDigestInit;
-    authscheme->authAuthenticate = NULL;
-    authscheme->authenticated = NULL;
-    authscheme->authFixHeader = authenticateDigestFixHeader;
-    authscheme->FreeUser = authenticateDigestUserFree;
-#if WAITING_FOR_TE
-
-    authscheme->AddTrailer = authDigestAddTrailer;
-#endif
-
-    authscheme->authStart = authenticateDigestStart;
-    authscheme->authStats = authenticateDigestStats;
-    authscheme->authUserUsername = authenticateDigestUsername;
-    authscheme->getdirection = NULL;
-    authscheme->oncloseconnection = NULL;
-    authscheme->decodeauth = authenticateDigestDecodeAuth;
-    authscheme->donefunc = authDigestDone;
-    authscheme->requestFree = NULL;
-    authscheme->authConnLastHeader = NULL;
+                      name, "digest", digestAuthRealm,
+                      name, "digest", authenticateChildren,
+                      name, "digest", noncemaxuses,
+                      name, "digest", (int) noncemaxduration,
+                      name, "digest", (int) nonceGCInterval);
 }
 
-static int
-authenticateDigestActive(void)
+bool
+AuthDigestConfig::active() const
 {
-    return (authdigest_initialised == 1) ? 1 : 0;
+    return authdigest_initialised == 1;
 }
 
-static int
-authDigestConfigured(void)
+bool
+AuthDigestConfig::configured() const
 {
-    if ((digestConfig != NULL) && (digestConfig->authenticate != NULL) &&
-            (digestConfig->authenticateChildren != 0) &&
-            (digestConfig->digestAuthRealm != NULL) && (digestConfig->noncemaxduration > -1))
-        return 1;
+    if ((authenticate != NULL) &&
+            (authenticateChildren != 0) &&
+            (digestAuthRealm != NULL) && (noncemaxduration > -1))
+        return true;
 
-    return 0;
+    return false;
 }
 
 int
-digest_request_h::authenticated() const
+AuthDigestUserRequest::authenticated() const
 {
     if (credentials() == Ok)
         return 1;
