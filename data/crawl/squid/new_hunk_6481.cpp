	    cacheDigestGuessStatsUpdate(&peer->digest.stats.guess,
		real_hit, guess_hit);
	else {
	    /* temporary paranoid debug */
	    static int max_count = 200;
	    if (max_count > 0) {
		debug(33,1) ("clientUpdateCounters: lost peer %s for %s! (%d)\n", 
		    http->request->hier.cd_host, http->request->host, max_count);
		max_count--;
	    }
	}
    }
#endif