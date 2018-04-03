 
 void
 server_list(StoreEntry * sentry)
+{
+    dump_peers(sentry, Config.peers);
+}
+
+void
+dump_peers(StoreEntry * sentry, peer * peers)
 {
     peer *e = NULL;
     struct _domain_ping *d = NULL;
     icp_opcode op;
-
     storeAppendPrintf(sentry, open_bracket);
-
-    if (getFirstPeer() == NULL)
+    if (peers == NULL)
 	storeAppendPrintf(sentry, "{There are no neighbors installed.}\n");
-    for (e = getFirstPeer(); e; e = getNextPeer(e)) {
-	if (e->host == NULL)
-	    fatal_dump("Found an peer without a hostname!");
+    for (e = peers; e; e = e->next) {
+	assert(e->host != NULL);
 	storeAppendPrintf(sentry, "\n{%-11.11s: %s/%d/%d}\n",
 	    neighborTypeStr(e),
 	    e->host,
