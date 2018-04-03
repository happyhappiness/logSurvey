    /* per-peer */
    storeAppendPrintf(sentry, "\nPer-peer statistics:\n");
    for (peer = getFirstPeer(); peer; peer = getNextPeer(peer)) {
	if (peer->digest)
	    peerDigestStatsReport(peer->digest, sentry);
	else
	    storeAppendPrintf(sentry, "\nNo peer digest from %s\n", peer->host);
	storeAppendPrintf(sentry, "\n");
    }

