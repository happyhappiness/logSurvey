    len += ulen + 1;
    icmpSendEcho(to, S_ICMP_ICP, payload, len);
    put_free_8k_page(payload);
}

void
icmpDomainPing(struct in_addr to, char *domain)
{
    debug(37, 3, "icmpDomainPing: '%s'\n", domain);
    icmpSendEcho(to, S_ICMP_DOM, domain, 0);
}

static void
icmpHandleSourcePing(struct sockaddr_in *from, char *buf)
{
    char *key;
    StoreEntry *entry;
    icp_common_t header;
    char *url;
    memcpy(&header, buf, sizeof(icp_common_t));
    url = buf + sizeof(icp_common_t);
    if (neighbors_do_private_keys && header.reqnum) {
	key = storeGeneratePrivateKey(url, METHOD_GET, header.reqnum);
    } else {
	key = storeGeneratePublicKey(url, METHOD_GET);
    }
    debug(37, 3, "icmpHandleSourcePing: from %s, key=%s\n",
	inet_ntoa(from->sin_addr),
	key);
    if ((entry = storeGet(key)) == NULL)
	return;
    if (entry->lock_count == 0)
	return;
    /* call neighborsUdpAck even if ping_status != PING_WAITING */
    neighborsUdpAck(icmp_sock,
	url,
	&header,
	from,
	entry,
	NULL,
	0);
}

#endif /* USE_ICMP */
