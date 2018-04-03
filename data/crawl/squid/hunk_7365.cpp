 
 void
 peerSelect(request_t * request,
-	StoreEntry *entry,
-	PSC callback,
-	PSC fail_callback,
-	void *callback_data)
+    StoreEntry * entry,
+    PSC callback,
+    PSC fail_callback,
+    void *callback_data)
 {
-    psctrl_t *ctrl = xcalloc(1, sizeof(psctrl_t));
-    ctrl->request = requestLink(request);
-    ctrl->entry = entry;
-    ctrl->callback = callback;
-    ctrl->fail_callback = fail_callback;
-    ctrl->callback_data = callback_data;
-    peerSelectFoo(ctrl);
+    ps_state *psstate = xcalloc(1, sizeof(ps_state));
+    psstate->request = requestLink(request);
+    psstate->entry = entry;
+    psstate->callback = callback;
+    psstate->fail_callback = fail_callback;
+    psstate->callback_data = callback_data;
+    psstate->icp.start = current_time;
+    peerSelectFoo(psstate);
 }
 
 static void
 peerCheckNeverDirectDone(int answer, void *data)
 {
-    psctrl_t *ctrl = data;
+    ps_state *psstate = data;
     debug(44, 3, "peerCheckNeverDirectDone: %d\n", answer);
-    ctrl->never_direct = answer ? 1 : -1;
-    peerSelectFoo(ctrl);
+    psstate->never_direct = answer ? 1 : -1;
+    peerSelectFoo(psstate);
 }
 
 static void
 peerCheckAlwaysDirectDone(int answer, void *data)
 {
-    psctrl_t *ctrl = data;
+    ps_state *psstate = data;
     debug(44, 3, "peerCheckAlwaysDirectDone: %d\n", answer);
-    ctrl->always_direct = answer ? 1 : -1;
-    peerSelectFoo(ctrl);
+    psstate->always_direct = answer ? 1 : -1;
+    peerSelectFoo(psstate);
 }
 
 static void
-peerSelectCallback(psctrl_t * ctrl, peer * p)
+peerSelectCallback(ps_state * psstate, peer * p)
 {
-    if (!ctrl->ping.timeout)
-	eventDelete(peerPingTimeout, ctrl);
-    ctrl->callback(p, ctrl->callback_data);
-    requestUnlink(ctrl->request);
-    xfree(ctrl);
+    StoreEntry *entry = psstate->entry;
+    if (entry) {
+	if (entry->ping_status == PING_WAITING)
+	    eventDelete(peerPingTimeout, psstate);
+	entry->ping_status = PING_DONE;
+    }
+    psstate->callback(p, psstate->callback_data);
+    requestUnlink(psstate->request);
+    xfree(psstate);
 }
 
 static void
-peerSelectCallbackFail(psctrl_t * ctrl)
+peerSelectCallbackFail(ps_state * psstate)
 {
-    request_t *request = ctrl->request;
-    char *url = ctrl->entry ? ctrl->entry->url : urlCanonical(request, NULL);
+    request_t *request = psstate->request;
+    char *url = psstate->entry ? psstate->entry->url : urlCanonical(request, NULL);
     debug(44, 1, "Failed to select source for '%s'\n", url);
-    debug(44, 1, "  always_direct = %d\n", ctrl->always_direct);
-    debug(44, 1, "   never_direct = %d\n", ctrl->never_direct);
-    debug(44, 1, "        timeout = %d\n", ctrl->ping.timeout);
-    ctrl->fail_callback(NULL, ctrl->callback_data);
-    requestUnlink(ctrl->request);
-    xfree(ctrl);
+    debug(44, 1, "  always_direct = %d\n", psstate->always_direct);
+    debug(44, 1, "   never_direct = %d\n", psstate->never_direct);
+    debug(44, 1, "        timeout = %d\n", psstate->icp.timeout);
+    psstate->fail_callback(NULL, psstate->callback_data);
+    requestUnlink(psstate->request);
+    xfree(psstate);
 }
 
 static void
