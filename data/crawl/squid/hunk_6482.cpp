 	assert(H->alg == PEER_SA_NONE);
     }
     if (/* we used ICP or CD for peer selecton */
-	H->alg != PEER_SA_NONE &&
-	/* a CD lookup found peers with digests */
-	H->cd_lookup != LOOKUP_NONE &&
+	http->request->hier.alg != PEER_SA_NONE &&
+	/* a successful CD lookup was made */
+	http->request->hier.cd_lookup != LOOKUP_NONE &&
+	/* it was not a CD miss (we go direct on CD MISSes) */
+	!(http->request->hier.alg == PEER_SA_DIGEST && http->request->hier.cd_lookup == LOOKUP_MISS) &&
 	/* paranoid: we have a reply pointer */
 	(reply = storeEntryReply(http->entry))) {
 	const char *x_cache_fld = httpHeaderGetLastStr(&reply->header, HDR_X_CACHE);
 	const int real_hit = x_cache_fld && !strncmp(x_cache_fld, "HIT", 3);
-	const int guess_hit = H->cd_lookup == LOOKUP_HIT;
-	peer *peer = peerFindByName(H->host);
+	const int guess_hit = LOOKUP_HIT == http->request->hier.cd_lookup;
+	peer *peer = peerFindByName(http->request->hier.cd_host);
 
+	debug(33,2) ("clientUpdateCounters: peer %s real/guess: %d/%d for %s!\n",
+	    http->request->hier.cd_host, real_hit, guess_hit, http->request->host);
 	cacheDigestGuessStatsUpdate(&Counter.cd.guess, real_hit, guess_hit);
 	if (peer)
 	    cacheDigestGuessStatsUpdate(&peer->digest.stats.guess,
 		real_hit, guess_hit);
-	else
-	    debug(33,1) ("clientUpdateCounters: lost peer: %s!\n", storeUrl(http->entry));
+	else {
+	    debug(33,2) ("clientUpdateCounters: lost peer %s for %s!\n", 
+		http->request->hier.cd_host, http->request->host);
+	    fatal_dump("lost peer");
+	}
     }
 #endif
 }
