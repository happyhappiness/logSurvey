     debugs(29, 2, "authenticateAuthUserAddIp: user '" << username() << "' has been seen at a new IP address (" << ipaddr << ")");
 }
 
-
+/**
+ * Add the AuthUser structure to the username cache.
+ */
 void
-AuthUser::lock()
+AuthUser::addToNameCache()
 {
-    debugs(29, 9, "authenticateAuthUserLock auth_user '" << this << "'.");
-    assert(this != NULL);
-    references++;
-    debugs(29, 9, "authenticateAuthUserLock auth_user '" << this << "' now at '" << references << "'.");
+    /* AuthUserHashPointer will self-register with the username cache */
+    new AuthUserHashPointer(this);
 }
 
+/**
+ * Dump the username cache statictics for viewing...
+ */
 void
-AuthUser::unlock()
+AuthUser::UsernameCacheStats(StoreEntry *output)
 {
-    debugs(29, 9, "authenticateAuthUserUnlock auth_user '" << this << "'.");
-    assert(this != NULL);
+    AuthUserHashPointer *usernamehash;
 
-    if (references > 0) {
-        references--;
-    } else {
-        debugs(29, 1, "Attempt to lower Auth User " << this << " refcount below 0!");
-    }
+    /* overview of username cache */
+    storeAppendPrintf(output, "Cached Usernames: %d of %d\n", proxy_auth_username_cache->count, proxy_auth_username_cache->size);
+    storeAppendPrintf(output, "Next Garbage Collection in %d seconds.\n", static_cast<int32_t>(last_discard + Config.authenticateGCInterval - squid_curtime));
 
-    debugs(29, 9, "authenticateAuthUserUnlock auth_user '" << this << "' now at '" << references << "'.");
+    /* cache dump column titles */
+    storeAppendPrintf(output, "\n%-15s %-9s %-9s %-9s %s\n",
+                      "Type",
+                      "State",
+                      "Check TTL",
+                      "Cache TTL",
+                      "Username");
+    storeAppendPrintf(output, "--------------- --------- --------- --------- ------------------------------\n");
 
-    if (references == 0)
-        delete this;
-}
-
-/* addToNameCache: add a auth_user structure to the username cache */
-void
-AuthUser::addToNameCache()
-{
-    usernamehash = new AuthUserHashPointer (this);
+    hash_first(proxy_auth_username_cache);
+    while ((usernamehash = ((AuthUserHashPointer *) hash_next(proxy_auth_username_cache)))) {
+        AuthUser::Pointer auth_user = usernamehash->user();
+
+        storeAppendPrintf(output, "%-15s %-9s %-9d %-9d %s\n",
+                          AuthType_str[auth_user->auth_type],
+                          CredentialsState_str[auth_user->credentials()],
+                          auth_user->ttl(),
+                          static_cast<int32_t>(auth_user->expiretime - squid_curtime + Config.authenticateTTL),
+                          auth_user->username()
+                          );
+    }
 }
