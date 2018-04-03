 #if USE_ICMP
 
 #include "squid.h"
-
-#include <netinet/in_systm.h>
-#include <netinet/in.h>
-#include <netinet/ip.h>
-#include <netinet/ip_icmp.h>
-
-#ifndef _SQUID_LINUX_
-#define icmphdr icmp
-#define iphdr ip
-#endif
-
-#ifdef _SQUID_LINUX_
-#define icmp_type type
-#define icmp_code code
-#define icmp_cksum checksum
-#define icmp_id un.echo.id
-#define icmp_seq un.echo.sequence
-#define icmp_gwaddr un.gateway
-#define ip_hl ihl
-#define ip_v version
-#define ip_tos tos
-#define ip_len tot_len
-#define ip_id id
-#define ip_off frag_off
-#define ip_ttl ttl
-#define ip_p protocol
-#define ip_sum check
-#define ip_src saddr
-#define ip_dst daddr
-#endif
+#include "pinger.h"
 
 #define S_ICMP_ECHO	1
 #define S_ICMP_ICP	2
 #define S_ICMP_DOM	3
 
 typedef struct _icmpQueueData {
-    struct sockaddr_in to;
     char *msg;
     int len;
     struct _icmpQueueData *next;
     void (*free) _PARAMS((void *));
 } icmpQueueData;
 
-#define MAX_PAYLOAD (8192 - sizeof(struct icmphdr) - sizeof (char) - sizeof(struct timeval) - 1)
-
-typedef struct {
-    struct timeval tv;
-    unsigned char opcode;
-    char payload[MAX_PAYLOAD];
-} icmpEchoData;
-
 static icmpQueueData *IcmpQueueHead = NULL;
 
 int icmp_sock = -1;
 
-static int icmp_ident = -1;
-static int icmp_pkts_sent = 0;
-
-static char *icmpPktStr[] =
-{
-    "Echo Reply",
-    "ICMP 1",
-    "ICMP 2",
-    "Destination Unreachable",
-    "Source Quench",
-    "Redirect",
-    "ICMP 6",
-    "ICMP 7",
-    "Echo",
-    "ICMP 9",
-    "ICMP 10",
-    "Time Exceeded",
-    "Parameter Problem",
-    "Timestamp",
-    "Timestamp Reply",
-    "Info Request",
-    "Info Reply",
-    "Out of Range Type"
-};
-
-static int in_cksum _PARAMS((unsigned short *ptr, int size));
 static void icmpRecv _PARAMS((int, void *));
