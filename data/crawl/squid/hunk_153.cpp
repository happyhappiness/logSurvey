 
     assert(!EBIT_TEST(flags, RELEASE_REQUEST));
 
-    if (mem_obj->request) {
-        HttpRequest *request = mem_obj->request;
-
-        if (mem_obj->vary_headers.isEmpty()) {
-            /* First handle the case where the object no longer varies */
-            request->vary_headers.clear();
-        } else {
-            if (!request->vary_headers.isEmpty() && request->vary_headers.cmp(mem_obj->vary_headers) != 0) {
-                /* Oops.. the variance has changed. Kill the base object
-                 * to record the new variance key
-                 */
-                request->vary_headers.clear();       /* free old "bad" variance key */
-                if (StoreEntry *pe = storeGetPublic(mem_obj->storeId(), mem_obj->method))
-                    pe->release();
-            }
-
-            /* Make sure the request knows the variance status */
-            if (request->vary_headers.isEmpty())
-                request->vary_headers = httpMakeVaryMark(request, mem_obj->getReply());
-        }
-
-        // TODO: storeGetPublic() calls below may create unlocked entries.
-        // We should add/use storeHas() API or lock/unlock those entries.
-        if (!mem_obj->vary_headers.isEmpty() && !storeGetPublic(mem_obj->storeId(), mem_obj->method)) {
-            /* Create "vary" base object */
-            String vary;
-            StoreEntry *pe = storeCreateEntry(mem_obj->storeId(), mem_obj->logUri(), request->flags, request->method);
-            /* We are allowed to do this typecast */
-            HttpReply *rep = new HttpReply;
-            rep->setHeaders(Http::scOkay, "Internal marker object", "x-squid-internal/vary", -1, -1, squid_curtime + 100000);
-            vary = mem_obj->getReply()->header.getList(Http::HdrType::VARY);
-
-            if (vary.size()) {
-                /* Again, we own this structure layout */
-                rep->header.putStr(Http::HdrType::VARY, vary.termedBuf());
-                vary.clean();
-            }
-
-#if X_ACCELERATOR_VARY
-            vary = mem_obj->getReply()->header.getList(Http::HdrType::HDR_X_ACCELERATOR_VARY);
-
-            if (vary.size() > 0) {
-                /* Again, we own this structure layout */
-                rep->header.putStr(Http::HdrType::HDR_X_ACCELERATOR_VARY, vary.termedBuf());
-                vary.clean();
-            }
-
-#endif
-            pe->replaceHttpReply(rep, false); // no write until key is public
-
-            pe->timestampsSet();
-
-            pe->makePublic();
+    adjustVary();
+    forcePublicKey(calcPublicKey(scope));
+}
 
-            pe->startWriting(); // after makePublic()
+void
+StoreEntry::clearPublicKeyScope()
+{
+    if (!key || EBIT_TEST(flags, KEY_PRIVATE))
+        return; // probably the old public key was deleted or made private
 
-            pe->complete();
+    // TODO: adjustVary() when collapsed revalidation supports that
 
-            pe->unlock("StoreEntry::setPublicKey+Vary");
-        }
+    const cache_key *newKey = calcPublicKey(ksDefault);
+    if (!storeKeyHashCmp(key, newKey))
+        return; // probably another collapsed revalidation beat us to this change
 
-        newkey = storeKeyPublicByRequest(mem_obj->request);
-    } else
-        newkey = storeKeyPublic(mem_obj->storeId(), mem_obj->method);
+    forcePublicKey(newKey);
+}
 
+/// Unconditionally sets public key for this store entry.
+/// Releases the old entry with the same public key (if any).
+void
+StoreEntry::forcePublicKey(const cache_key *newkey)
+{
     if (StoreEntry *e2 = (StoreEntry *)hash_lookup(store_table, newkey)) {
+        assert(e2 != this);
         debugs(20, 3, "Making old " << *e2 << " private.");
         e2->setPrivateKey();
         e2->release();
-
-        if (mem_obj->request)
-            newkey = storeKeyPublicByRequest(mem_obj->request);
-        else
-            newkey = storeKeyPublic(mem_obj->storeId(), mem_obj->method);
     }
 
     if (key)