-peerSelectFoo(psctrl_t * ctrl)
+peerSelectFoo(ps_state * psstate)
 {
     peer *p;
     hier_code code;
-    StoreEntry *entry = ctrl->entry;
-    request_t *request = ctrl->request;
+    StoreEntry *entry = psstate->entry;
+    request_t *request = psstate->request;
     int direct;
-    debug(44, 3, "peerSelect: '%s'\n", entry->url);
-    if (ctrl->never_direct == 0) {
+    debug(44, 3, "peerSelect: '%s %s'\n",
+	RequestMethodStr[request->method],
+	request->host);
+    if (psstate->never_direct == 0) {
 	aclNBCheck(Config.accessList.NeverDirect,
 	    request,
 	    request->client_addr,
 	    NULL,		/* user agent */
 	    NULL,		/* ident */
 	    peerCheckNeverDirectDone,
-	    ctrl);
+	    psstate);
 	return;
-    } else if (ctrl->never_direct > 0) {
+    } else if (psstate->never_direct > 0) {
 	direct = DIRECT_NO;
-    } else if (ctrl->always_direct == 0) {
+    } else if (psstate->always_direct == 0) {
 	aclNBCheck(Config.accessList.AlwaysDirect,
 	    request,
 	    request->client_addr,
 	    NULL,		/* user agent */
 	    NULL,		/* ident */
 	    peerCheckAlwaysDirectDone,
-	    ctrl);
+	    psstate);
 	return;
-    } else if (ctrl->always_direct > 0) {
+    } else if (psstate->always_direct > 0) {
 	direct = DIRECT_YES;
     } else {
 	direct = DIRECT_MAYBE;
     }
     debug(44, 3, "peerSelect: direct = %d\n", direct);
     if (direct == DIRECT_YES) {
 	debug(44, 3, "peerSelect: HIER_DIRECT\n");
-	hierarchyNote(request, HIER_DIRECT, ctrl->ping.timeout, request->host);
-	peerSelectCallback(ctrl, NULL);
+	hierarchyNote(request, HIER_DIRECT, &psstate->icp, request->host);
+	peerSelectCallback(psstate, NULL);
 	return;
     }
     if (peerSelectIcpPing(request, direct, entry)) {
 	if (entry->ping_status != PING_NONE)
-		fatal_dump("peerSelectFoo: bad ping_status");
+	    fatal_dump("peerSelectFoo: bad ping_status");
 	debug(44, 3, "peerSelect: Doing ICP pings\n");
-	ctrl->ping.n_sent = neighborsUdpPing(request,
-		entry,
-		&ctrl->ping.n_replies_expected);
-	if (ctrl->ping.n_sent > 0) {
+	psstate->icp.n_sent = neighborsUdpPing(request,
+	    entry,
+	    peerHandleIcpReply,
+	    psstate,
+	    &psstate->icp.n_replies_expected);
+	if (psstate->icp.n_sent > 0) {
 	    entry->ping_status = PING_WAITING;
 	    eventAdd("peerPingTimeout",
 		peerPingTimeout,
-		ctrl,
+		psstate,
 		Config.neighborTimeout);
-	    ctrl->ping.start = current_time;
 	    return;
 	}
 	debug_trap("peerSelect: neighborsUdpPing returned 0");
     }
-    if ((p = ctrl->ping.best_parent)) {
+    if ((p = psstate->best_parent)) {
 	code = HIER_BEST_PARENT_MISS;
 	debug(44, 3, "peerSelect: %s/%s\n", hier_strings[code], p->host);
-	hierarchyNote(request, code, ctrl->ping.timeout, p->host);
-	peerSelectCallback(ctrl, p);
+	hierarchyNote(request, code, &psstate->icp, p->host);
+	peerSelectCallback(psstate, p);
     } else if (direct != DIRECT_NO) {
 	code = HIER_DIRECT;
 	debug(44, 3, "peerSelect: %s/%s\n", hier_strings[code], request->host);
-	hierarchyNote(request, code, ctrl->ping.timeout, request->host);
-	peerSelectCallback(ctrl, NULL);
+	hierarchyNote(request, code, &psstate->icp, request->host);
+	peerSelectCallback(psstate, NULL);
     } else if ((p = peerGetSomeParent(request, &code))) {
 	debug(44, 3, "peerSelect: %s/%s\n", hier_strings[code], p->host);
-	hierarchyNote(request, code, ctrl->ping.timeout, p->host);
-	peerSelectCallback(ctrl, p);
+	hierarchyNote(request, code, &psstate->icp, p->host);
+	peerSelectCallback(psstate, p);
     } else {
 	code = HIER_NO_DIRECT_FAIL;
-	hierarchyNote(request, code, ctrl->ping.timeout, NULL);
-	peerSelectCallbackFail(ctrl);
+	hierarchyNote(request, code, &psstate->icp, NULL);
+	peerSelectCallbackFail(psstate);
     }
 }
 
 void
 peerPingTimeout(void *data)
 {
-    psctrl_t *ctrl = data;
-    StoreEntry *entry = ctrl->entry;
+    ps_state *psstate = data;
+    StoreEntry *entry = psstate->entry;
     debug(44, 3, "peerPingTimeout: '%s'\n", entry->url);
     entry->ping_status = PING_TIMEOUT;
     PeerStats.timeouts++;
-    ctrl->ping.timeout = 1;
-    peerSelectFoo(ctrl);
-}
-
-void
-peerPingComplete(void *data)
-{
-    psctrl_t *ctrl = data;
-    StoreEntry *entry = ctrl->entry;
-    debug(44, 3, "peerPingComplete: '%s'\n", entry->url);
-    entry->ping_status = PING_DONE;
-    peerSelectFoo(ctrl);
+    psstate->icp.timeout = 1;
+    peerSelectFoo(psstate);
 }
 
 void
