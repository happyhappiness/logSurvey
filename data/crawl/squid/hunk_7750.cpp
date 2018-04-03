 {
     edge *e = NULL;
     dom_list *d = NULL;
+    icp_opcode op;
 
-    storeAppendPrintf(sentry, "{\n");
+    storeAppendPrintf(sentry, open_bracket);
 
-    if (getFirstEdge() == (edge *) NULL) {
+    if (getFirstEdge() == NULL)
 	storeAppendPrintf(sentry, "{There are no neighbors installed.}\n");
-    }
     for (e = getFirstEdge(); e; e = getNextEdge(e)) {
 	if (e->host == NULL)
 	    fatal_dump("Found an edge without a hostname!");
-	storeAppendPrintf(sentry, "\n{Hostname:    %s}\n", e->host);
-	storeAppendPrintf(sentry, "{Edge type:   %s}\n",
-	    e->type == EDGE_PARENT ? "parent" : "neighbor");
-	storeAppendPrintf(sentry, "{Status:      %s}\n",
+	storeAppendPrintf(sentry, "\n{%-11.11s: %s/%d/%d}\n",
+	    e->type == EDGE_PARENT ? "Parent" : "Sibling",
+	    e->host,
+	    e->http_port,
+	    e->icp_port);
+	storeAppendPrintf(sentry, "{Status     : %s}\n",
 	    e->neighbor_up ? "Up" : "Down");
-	storeAppendPrintf(sentry, "{UDP PORT:    %d}\n", e->udp_port);
-	storeAppendPrintf(sentry, "{ASCII PORT:  %d}\n", e->ascii_port);
-	storeAppendPrintf(sentry, "{ACK DEFICIT: %d}\n", e->ack_deficit);
-	storeAppendPrintf(sentry, "{PINGS SENT:  %d}\n", e->num_pings);
-	storeAppendPrintf(sentry, "{PINGS ACKED: %d}\n", e->pings_acked);
+	storeAppendPrintf(sentry, "{AVG RTT    : %d msec}\n", e->stats.rtt);
+	storeAppendPrintf(sentry, "{ACK DEFICIT: %8d}\n", e->stats.ack_deficit);
+	storeAppendPrintf(sentry, "{PINGS SENT : %8d}\n", e->stats.pings_sent);
+	storeAppendPrintf(sentry, "{PINGS ACKED: %8d %3d%%}\n",
+	    e->stats.pings_acked,
+	    percent(e->stats.pings_acked, e->stats.pings_sent));
+	storeAppendPrintf(sentry, "{Histogram of PINGS ACKED:}\n");
+	for (op = ICP_OP_INVALID; op < ICP_OP_END; op++) {
+	    if (e->stats.counts[op] == 0)
+		continue;
+	    storeAppendPrintf(sentry, "{%-10.10s : %8d %3d%%}\n",
+		IcpOpcodeStr[op],
+		e->stats.counts[op],
+		percent(e->stats.counts[op], e->stats.pings_acked));
+	}
+	storeAppendPrintf(sentry, "{FETCHES    : %8d %3d%%}\n",
+	    e->stats.fetches,
+	    percent(e->stats.fetches, e->stats.pings_acked));
+
 	if (e->last_fail_time) {
 	    storeAppendPrintf(sentry, "{Last failed connect() at: %s}\n",
 		mkhttpdlogtime(&(e->last_fail_time)));
