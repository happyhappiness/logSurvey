handle_udp(const struct udphdr *udp, int len, struct in_addr sip, struct in_addr dip)
{
    char buf[PCAP_SNAPLEN];
    if (port53 != udp->uh_dport)
	return 0;
    memcpy(buf, udp + 1, len - sizeof(*udp));
    if (0 == handle_dns(buf, len - sizeof(*udp), sip, dip))
