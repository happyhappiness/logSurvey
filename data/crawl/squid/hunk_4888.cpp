     FwdReplyCodes[tries][status]++;
 }
 
-static void
-fwdStats(StoreEntry * s)
+void
+FwdState::serversFree(FwdServer ** FSVR)
 {
-    int i;
-    int j;
-    storeAppendPrintf(s, "Status");
+    FwdServer *fs;
 
-    for (j = 0; j <= MAX_FWD_STATS_IDX; j++) {
-        storeAppendPrintf(s, "\ttry#%d", j + 1);
+    while ((fs = *FSVR)) {
+        *FSVR = fs->next;
+        fwdServerFree(fs);
     }
+}
 
-    storeAppendPrintf(s, "\n");
+/**** PRIVATE NON-MEMBER FUNCTIONS ********************************************/
 
-    for (i = 0; i <= (int) HTTP_INVALID_HEADER; i++) {
-        if (FwdReplyCodes[0][i] == 0)
-            continue;
+static void
+fwdServerFree(FwdServer * fs)
+{
+    cbdataReferenceDone(fs->_peer);
+    memFree(fs, MEM_FWD_SERVER);
+}
 
-        storeAppendPrintf(s, "%3d", i);
+static struct IN_ADDR
+            aclMapAddr(acl_address * head, ACLChecklist * ch)
+{
+    acl_address *l;
 
-        for (j = 0; j <= MAX_FWD_STATS_IDX; j++) {
-            storeAppendPrintf(s, "\t%d", FwdReplyCodes[j][i]);
-        }
+    struct IN_ADDR addr;
 
-        storeAppendPrintf(s, "\n");
+    for (l = head; l; l = l->next)
+    {
+        if (ch->matchAclListFast(l->aclList))
+            return l->addr;
     }
+
+    addr.s_addr = INADDR_ANY;
+    return addr;
 }
 
-int
-fwdReforwardableStatus(http_status s)
+static int
+aclMapTOS(acl_tos * head, ACLChecklist * ch)
 {
-    switch (s) {
+    acl_tos *l;
 
-    case HTTP_BAD_GATEWAY:
+    for (l = head; l; l = l->next) {
+        if (ch->matchAclListFast(l->aclList))
+            return l->tos;
+    }
 
-    case HTTP_GATEWAY_TIMEOUT:
-        return 1;
+    return 0;
+}
 
-    case HTTP_FORBIDDEN:
+struct IN_ADDR
+            getOutgoingAddr(HttpRequest * request)
+{
+    ACLChecklist ch;
 
-    case HTTP_INTERNAL_SERVER_ERROR:
+    if (request)
+    {
+        ch.src_addr = request->client_addr;
+        ch.my_addr = request->my_addr;
+        ch.my_port = request->my_port;
+        ch.request = requestLink(request);
+    }
 
-    case HTTP_NOT_IMPLEMENTED:
+    return aclMapAddr(Config.accessList.outgoing_address, &ch);
+}
 
-    case HTTP_SERVICE_UNAVAILABLE:
-        return Config.retry.onerror;
+unsigned long
+getOutgoingTOS(HttpRequest * request)
+{
+    ACLChecklist ch;
 
-    default:
-        return 0;
+    if (request) {
+        ch.src_addr = request->client_addr;
+        ch.my_addr = request->my_addr;
+        ch.my_port = request->my_port;
+        ch.request = requestLink(request);
     }
 
-    /* NOTREACHED */
+    return aclMapTOS(Config.accessList.outgoing_tos, &ch);
 }
 
+
+/**** WIP_FWD_LOG *************************************************************/
+
 #if WIP_FWD_LOG
 void
 fwdUninit(void)
