#if HAVE_ARPA_INET_H
#include <arpa/inet.h>
#endif

#define free +

#define DEBUG_SNMPTRACE		0	/* set to 1 to print all SNMP actions */
#define DEBUG_SNMPFULLDUMP	0	/* set to 1 to dump all SNMP packets */

#include "asn1.h"
#include "snmp.h"
#include "snmp_impl.h"
#include "snmp_api.h"
#include "snmp_client.h"

#include "util.h"

#define PACKET_LENGTH	4500

oid default_enterprise[] =
{1, 3, 6, 1, 4, 1, 3, 1, 1};	/* enterprises.cmu.systems.cmuSNMP */

#define DEFAULT_COMMUNITY   "public"
#define DEFAULT_REMPORT	    SNMP_PORT
#define DEFAULT_ENTERPRISE  default_enterprise
#define DEFAULT_TIME	    0
#define DEFAULT_MMS	    1389	/* large, randomly picked for testing purposes */

/*
 * Internal information about the state of the snmp session.
 */
struct snmp_internal_session {
    int sd;			/* socket descriptor for this connection */
    ipaddr addr;		/* address of connected peer */
    struct request_list *requests;	/* Info about outstanding requests */
};

/*
 * A list of all the outstanding requests for a particular session.
 */
struct request_list {
    struct request_list *next_request;
    u_long request_id;		/* request id */
    int retries;		/* Number of retries */
    u_long timeout;		/* length to wait for timeout */
    struct timeval time;	/* Time this request was made */
    struct timeval expire;	/* time this request is due to expire */
    struct snmp_pdu *pdu;	/* The pdu for this request (saved so it can be retransmitted */
};

/*
 * The list of active/open sessions.
 */
struct session_list {
    struct session_list *next;
    struct snmp_session *session;
    struct snmp_internal_session *internal;
};

struct session_list *Sessions = NULL;

u_long Reqid = 0;
int snmp_errno = 0;

char *api_errors[4] =
{
    "Unknown session",
    "Unknown host",
    "Invalid local port",
    "Unknown Error"
};


static void sync_with_agent(struct snmp_session *session);

#if NO_PRINTFS
static char *
api_errstring(int snmp_errnumber)
{
    if (snmp_errnumber <= SNMPERR_BAD_SESSION && snmp_errnumber >= SNMPERR_GENERR) {
	return api_errors[snmp_errnumber + 4];
    } else {
	return "Unknown Error";
    }
}
#endif

#if UNUSED_CODE
/*
 * Gets initial request ID for all transactions.
 */
static void
init_snmp(void)
{
    struct timeval tv;

    gettimeofday(&tv, (struct timezone *) 0);
    srandom(tv.tv_sec ^ tv.tv_usec);
    Reqid = random();
}

#endif


/*
 * Dump snmp packet to stdout:
 */
static void
snmp_print_packet(char *packet, int length, ipaddr addr, int code)
{
    if (length < 0) {
	return;
    }
#if NO_PRINTFS
    if (code <= 0) {		/* received */
	printf("\nReceived %4d bytes from ", length);
    } else {			/* sending */
	printf("\nSending  %4d bytes to   ", length);
    }
    printf("%s:", inet_ntoa(addr.sin_addr));
#endif
#if DEBUG_SNMPFULLDUMP
    for (count = 0; count < length; count++) {
	if ((count & 15) == 0) {
	    printf("\n  ");
	}
	printf("%02X ", (int) (packet[count] & 255));
    }
#endif
#if NO_PRINTFS
    fflush(stdout);
#endif
}

#if DEBUG_SNMPTRACE
/*
 * Print request
 */
#define TRACE_SEND   (0)
#define TRACE_RECV   (1)
#define TRACE_TIMEOUT (2)
static void
snmp_print_trace(struct session_list *slp, struct request_list *rp, int code)
{
    int reqid = 0, retries = 1;
    if (rp) {
	reqid = rp->request_id;
	retries = rp->retries;
    }
    printf("\n Session %2d  ReqId %4d  ", slp->internal->sd, reqid);
    switch (code) {
    case TRACE_SEND:
	printf("send pdu (%d)", retries);
	break;
    case TRACE_RECV:
	printf("recv pdu");
	break;
    case TRACE_TIMEOUT:
	printf("time out");
	break;
    }
    fflush(stdout);
}
#endif /* DEBUG_SNMPTRACE */




/*
 * Sets up the session with the snmp_session information provided