-static void icmpQueueSend _PARAMS((struct in_addr,
-	char *msg,
+static void icmpQueueSend _PARAMS((pingerEchoData * pkt,
 	int len,
 	void          (*free) _PARAMS((void *))));
 static void icmpSend _PARAMS((int fd, icmpQueueData * queue));
-static void icmpLog _PARAMS((struct icmphdr * icmp,
-	struct in_addr addr,
-	int rtt,
-	int hops));
-static int ipHops _PARAMS((int ttl));
-static void icmpProcessReply _PARAMS((struct sockaddr_in * from,
-	struct icmphdr * icmp,
-	int hops));
 static void icmpHandleSourcePing _PARAMS((struct sockaddr_in * from, char *buf));
 
 void
 icmpOpen(void)
 {
-    struct protoent *proto = NULL;
-    if ((proto = getprotobyname("icmp")) == 0) {
-	debug(37, 0, "icmpOpen: unknown protocol: icmp\n");
-	return;
-    }
-    enter_suid();
-    icmp_sock = comm_open(SOCK_RAW,
-	proto->p_proto,
-	Config.Addrs.udp_outgoing,
+    struct sockaddr_in S;
+    int namelen = sizeof(struct sockaddr_in);
+    pid_t pid;
+    char *command = "pinger";
+    int child_sock;
+    icmp_sock = comm_open(SOCK_DGRAM,
+	0,
+	local_addr,
 	0,
 	COMM_NONBLOCKING,
 	"ICMP Socket");
-    leave_suid();
     if (icmp_sock < 0) {
 	debug(37, 0, "icmpOpen: icmp_sock: %s\n", xstrerror());
 	return;
     }
-    icmp_ident = getpid() & 0xffff;
+    child_sock = comm_open(SOCK_DGRAM,
+	0,
+	local_addr,
+	0,
+	0,
+	"ICMP Socket");
+    if (child_sock < 0) {
+	debug(37, 0, "icmpOpen: child_sock: %s\n", xstrerror());
+	return;
+    }
+    getsockname(icmp_sock, &S, &namelen);
+    if (comm_connect_addr(child_sock, &S) != COMM_OK)
+	fatal_dump(xstrerror());
+    getsockname(child_sock, &S, &namelen);
+    if (comm_connect_addr(icmp_sock, &S) != COMM_OK)
+	fatal_dump(xstrerror());
+    if ((pid = fork()) < 0) {
+	debug(29, 0, "icmpOpen: fork: %s\n", xstrerror());
+	comm_close(icmp_sock);
+	comm_close(child_sock);
+	return;
+    }
+    if (pid == 0) {		/* child */
+	comm_close(icmp_sock);
+	dup2(child_sock, 0);
+	dup2(child_sock, 1);
+	comm_close(child_sock);
+	dup2(fileno(debug_log), 2);
+	fclose(debug_log);
+	enter_suid();
+	execlp(command, "(pinger)", NULL);
+	debug(29, 0, "icmpOpen: %s: %s\n", command, xstrerror());
+	_exit(1);
+    }
+    comm_close(child_sock);
     comm_set_select_handler(icmp_sock,
 	COMM_SELECT_READ,
 	(PF) icmpRecv,
 	(void *) -1);
-    debug(37, 0, "ICMP socket opened on FD %d\n", icmp_sock);
+    comm_set_fd_lifetime(icmp_sock, -1);
 }
 
 void
 icmpClose(void)
 {
     comm_close(icmp_sock);
-    icmp_sock = -1;
-    icmp_ident = 0;
 }
 
 static void
 icmpSendEcho(struct in_addr to, int opcode, char *payload, int len)
 {
-    char *pkt = NULL;
-    struct icmphdr *icmp = NULL;
-    icmpEchoData *echo;
-    int icmp_pktsize = sizeof(struct icmphdr);
-    pkt = get_free_8k_page();
-    memset(pkt, '\0', 8192);
-    icmp = (struct icmphdr *) (void *) pkt;
-    icmp->icmp_type = ICMP_ECHO;
-    icmp->icmp_code = 0;
-    icmp->icmp_cksum = 0;
-    icmp->icmp_id = icmp_ident;
-    icmp->icmp_seq = icmp_pkts_sent++;
-    echo = (icmpEchoData *) (icmp + 1);
-    /* echo = (icmpEchoData *) (pkt + icmp_pktsize); */
-    echo->opcode = (unsigned char) opcode;
-    echo->tv = current_time;
-    icmp_pktsize += sizeof(icmpEchoData) - MAX_PAYLOAD;
-    if (payload) {
-	if (len == 0)
-	    len = strlen(payload);
-	if (len > MAX_PAYLOAD)
-	    len = MAX_PAYLOAD;
-	memcpy(echo->payload, payload, len);
-	icmp_pktsize += len;
-    }
-    icmp->icmp_cksum = in_cksum((u_short *) icmp, icmp_pktsize);
-    icmpQueueSend(to, pkt, icmp_pktsize, put_free_8k_page);
+    pingerEchoData *pecho = xcalloc(1, sizeof(pingerEchoData));
+    if (payload && len == 0)
+	len = strlen(payload);
+    pecho->to = to;
+    pecho->opcode = (unsigned char) opcode;
+    pecho->psize = len;
+    memcpy(pecho->payload, payload, len);
+    icmpQueueSend(pecho, sizeof(pingerEchoData) - 8192 + len, xfree);
 }
 
 static void
-icmpProcessReply(struct sockaddr_in *from, struct icmphdr *icmp, int hops)
+icmpRecv(int unused1, void *unused2)
 {
-    int rtt;
-    icmpEchoData *echo = (icmpEchoData *) (icmp + 1);
-    rtt = tvSubMsec(echo->tv, current_time);
-    icmpLog(icmp, from->sin_addr, rtt, hops);
-    switch (echo->opcode) {
+    int n;
+    pingerReplyData preply;
+    static struct sockaddr_in F;
+
+    comm_set_select_handler(icmp_sock,
+	COMM_SELECT_READ,
+	(PF) icmpRecv,
+	(void *) -1);
+    n = recv(icmp_sock,
+	(char *) &preply,
+	sizeof(pingerReplyData),
+	0);
+    F.sin_family = AF_INET;
+    F.sin_addr = preply.from;
+    F.sin_port = 0;
+    switch (preply.opcode) {
     case S_ICMP_ECHO:
 	break;
     case S_ICMP_ICP:
-	icmpHandleSourcePing(from, echo->payload);
+	icmpHandleSourcePing(&F, preply.payload);
 	break;
     case S_ICMP_DOM:
-	netdbHandlePingReply(from, hops, rtt);
+	netdbHandlePingReply(&F, preply.hops, preply.rtt);
 	break;
     default:
-	debug(37, 0, "icmpProcessReply: Bad opcode: %d\n", (int) echo->opcode);
+	debug(37, 0, "icmpRecv: Bad opcode: %d\n", (int) preply.opcode);
 	break;
     }
 }
 
-static void
-icmpRecv(int unused1, void *unused2)
-{
-    int n;
-    int fromlen;
-    struct sockaddr_in from;
-    int iphdrlen = 20;
-    struct iphdr *ip = NULL;
-    register struct icmphdr *icmp = NULL;
-    char *pkt = get_free_8k_page();
-    int hops;
-
-    comm_set_select_handler(icmp_sock,
-	COMM_SELECT_READ,
-	(PF) icmpRecv,
-	(void *) -1);
-    fromlen = sizeof(from);
-    n = recvfrom(icmp_sock,
-	pkt,
-	8192,
-	0,
-	(struct sockaddr *) &from,
-	&fromlen);
-    debug(37, 9, "icmpRecv: %d bytes from %s\n", n, inet_ntoa(from.sin_addr));
-    ip = (struct iphdr *) (void *) pkt;
-#if HAVE_IP_HL 
-    iphdrlen = ip->ip_hl << 2;
-#else
-#if BYTE_ORDER == BIG_ENDIAN
-    iphdrlen = (ip->ip_vhl >> 4) << 2;
-#endif
-#if BYTE_ORDER == LITTLE_ENDIAN
-    iphdrlen = (ip->ip_vhl & 0xF) << 2;
-#endif
-#endif
-    icmp = (struct icmphdr *) (void *) (pkt + iphdrlen);
-    if (icmp->icmp_type == ICMP_ECHOREPLY) {
-	if (icmp->icmp_id == icmp_ident) {
-	    hops = ipHops(ip->ip_ttl);
-	    icmpProcessReply(&from, icmp, hops);
-	}
-    }
-    put_free_8k_page(pkt);
-}
-
-
-static int
-in_cksum(unsigned short *ptr, int size)
-{
-
-    register long sum;
-    unsigned short oddbyte;
-    register unsigned short answer;
-    sum = 0;
-    while (size > 1) {
-	sum += *ptr++;
-	size -= 2;
-    }
-    if (size == 1) {
-	oddbyte = 0;
-	*((unsigned char *) &oddbyte) = *(unsigned char *) ptr;
-	sum += oddbyte;
-    }
-    sum = (sum >> 16) + (sum & 0xffff);
-    sum += (sum >> 16);
-    answer = ~sum;
-    return (answer);
-}
 
 static void
-icmpQueueSend(struct in_addr to,
-    char *pkt,
+icmpQueueSend(pingerEchoData * pkt,
     int len,
     void (*free) _PARAMS((void *)))
 {
     icmpQueueData *q = NULL;
     icmpQueueData **H = NULL;
-    debug(37, 3, "icmpQueueSend: Queueing %d bytes for %s\n", len, inet_ntoa(to));
+    debug(37, 3, "icmpQueueSend: Queueing %d bytes\n", len);
     q = xcalloc(1, sizeof(icmpQueueData));
-    q->to.sin_family = AF_INET;
-    q->to.sin_addr = to;
-    q->msg = pkt;
+    q->msg = (char *) pkt;
     q->len = len;
     q->free = free;
     for (H = &IcmpQueueHead; *H; H = &(*H)->next);
