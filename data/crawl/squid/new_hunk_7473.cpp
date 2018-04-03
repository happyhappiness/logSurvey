
static icmpQueueData *IcmpQueueHead = NULL;

static void icmpRecv _PARAMS((int, void *));
static void icmpQueueSend _PARAMS((pingerEchoData * pkt,
	int len,
	void          (*free_func) _PARAMS((void *))));
static void icmpSend _PARAMS((int fd, icmpQueueData * queue));
static void icmpHandleSourcePing _PARAMS((struct sockaddr_in * from, char *buf));

static void
icmpSendEcho(struct in_addr to, int opcode, char *payload, int len)
{
