 	debug(15, 0, "Check 'icp_port' in your config file\n");
 	fatal_dump(NULL);
     }
+    if (entry->swap_status != NO_SWAP)
+        fatal_dump("neighborsUdpPing: bad swap_status");
     for (i = 0, e = friends.first_ping; i++ < friends.n; e = e->next) {
-	if (entry->swap_status != NO_SWAP)
-	    fatal_dump("neighborsUdpPing: bad swap_status");
-	if (e == (edge *) NULL)
+	if (e == NULL)
 	    e = friends.edges_head;
 	debug(15, 5, "neighborsUdpPing: Edge %s\n", e->host);
 
