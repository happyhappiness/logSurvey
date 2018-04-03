	assert(H->alg == PEER_SA_NONE);
    }
    if (/* we used ICP or CD for peer selecton */
	H->alg != PEER_SA_NONE &&
	/* a CD lookup found peers with digests */
	H->cd_lookup != LOOKUP_NONE &&
	/* paranoid: we have a reply pointer */
	(reply = storeEntryReply(http->entry))) {
	const char *x_cache_fld = httpHeaderGetLastStr(&reply->header, HDR_X_CACHE);
	const int real_hit = x_cache_fld && !strncmp(x_cache_fld, "HIT", 3);
	const int guess_hit = H->cd_lookup == LOOKUP_HIT;
	peer *peer = peerFindByName(H->host);

	cacheDigestGuessStatsUpdate(&Counter.cd.guess, real_hit, guess_hit);
	if (peer)
	    cacheDigestGuessStatsUpdate(&peer->digest.stats.guess,
		real_hit, guess_hit);
	else
	    debug(33,1) ("clientUpdateCounters: lost peer: %s!\n", storeUrl(http->entry));
    }
#endif
}
