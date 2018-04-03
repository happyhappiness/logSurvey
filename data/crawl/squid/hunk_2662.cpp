  * Dump the username cache statictics for viewing...
  */
 void
-AuthUser::UsernameCacheStats(StoreEntry *output)
+Auth::User::UsernameCacheStats(StoreEntry *output)
 {
     AuthUserHashPointer *usernamehash;
 
     /* overview of username cache */
     storeAppendPrintf(output, "Cached Usernames: %d of %d\n", proxy_auth_username_cache->count, proxy_auth_username_cache->size);
-    storeAppendPrintf(output, "Next Garbage Collection in %d seconds.\n", static_cast<int32_t>(last_discard + Config.authenticateGCInterval - squid_curtime));
+    storeAppendPrintf(output, "Next Garbage Collection in %d seconds.\n",
+                      static_cast<int32_t>(last_discard + ::Config.authenticateGCInterval - squid_curtime));
 
     /* cache dump column titles */
     storeAppendPrintf(output, "\n%-15s %-9s %-9s %-9s %s\n",
