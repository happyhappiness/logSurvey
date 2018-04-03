	    cacheDigestGuessStatsUpdate(&peer->digest.stats.guess,
		real_hit, guess_hit);
	else {
	    debug(33,2) ("clientUpdateCounters: lost peer %s for %s!\n", 
		http->request->hier.cd_host, http->request->host);
	    fatal_dump("lost peer");
	}
    }
#endif