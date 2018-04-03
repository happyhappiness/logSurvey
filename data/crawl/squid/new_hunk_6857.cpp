icmpOpen(void)
{
#if USE_ICMP
    char *args[2];
    int x;
    int rfd;
    int wfd;
    args[0] = "(pinger)";
    args[1] = NULL;
    x = ipcCreate(IPC_UDP_SOCKET,
	Config.Program.pinger,
	args,
	"Pinger Socket",
	&rfd,
	&wfd);
    if (x < 0)
	return;
    assert(rfd == wfd);
    icmp_sock = rfd;
    commSetSelect(icmp_sock, COMM_SELECT_READ, icmpRecv, NULL, 0);
    commSetTimeout(icmp_sock, -1, NULL, NULL);
    debug(29, 0) ("Pinger socket opened on FD %d\n", icmp_sock);
