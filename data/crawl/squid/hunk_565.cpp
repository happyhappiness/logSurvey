     return key;
 }
 
-/**
- * Add the Auth::User structure to the username cache.
- */
-void
-Auth::User::addToNameCache()
-{
-    /* AuthUserHashPointer will self-register with the username cache */
-    new AuthUserHashPointer(this);
-}
-
 /**
  * Dump the username cache statictics for viewing...
  */
 void
-Auth::User::UsernameCacheStats(StoreEntry *output)
+Auth::User::CredentialsCacheStats(StoreEntry *output)
 {
-    AuthUserHashPointer *usernamehash;
-
-    /* overview of username cache */
-    storeAppendPrintf(output, "Cached Usernames: %d of %d\n", proxy_auth_username_cache->count, proxy_auth_username_cache->size);
-    storeAppendPrintf(output, "Next Garbage Collection in %d seconds.\n",
-                      static_cast<int32_t>(last_discard + ::Config.authenticateGCInterval - squid_curtime));
-
-    /* cache dump column titles */
-    storeAppendPrintf(output, "\n%-15s %-9s %-9s %-9s %s\n",
+    auto userlist = authenticateCachedUsersList();
+    storeAppendPrintf(output, "Cached Usernames: %d", static_cast<int32_t>(userlist.size()));
+    storeAppendPrintf(output, "\n%-15s %-9s %-9s %-9s %s\t%s\n",
                       "Type",
                       "State",
                       "Check TTL",
                       "Cache TTL",
-                      "Username");
+                      "Username", "Key");
     storeAppendPrintf(output, "--------------- --------- --------- --------- ------------------------------\n");
-
-    hash_first(proxy_auth_username_cache);
-    while ((usernamehash = ((AuthUserHashPointer *) hash_next(proxy_auth_username_cache)))) {
-        Auth::User::Pointer auth_user = usernamehash->user();
-
-        storeAppendPrintf(output, "%-15s %-9s %-9d %-9d %s\n",
+    for ( auto auth_user : userlist ) {
+        storeAppendPrintf(output, "%-15s %-9s %-9d %-9d %s\t" SQUIDSBUFPH "\n",
                           Auth::Type_str[auth_user->auth_type],
                           CredentialState_str[auth_user->credentials()],
                           auth_user->ttl(),
                           static_cast<int32_t>(auth_user->expiretime - squid_curtime + ::Config.authenticateTTL),
-                          auth_user->username()
+                          auth_user->username(),
+                          SQUIDSBUFPRINT(auth_user->userKey())
                          );
     }
 }
