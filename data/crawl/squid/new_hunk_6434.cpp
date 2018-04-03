    netdbRelease(n);
#endif
}

void
netdbBinaryExchange(StoreEntry * s)
{
#if USE_ICMP
    http_reply *reply = s->mem_obj->reply;
    netdbEntry *n;
    netdbEntry *next;
    int i;
    int j;
    int rec_sz;
    char *buf;
    struct in_addr addr;
    storeBuffer(s);
    httpReplyReset(reply);
    httpReplySetHeaders(reply, 1.0, HTTP_OK, "OK",
	NULL, -1, squid_curtime, -2);
    httpReplySwapOut(reply, s);
    rec_sz = 0;
    rec_sz += 1 + sizeof(addr.s_addr);
    rec_sz += 1 + sizeof(int);
    rec_sz += 1 + sizeof(int);
    buf = memAllocate(MEM_4K_BUF);
    i = 0;
    next = (netdbEntry *) hash_first(addr_table);
    while (next != NULL) {
	n = next;
	next = (netdbEntry *) hash_next(addr_table);
	if (0.0 == n->rtt)
	    continue;
	if (!safe_inet_addr(n->network, &addr))
	    continue;
	buf[i++] = (char) NETDB_NETWORK;
	xmemcpy(&buf[i], &addr.s_addr, sizeof(addr.s_addr));
	i += sizeof(addr.s_addr);
	buf[i++] = (char) NETDB_RTT;
	j = ntohl((int) (n->rtt * 1000));
	xmemcpy(&buf[i], &j, sizeof(int));
	i += sizeof(int);
	buf[i++] = (char) NETDB_HOPS;
	j = ntohl((int) (n->hops * 1000));
	xmemcpy(&buf[i], &j, sizeof(int));
	i += sizeof(int);
	if (i + rec_sz > 4096 || next == NULL) {
	    storeAppend(s, buf, i);
	    i = 0;
	}
    }
    assert(0 == i);
    storeBufferFlush(s);
    storeComplete(s);
#else
    storeAppendPrintf(s, "NETDB support not compiled into this Squid cache.\n");
#endif
}