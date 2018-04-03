 
     if (Config.onoff.redirector_bypass)
         storeAppendPrintf(sentry, "\nNumber of requests bypassed "
-                          "because all redirectors were busy: %d\n", n_bypassed);
+                          "because all redirectors were busy: %d\n", redirectorBypassed);
 }
 
-/**** PUBLIC FUNCTIONS ****/
+static void
+storeIdStats(StoreEntry * sentry)
+{
+    if (storeIds == NULL) {
+        storeAppendPrintf(sentry, "No StoreId helpers defined\n");
+        return;
+    }
 
-void
-redirectStart(ClientHttpRequest * http, HLPCB * handler, void *data)
+    helperStats(sentry, storeIds, "StoreId helper Statistics");
+
+    if (Config.onoff.store_id_bypass)
+        storeAppendPrintf(sentry, "\nNumber of requests bypassed "
+                          "because all StoreId helpers were busy: %d\n", storeIdBypassed);
+}
+
+static void
+constructHelperQuery(const char *name, struct helper *hlp, HLPCB *replyHandler, ClientHttpRequest * http, HLPCB *handler, void *data)
 {
     ConnStateData * conn = http->getConn();
-    redirectStateData *r = NULL;
     const char *fqdn;
     char buf[MAX_REDIRECTOR_REQUEST_STRLEN];
     int sz;
     http_status status;
     char claddr[MAX_IPSTRLEN];
     char myaddr[MAX_IPSTRLEN];
-    assert(http);
-    assert(handler);
-    debugs(61, 5, "redirectStart: '" << http->uri << "'");
 
-    if (Config.onoff.redirector_bypass && redirectors->stats.queue_size) {
-        /* Skip redirector if there is one request queued */
-        ++n_bypassed;
-        HelperReply bypassReply;
-        bypassReply.result = HelperReply::Okay;
-        bypassReply.notes.add("message","URL rewrite/redirect queue too long. Bypassed.");
-        handler(data, bypassReply);
-        return;
-    }
-
-    r = cbdataAlloc(redirectStateData);
+    /** TODO: create a standalone method to initialize
+     * the cbdata\redirectStateData for all the helpers.
+     */
+    redirectStateData *r = cbdataAlloc(redirectStateData);
     r->orig_url = xstrdup(http->uri);
     if (conn != NULL)
         r->client_addr = conn->log_addr;
