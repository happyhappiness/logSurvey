 static void
 server_list(const cacheinfo * obj, StoreEntry * sentry)
 {
-    edge *e = NULL;
+    peer *e = NULL;
     struct _domain_ping *d = NULL;
     icp_opcode op;
 
     storeAppendPrintf(sentry, open_bracket);
 
-    if (getFirstEdge() == NULL)
+    if (getFirstPeer() == NULL)
 	storeAppendPrintf(sentry, "{There are no neighbors installed.}\n");
-    for (e = getFirstEdge(); e; e = getNextEdge(e)) {
+    for (e = getFirstPeer(); e; e = getNextPeer(e)) {
 	if (e->host == NULL)
-	    fatal_dump("Found an edge without a hostname!");
+	    fatal_dump("Found an peer without a hostname!");
 	storeAppendPrintf(sentry, "\n{%-11.11s: %s/%d/%d}\n",
-	    e->type == EDGE_PARENT ? "Parent" : "Sibling",
+	    e->type == PEER_PARENT ? "Parent" : "Sibling",
 	    e->host,
 	    e->http_port,
 	    e->icp_port);
