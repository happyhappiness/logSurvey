 	    (int) peer->digest.stats.kbytes_recv.kb);
 	storeAppendPrintf(sentry, "peer.local_memory = %d\n",
 	    peer->digest.cd ? peer->digest.cd->mask_size/1024 : 0);
-	storeAppendPrintf(sentry, "\n");
-	if (peer->digest.cd) {
+	storeAppendPrintf(sentry, "digest state: inited: %d, disabled: %d usable: %d requested: %d\n",
+	    0 < EBIT_TEST(peer->digest.flags, PD_INITED),
+	    0 < EBIT_TEST(peer->digest.flags, PD_DISABLED),
+	    0 < EBIT_TEST(peer->digest.flags, PD_USABLE),
+	    0 < EBIT_TEST(peer->digest.flags, PD_REQUESTED)
+	);
+	if (peer->digest.cd)
 	    cacheDigestReport(peer->digest.cd, peer->host, sentry);
-	    storeAppendPrintf(sentry, "digest inited: %d, disabled: %d usable: %d requested: %d\n",
-		0 < EBIT_TEST(peer->digest.flags, PD_INITED),
-		0 < EBIT_TEST(peer->digest.flags, PD_DISABLED),
-		0 < EBIT_TEST(peer->digest.flags, PD_USABLE),
-		0 < EBIT_TEST(peer->digest.flags, PD_REQUESTED)
-		);
-	} else {
-	    storeAppendPrintf(sentry, "peer %s has no cache digest\n", peer->host);
-	}
+	else
+	    storeAppendPrintf(sentry, "no cache digest from peer %s\n", peer->host);
 	storeAppendPrintf(sentry, "\n");
     }
 