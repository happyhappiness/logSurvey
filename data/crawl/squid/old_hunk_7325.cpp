{
    struct in_addr b;
    b.s_addr = ntohl(a.s_addr);
    if (IN_CLASSC(b.s_addr))
	b.s_addr &= IN_CLASSC_NET;
    else if (IN_CLASSB(b.s_addr))
	b.s_addr &= IN_CLASSB_NET;
    else if (IN_CLASSA(b.s_addr))
	b.s_addr &= IN_CLASSA_NET;
    b.s_addr = htonl(b.s_addr);
    return b;
}

static int
sortByHops(netdbEntry ** n1, netdbEntry ** n2)
{
    if ((*n1)->hops > (*n2)->hops)
	return 1;
    else if ((*n1)->hops < (*n2)->hops)
	return -1;
    else
	return 0;
}

#endif /* USE_ICMP */

/* PUBLIC FUNCTIONS */
