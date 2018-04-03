         storeDirSwapLog(this, SWAP_LOG_ADD);
 }
 
+/// Calculates correct public key for feeding forcePublicKey().
+/// Assumes adjustVary() has been called for this entry already.
+const cache_key *
+StoreEntry::calcPublicKey(const KeyScope keyScope)
+{
+    assert(mem_obj);
+    return mem_obj->request ?  storeKeyPublicByRequest(mem_obj->request, keyScope) :
+           storeKeyPublic(mem_obj->storeId(), mem_obj->method, keyScope);
+}
+
+/// Updates mem_obj->request->vary_headers to reflect the current Vary.
+/// The vary_headers field is used to calculate the Vary marker key.
+/// Releases the old Vary marker with an outdated key (if any).
+void
+StoreEntry::adjustVary()
+{
+    assert(mem_obj);
+
+    if (!mem_obj->request)
+        return;
+
+    HttpRequest *request = mem_obj->request;
+
+    if (mem_obj->vary_headers.isEmpty()) {
+        /* First handle the case where the object no longer varies */
+        request->vary_headers.clear();
+    } else {
+        if (!request->vary_headers.isEmpty() && request->vary_headers.cmp(mem_obj->vary_headers) != 0) {
+            /* Oops.. the variance has changed. Kill the base object
+             * to record the new variance key
+             */
+            request->vary_headers.clear();       /* free old "bad" variance key */
+            if (StoreEntry *pe = storeGetPublic(mem_obj->storeId(), mem_obj->method))
+                pe->release();
+        }
+
+        /* Make sure the request knows the variance status */
+        if (request->vary_headers.isEmpty())
+            request->vary_headers = httpMakeVaryMark(request, mem_obj->getReply());
+    }
+
+    // TODO: storeGetPublic() calls below may create unlocked entries.
+    // We should add/use storeHas() API or lock/unlock those entries.
+    if (!mem_obj->vary_headers.isEmpty() && !storeGetPublic(mem_obj->storeId(), mem_obj->method)) {
+        /* Create "vary" base object */
+        String vary;
+        StoreEntry *pe = storeCreateEntry(mem_obj->storeId(), mem_obj->logUri(), request->flags, request->method);
+        /* We are allowed to do this typecast */
+        HttpReply *rep = new HttpReply;
+        rep->setHeaders(Http::scOkay, "Internal marker object", "x-squid-internal/vary", -1, -1, squid_curtime + 100000);
+        vary = mem_obj->getReply()->header.getList(Http::HdrType::VARY);
+
+        if (vary.size()) {
+            /* Again, we own this structure layout */
+            rep->header.putStr(Http::HdrType::VARY, vary.termedBuf());
+            vary.clean();
+        }
+
+#if X_ACCELERATOR_VARY
+        vary = mem_obj->getReply()->header.getList(Http::HdrType::HDR_X_ACCELERATOR_VARY);
+
+        if (vary.size() > 0) {
+            /* Again, we own this structure layout */
+            rep->header.putStr(Http::HdrType::HDR_X_ACCELERATOR_VARY, vary.termedBuf());
+            vary.clean();
+        }
+
+#endif
+        pe->replaceHttpReply(rep, false); // no write until key is public
+
+        pe->timestampsSet();
+
+        pe->makePublic();
+
+        pe->startWriting(); // after makePublic()
+
+        pe->complete();
+
+        pe->unlock("StoreEntry::forcePublicKey+Vary");
+    }
+}
+
 StoreEntry *
 storeCreatePureEntry(const char *url, const char *log_url, const RequestFlags &flags, const HttpRequestMethod& method)
 {
