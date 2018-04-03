     } else {
 	direct = DIRECT_MAYBE;
     }
-    debug(44, 3, "peerSelect: direct = %d\n", direct);
+    debug(44, 3) ("peerSelect: direct = %d\n", direct);
     if (direct == DIRECT_YES) {
-	debug(44, 3, "peerSelect: DIRECT\n");
+	debug(44, 3) ("peerSelect: DIRECT\n");
 	hierarchyNote(request, DIRECT, &psstate->icp, request->host);
 	peerSelectCallback(psstate, NULL);
 	return;
     }
     if (peerSelectIcpPing(request, direct, entry)) {
 	if (entry->ping_status != PING_NONE)
 	    fatal_dump("peerSelectFoo: bad ping_status");
-	debug(44, 3, "peerSelect: Doing ICP pings\n");
+	debug(44, 3) ("peerSelect: Doing ICP pings\n");
 	psstate->icp.n_sent = neighborsUdpPing(request,
 	    entry,
 	    peerHandleIcpReply,
