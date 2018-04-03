	    inet_ntoa(from.sin_addr),
	    ntohs(from.sin_port));
}

void
icpConnectionsOpen(void)
{
    u_short port;
    struct in_addr addr;
    struct sockaddr_in xaddr;
    int x;
    int len;
    wordlist *s;
    if (Config2.Accel.on && !Config.onoff.accel_with_proxy)
	return;
    if ((port = Config.Port.icp) <= 0)
	return;
    enter_suid();
    theInIcpConnection = comm_open(SOCK_DGRAM,
	0,
	Config.Addrs.udp_incoming,
	port,
	COMM_NONBLOCKING,
	"ICP Port");
    leave_suid();
    if (theInIcpConnection < 0)
	fatal("Cannot open ICP Port");
    fd_note(theInIcpConnection, "ICP socket");
    commSetSelect(theInIcpConnection,
	COMM_SELECT_READ,
	icpHandleUdp,
	NULL, 0);
    for (s = Config.mcast_group_list; s; s = s->next)
	ipcache_nbgethostbyname(s->key, mcastJoinGroups, NULL);
    debug(1, 1) ("Accepting ICP connections on port %d, FD %d.\n",
	(int) port, theInIcpConnection);
    if ((addr = Config.Addrs.udp_outgoing).s_addr != no_addr.s_addr) {
	enter_suid();
	theOutIcpConnection = comm_open(SOCK_DGRAM,
	    0,
	    addr,
	    port,
	    COMM_NONBLOCKING,
	    "ICP Port");
	leave_suid();
	if (theOutIcpConnection < 0)
	    fatal("Cannot open Outgoing ICP Port");
	commSetSelect(theOutIcpConnection,
	    COMM_SELECT_READ,
	    icpHandleUdp,
	    NULL, 0);
	debug(1, 1) ("Accepting ICP connections on port %d, FD %d.\n",
	    (int) port, theInIcpConnection);
	fd_note(theOutIcpConnection, "Outgoing ICP socket");
	fd_note(theInIcpConnection, "Incoming ICP socket");
    } else {
	theOutIcpConnection = theInIcpConnection;
    }
    memset(&theOutICPAddr, '\0', sizeof(struct in_addr));
    len = sizeof(struct sockaddr_in);
    memset(&xaddr, '\0', len);
    x = getsockname(theOutIcpConnection,
	(struct sockaddr *) &xaddr, &len);
    if (x < 0)
	debug(50, 1) ("theOutIcpConnection FD %d: getsockname: %s\n",
	    theOutIcpConnection, xstrerror());
    else
	theOutICPAddr = xaddr.sin_addr;
}
