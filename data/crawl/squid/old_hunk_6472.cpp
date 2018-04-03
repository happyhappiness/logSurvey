    storeAppendPrintf(sentry, "\nPer-peer statistics:\n");
    for (peer = getFirstPeer(); peer; peer = getNextPeer(peer)) {
	cacheDigestGuessStatsReport(&peer->digest.stats.guess, sentry, peer->host);
	storeAppendPrintf(sentry, "\n");
    }

