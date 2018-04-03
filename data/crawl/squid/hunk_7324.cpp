     p->last_fail_time = squid_curtime;
     eventAdd("peerCheckConnect", peerCheckConnect, p, 80);
 }
+
+static void
+peerCountMcastPeersSchedule(peer * p, time_t when)
+{
+    if (p->mcast.flags & PEER_COUNT_EVENT_PENDING)
+	return;
+    eventAdd("peerCountMcastPeersStart",
+	peerCountMcastPeersStart,
+	p,
+	when);
+    p->mcast.flags |= PEER_COUNT_EVENT_PENDING;
+}
+
+static void
+peerCountMcastPeersStart(void *data)
+{
+    peer *p = data;
+    ps_state *psstate = xcalloc(1, sizeof(ps_state));
+    StoreEntry *fake;
+    MemObject *mem;
+    icp_common_t *query;
+    LOCAL_ARRAY(char, url, MAX_URL);
+    if (p->type != PEER_MULTICAST)
+	fatal_dump("peerCountMcastPeersStart: non-multicast peer");
+    p->mcast.flags &= ~PEER_COUNT_EVENT_PENDING;
+    sprintf(url, "http://%s/", inet_ntoa(p->in_addr.sin_addr));
+    fake = storeCreateEntry(url, NULL, 0, 0, METHOD_GET);
+    psstate->request = requestLink(urlParse(METHOD_GET, url));
+    psstate->entry = fake;
+    psstate->callback = NULL;
+    psstate->fail_callback = NULL;
+    psstate->callback_data = p;
+    psstate->icp.start = current_time;
+    mem = fake->mem_obj;
+    mem->start_ping = current_time;
+    mem->icp_reply_callback = peerCountHandleIcpReply;
+    mem->ircb_data = psstate;
+    comm_set_mcast_ttl(theOutIcpConnection, p->mcast.ttl);
+    p->mcast.reqnum = storeReqnum(fake, METHOD_GET);
+    query = icpCreateMessage(ICP_OP_QUERY, 0, url, p->mcast.reqnum, 0);
+    icpUdpSend(theOutIcpConnection,
+	&p->in_addr,
+	query,
+	LOG_TAG_NONE,
+	PROTO_NONE);
+    fake->ping_status = PING_WAITING;
+    eventAdd("peerCountMcastPeersDone",
+	peerCountMcastPeersDone,
+	p,
+	Config.neighborTimeout);
+    p->mcast.flags |= PEER_COUNTING;
+    peerCountMcastPeersSchedule(p, MCAST_COUNT_RATE);
+}
+
+static void
+peerCountMcastPeersDone(void *data)
+{
+    ps_state *psstate = data;
+    peer *p = psstate->callback_data;
+    StoreEntry *fake = psstate->entry;
+    double old;
+    double new;
+    double D;
+    p->mcast.flags &= ~PEER_COUNTING;
+    D = (double) ++p->mcast.n_times_counted;
+    if (D > 10.0)
+	D = 10.0;
+    old = p->mcast.avg_n_members;
+    new = (double) psstate->icp.n_recv;
+    p->mcast.avg_n_members = (old * (D - 1.0) + new) / D;
+    debug(15, 1, "Group %s: %d replies, %4.1f average\n",
+	p->host,
+	psstate->icp.n_recv,
+	p->mcast.avg_n_members);
+    p->mcast.n_replies_expected = (int) p->mcast.avg_n_members;
+    fake->store_status = STORE_ABORTED;
+    storeReleaseRequest(fake);
+    storeUnlockObject(fake);
+}
+
+static void
+peerCountHandleIcpReply(peer * p, peer_t type, icp_opcode op, void *data)
+{
+    ps_state *psstate = data;
+    psstate->icp.n_recv++;
+    debug(0, 0, "peerCountHandleIcpReply: %d replies\n", psstate->icp.n_recv);
+}
