     storeAppendPrintf(sentry, "\nPer-peer statistics:\n");
     for (peer = getFirstPeer(); peer; peer = getNextPeer(peer)) {
 	cacheDigestGuessStatsReport(&peer->digest.stats.guess, sentry, peer->host);
+	storeAppendPrintf(sentry, "peer.msgs_sent = %d\n",
+	    peer->digest.stats.msgs_sent);
+	storeAppendPrintf(sentry, "peer.msgs_recv = %d\n",
+	    peer->digest.stats.msgs_recv);
+	storeAppendPrintf(sentry, "peer.kbytes_sent = %d\n",
+	    (int) peer->digest.stats.kbytes_sent.kb);
+	storeAppendPrintf(sentry, "peer.kbytes_recv = %d\n",
+	    (int) peer->digest.stats.kbytes_recv.kb);
+	storeAppendPrintf(sentry, "peer.local_memory = %d\n",
+	    peer->digest.cd ? peer->digest.cd->mask_size/1024 : 0);
 	storeAppendPrintf(sentry, "\n");
     }
 
