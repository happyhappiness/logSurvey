    memcpy(&us, buf + 10, 2);
    qh.arcount = ntohs(us);

    offset = sizeof(qh);
    memset(qname, '\0', MAX_QNAME_SZ);
    x = rfc1035NameUnpack(buf, len, &offset, qname, MAX_QNAME_SZ);
    if (0 != x)
	return 0;
    if ('\0' == qname[0])
	strcpy(qname, ".");
    while ((t = strchr(qname, '\n')))
	*t = ' ';
    while ((t = strchr(qname, '\r')))
	*t = ' ';
    for (t = qname; *t; t++)
	*t = tolower(*t);

    memcpy(&us, buf + offset, 2);
    qtype = ntohs(us);
    memcpy(&us, buf + offset + 2, 2);
    qclass = ntohs(us);

    fprintf (stderr, "qtype = %hu\n", qtype);

    /* gather stats */
    qtype_counts[qtype]++;
    qclass_counts[qclass]++;
    opcode_counts[qh.opcode]++;

    s = QnameToNld(qname, 1);
    sc = StringCounter_lookup_or_add(&Tlds, s);
    sc->count++;

    if (sld_flag) {
	s = QnameToNld(qname, 2);
	sc = StringCounter_lookup_or_add(&Slds, s);
	sc->count++;

	/* increment StringAddrCounter */
	ssc = StringAddrCounter_lookup_or_add(&SSC2, sip, s);
	ssc->count++;

    }
    if (nld_flag) {
	s = QnameToNld(qname, 3);
	sc = StringCounter_lookup_or_add(&Nlds, s);
	sc->count++;

	/* increment StringAddrCounter */
	ssc = StringAddrCounter_lookup_or_add(&SSC3, sip, s);
	ssc->count++;

    }
    return 1;
}

static int
handle_udp(const struct udphdr *udp, int len, struct in_addr sip, struct in_addr dip)
{
    char buf[PCAP_SNAPLEN];
    fprintf (stderr, "handle_udp (udp = %p, len = %i)\n",
		    (void *) udp, len);
    if (ntohs (udp->uh_dport) != 53)
	return 0;
    memcpy(buf, udp + 1, len - sizeof(*udp));
    if (0 == handle_dns(buf, len - sizeof(*udp), sip, dip))
	return 0;
    return 1;
}

static int
handle_ip(const struct ip *ip, int len)
{
    char buf[PCAP_SNAPLEN];
    int offset = ip->ip_hl << 2;
    AgentAddr *clt;
    AgentAddr *srv;
    fprintf (stderr, "handle_ip (ip = %p, len = %i)\n",
		    (void *) ip, len);
    if (ignore_addr.s_addr)
	if (ip->ip_src.s_addr == ignore_addr.s_addr)
	    return 0;
    if (IPPROTO_UDP != ip->ip_p)
	return 0;
    memcpy(buf, (void *) ip + offset, len - offset);
    if (0 == handle_udp((struct udphdr *) buf, len - offset, ip->ip_src, ip->ip_dst))
	return 0;
    clt = AgentAddr_lookup_or_add(&Sources, ip->ip_src);
    clt->count++;
    srv = AgentAddr_lookup_or_add(&Destinations, ip->ip_dst);
    srv->count++;
    return 1;
}

#if USE_PPP
static int
handle_ppp(const u_char * pkt, int len)
{
