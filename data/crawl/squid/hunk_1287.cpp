 
     if (authenticateProgram)
         wordlistDestroy(&authenticateProgram);
-
-    if (basicAuthRealm)
-        safe_free(basicAuthRealm);
 }
 
-void
-Auth::Basic::Config::dump(StoreEntry * entry, const char *name, Auth::Config * scheme)
+bool
+Auth::Basic::Config::dump(StoreEntry * entry, const char *name, Auth::Config * scheme) const
 {
-    wordlist *list = authenticateProgram;
-    storeAppendPrintf(entry, "%s %s", name, "basic");
-
-    while (list != NULL) {
-        storeAppendPrintf(entry, " %s", list->key);
-        list = list->next;
-    }
+    if (!Auth::Config::dump(entry, name, scheme))
+        return false; // not configured
 
-    storeAppendPrintf(entry, "\n");
-
-    storeAppendPrintf(entry, "%s basic realm %s\n", name, basicAuthRealm);
-    storeAppendPrintf(entry, "%s basic children %d startup=%d idle=%d concurrency=%d\n", name, authenticateChildren.n_max, authenticateChildren.n_startup, authenticateChildren.n_idle, authenticateChildren.concurrency);
     storeAppendPrintf(entry, "%s basic credentialsttl %d seconds\n", name, (int) credentialsTTL);
     storeAppendPrintf(entry, "%s basic casesensitive %s\n", name, casesensitive ? "on" : "off");
-    Auth::Config::dump(entry, name, scheme);
+    storeAppendPrintf(entry, "%s basic utf8 %s\n", name, utf8 ? "on" : "off");
+    return true;
 }
 
 Auth::Basic::Config::Config() :
         credentialsTTL( 2*60*60 ),
         casesensitive(0),
         utf8(0)
 {
-    basicAuthRealm = xstrdup("Squid proxy-caching web server");
-}
-
-Auth::Basic::Config::~Config()
-{
-    safe_free(basicAuthRealm);
+    static const SBuf defaultRealm("Squid proxy-caching web server");
+    realm = defaultRealm;
 }
 
 void
 Auth::Basic::Config::parse(Auth::Config * scheme, int n_configured, char *param_str)
 {
-    if (strcmp(param_str, "program") == 0) {
-        if (authenticateProgram)
-            wordlistDestroy(&authenticateProgram);
-
-        parse_wordlist(&authenticateProgram);
-
-        requirePathnameExists("auth_param basic program", authenticateProgram->key);
-    } else if (strcmp(param_str, "children") == 0) {
-        authenticateChildren.parseConfig();
-    } else if (strcmp(param_str, "realm") == 0) {
-        parse_eol(&basicAuthRealm);
-    } else if (strcmp(param_str, "credentialsttl") == 0) {
+    if (strcmp(param_str, "credentialsttl") == 0) {
         parse_time_t(&credentialsTTL);
     } else if (strcmp(param_str, "casesensitive") == 0) {
         parse_onoff(&casesensitive);
