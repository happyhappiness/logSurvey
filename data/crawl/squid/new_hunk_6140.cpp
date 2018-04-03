idnsInit(void)
{
    static int init = 0;
    if (DnsSocket < 0) {
	DnsSocket = comm_open(SOCK_DGRAM,
	    0,
	    Config.Addrs.udp_outgoing,
	    0,
	    COMM_NONBLOCKING,
	    "DNS Socket");
	if (DnsSocket < 0)
	    fatal("Could not create a DNS socket");
	debug(78, 1) ("DNS Socket created on FD %d\n", DnsSocket);
	commSetSelect(DnsSocket, COMM_SELECT_READ, idnsRead, NULL, 0);
    }
    if (nns == 0)
	idnsParseResolvConf();