     MemObject *mem;
     icp_common_t *query;
     LOCAL_ARRAY(char, url, MAX_URL);
-    if (p->type != PEER_MULTICAST)
-	fatal_dump("peerCountMcastPeersStart: non-multicast peer");
+    assert(p->type == PEER_MULTICAST);
     p->mcast.flags &= ~PEER_COUNT_EVENT_PENDING;
     snprintf(url, MAX_URL, "http://%s/", inet_ntoa(p->in_addr.sin_addr));
     fake = storeCreateEntry(url, url, 0, METHOD_GET);
