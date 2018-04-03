 CossSwapDir::statfs(StoreEntry & sentry) const
 {
     storeAppendPrintf(&sentry, "\n");
-    storeAppendPrintf(&sentry, "Maximum Size: %d KB\n", max_size);
-    storeAppendPrintf(&sentry, "Current Size: %d KB\n", cur_size);
+    storeAppendPrintf(&sentry, "Maximum Size: %Zu KB\n", max_size);
+    storeAppendPrintf(&sentry, "Current Size: %Zu KB\n", cur_size);
     storeAppendPrintf(&sentry, "Percent Used: %0.2f%%\n",
-                      100.0 * cur_size / max_size);
+                      (100.0 * (double)cur_size / (double)max_size) );
     storeAppendPrintf(&sentry, "Number of object collisions: %d\n", (int) numcollisions);
 #if 0
     /* is this applicable? I Hope not .. */
