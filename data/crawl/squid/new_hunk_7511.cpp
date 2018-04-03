#if USE_ICMP

#include "squid.h"
#include "pinger.h"

#define S_ICMP_ECHO	1
#define S_ICMP_ICP	2
#define S_ICMP_DOM	3

typedef struct _icmpQueueData {
    char *msg;
    int len;
    struct _icmpQueueData *next;
    void (*free) _PARAMS((void *));
} icmpQueueData;

static icmpQueueData *IcmpQueueHead = NULL;

int icmp_sock = -1;

static void icmpRecv _PARAMS((int, void *));
static void icmpQueueSend _PARAMS((pingerEchoData * pkt,
	int len,
	void          (*free) _PARAMS((void *))));
static void icmpSend _PARAMS((int fd, icmpQueueData * queue));
static void icmpHandleSourcePing _PARAMS((struct sockaddr_in * from, char *buf));

void
icmpOpen(void)
{
    struct sockaddr_in S;
    int namelen = sizeof(struct sockaddr_in);
    pid_t pid;
    char *command = "pinger";
    int child_sock;
    icmp_sock = comm_open(SOCK_DGRAM,
	0,
	local_addr,
	0,
	COMM_NONBLOCKING,
	"ICMP Socket");
    if (icmp_sock < 0) {
	debug(37, 0, "icmpOpen: icmp_sock: %s\n", xstrerror());
	return;
    }
    child_sock = comm_open(SOCK_DGRAM,
	0,
	local_addr,
	0,
	0,
	"ICMP Socket");
    if (child_sock < 0) {
	debug(37, 0, "icmpOpen: child_sock: %s\n", xstrerror());
	return;
    }
    getsockname(icmp_sock, &S, &namelen);
    if (comm_connect_addr(child_sock, &S) != COMM_OK)
	fatal_dump(xstrerror());
    getsockname(child_sock, &S, &namelen);
    if (comm_connect_addr(icmp_sock, &S) != COMM_OK)
	fatal_dump(xstrerror());
    if ((pid = fork()) < 0) {
	debug(29, 0, "icmpOpen: fork: %s\n", xstrerror());
	comm_close(icmp_sock);
	comm_close(child_sock);
	return;
    }
    if (pid == 0) {		/* child */
	comm_close(icmp_sock);
	dup2(child_sock, 0);
	dup2(child_sock, 1);
	comm_close(child_sock);
	dup2(fileno(debug_log), 2);
	fclose(debug_log);
	enter_suid();
	execlp(command, "(pinger)", NULL);
	debug(29, 0, "icmpOpen: %s: %s\n", command, xstrerror());
	_exit(1);
    }
    comm_close(child_sock);
    comm_set_select_handler(icmp_sock,
	COMM_SELECT_READ,
	(PF) icmpRecv,
	(void *) -1);
    comm_set_fd_lifetime(icmp_sock, -1);
}

void
icmpClose(void)
{
    comm_close(icmp_sock);
}

static void
icmpSendEcho(struct in_addr to, int opcode, char *payload, int len)
{
    pingerEchoData *pecho = xcalloc(1, sizeof(pingerEchoData));
    if (payload && len == 0)
	len = strlen(payload);
    pecho->to = to;
    pecho->opcode = (unsigned char) opcode;
    pecho->psize = len;
    memcpy(pecho->payload, payload, len);
    icmpQueueSend(pecho, sizeof(pingerEchoData) - 8192 + len, xfree);
}

static void
icmpRecv(int unused1, void *unused2)
{
    int n;
    pingerReplyData preply;
    static struct sockaddr_in F;

    comm_set_select_handler(icmp_sock,
	COMM_SELECT_READ,
	(PF) icmpRecv,
	(void *) -1);
    n = recv(icmp_sock,
	(char *) &preply,
	sizeof(pingerReplyData),
	0);
    F.sin_family = AF_INET;
    F.sin_addr = preply.from;
    F.sin_port = 0;
    switch (preply.opcode) {
    case S_ICMP_ECHO:
	break;
    case S_ICMP_ICP:
	icmpHandleSourcePing(&F, preply.payload);
	break;
    case S_ICMP_DOM:
	netdbHandlePingReply(&F, preply.hops, preply.rtt);
	break;
    default:
	debug(37, 0, "icmpRecv: Bad opcode: %d\n", (int) preply.opcode);
	break;
    }
}


static void
icmpQueueSend(pingerEchoData * pkt,
    int len,
    void (*free) _PARAMS((void *)))
{
    icmpQueueData *q = NULL;
    icmpQueueData **H = NULL;
    debug(37, 3, "icmpQueueSend: Queueing %d bytes\n", len);
    q = xcalloc(1, sizeof(icmpQueueData));
    q->msg = (char *) pkt;
    q->len = len;
    q->free = free;
    for (H = &IcmpQueueHead; *H; H = &(*H)->next);
