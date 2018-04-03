 
     storeAppendPrintf(entry, "\n");
 
-    storeAppendPrintf(entry, "%s basic realm %s\n", name, config->basicAuthRealm);
-    storeAppendPrintf(entry, "%s basic children %d\n", name, config->authenticateChildren);
-    storeAppendPrintf(entry, "%s basic concurrency %d\n", name, config->authenticateConcurrency);
-    storeAppendPrintf(entry, "%s basic credentialsttl %d seconds\n", name, (int) config->credentialsTTL);
+    storeAppendPrintf(entry, "%s basic realm %s\n", name, basicAuthRealm);
+    storeAppendPrintf(entry, "%s basic children %d\n", name, authenticateChildren);
+    storeAppendPrintf(entry, "%s basic concurrency %d\n", name, authenticateConcurrency);
+    storeAppendPrintf(entry, "%s basic credentialsttl %d seconds\n", name, (int) credentialsTTL);
 
 }
 
-static void
-authBasicParse(authScheme * scheme, int n_configured, char *param_str)
-{
-    if (scheme->scheme_data == NULL) {
-        assert(basicConfig == NULL);
-        /* this is the first param to be found */
-        scheme->scheme_data = xmalloc(sizeof(auth_basic_config));
-        memset(scheme->scheme_data, 0, sizeof(auth_basic_config));
-        basicConfig = static_cast<auth_basic_config *>(scheme->scheme_data);
-        basicConfig->authenticateChildren = 5;
-        basicConfig->credentialsTTL = 2 * 60 * 60;	/* two hours */
-    }
-
-    basicConfig =  static_cast<auth_basic_config *>(scheme->scheme_data);
+AuthBasicConfig::AuthBasicConfig()
+{
+    /* TODO: move into initialisation list */
+    authenticateChildren = 5;
+    credentialsTTL = 2 * 60 * 60;	/* two hours */
+}
 
+void
+AuthBasicConfig::parse(AuthConfig * scheme, int n_configured, char *param_str)
+{
     if (strcasecmp(param_str, "program") == 0) {
-        if (basicConfig->authenticate)
-            wordlistDestroy(&basicConfig->authenticate);
+        if (authenticate)
+            wordlistDestroy(&authenticate);
 
-        parse_wordlist(&basicConfig->authenticate);
+        parse_wordlist(&authenticate);
 
-        requirePathnameExists("authparam basic program", basicConfig->authenticate->key);
+        requirePathnameExists("authparam basic program", authenticate->key);
     } else if (strcasecmp(param_str, "children") == 0) {
-        parse_int(&basicConfig->authenticateChildren);
+        parse_int(&authenticateChildren);
     } else if (strcasecmp(param_str, "concurrency") == 0) {
-        parse_int(&basicConfig->authenticateConcurrency);
+        parse_int(&authenticateConcurrency);
     } else if (strcasecmp(param_str, "realm") == 0) {
-        parse_eol(&basicConfig->basicAuthRealm);
+        parse_eol(&basicAuthRealm);
     } else if (strcasecmp(param_str, "credentialsttl") == 0) {
-        parse_time_t(&basicConfig->credentialsTTL);
+        parse_time_t(&credentialsTTL);
     } else {
         debug(28, 0) ("unrecognised basic auth scheme parameter '%s'\n", param_str);
     }
