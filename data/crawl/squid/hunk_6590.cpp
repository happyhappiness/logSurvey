 	    e->host,
 	    e->http_port,
 	    e->icp_port);
+	storeAppendPrintf(sentry, "Flags      :");
+	dump_peer_options(sentry, e);
 	for (i = 0; i < e->n_addresses; i++) {
 	    storeAppendPrintf(sentry, "Address[%d] : %s\n", i,
 		inet_ntoa(e->addresses[i]));
