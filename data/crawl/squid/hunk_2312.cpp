         }
     }
 
-    if (entry && external_acl_grace_expired(def, entry)) {
-        if (oldstate) {
-            debugs(82, 4, "externalAclLookup: in grace period, but already pending lookup ('" << key << "', ch=" << ch << ")");
-            callback(callback_data, entry);
-            return;
-        } else {
-            graceful = 1; // grace expired, (neg)ttl did not, and we must start a new lookup.
-        }
-    }
-
-    // The entry is in the cache, grace_ttl did not expired.
-    if (!graceful && entry && !external_acl_grace_expired(def, entry)) {
-        /* Should not really happen, but why not.. */
-        callback(callback_data, entry);
-        debugs(82, 4, "externalAclLookup: no lookup pending for '" << key << "', and grace not expired");
-        debugs(82, 4, "externalAclLookup: (what tha' hell?)");
+    // A background refresh has no need to piggiback on a pending request:
+    // When the pending request completes, the cache will be refreshed anyway.
+    if (oldstate && inBackground) {
+        debugs(82, 7, HERE << "'" << def->name << "' queue is already being refreshed (ch=" << ch << ")");
         return;
     }
 
-    /* No pending lookup found. Sumbit to helper */
-    state = cbdataAlloc(externalAclState);
-
+    externalAclState *state = cbdataAlloc(externalAclState);
     state->def = cbdataReference(def);
 
     state->key = xstrdup(key);
 
-    if (!graceful) {
-        state->callback = callback;
-        state->callback_data = cbdataReference(callback_data);
+    if (!inBackground) {
+        state->callback = &ExternalACLLookup::LookupDone;
+        state->callback_data = cbdataReference(checklist);
     }
 
     if (oldstate) {
         /* Hook into pending lookup */
         state->queue = oldstate->queue;
         oldstate->queue = state;
     } else {
+        /* No pending lookup found. Sumbit to helper */
+
         /* Check for queue overload */
 
         if (def->theHelper->stats.queue_size >= (int)def->theHelper->childs.n_running) {
-            debugs(82, 1, "externalAclLookup: '" << def->name << "' queue overload (ch=" << ch << ")");
+            debugs(82, 7, HERE << "'" << def->name << "' queue is too long");
+            assert(inBackground); // or the caller should have checked
             cbdataFree(state);
-            callback(callback_data, entry);
             return;
         }
 
         /* Send it off to the helper */
+        MemBuf buf;
         buf.init();
 
         buf.Printf("%s\n", key);
