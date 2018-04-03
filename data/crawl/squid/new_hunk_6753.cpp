#if HAVE_ARPA_INET_H
#include <arpa/inet.h>
#endif
#if HAVE_SYS_TIME_H
#include <sys/time.h>
#endif
#if HAVE_NETDB_H
#include <netdb.h>
#endif

#include "asn1.h"
#include "snmp.h"

#include "snmp-internal.h"
#include "snmp_impl.h"
#include "snmp_session.h"

#include "mibii.h"
#include "snmp_dump.h"
#include "snmp_error.h"
#include "snmp_vars.h"
#include "snmp_pdu.h"
#include "snmp_msg.h"

#include "snmp_api.h"
#include "snmp_client.h"
#include "snmp_api_error.h"
#include "snmp_api_util.h"

#include "util.h"

extern int snmp_errno;


/*#define DEBUG_API 1*/

/*
 * RFC 1906: Transport Mappings for SNMPv2
 */


oid default_enterprise[] = {1, 3, 6, 1, 4, 1, 3, 1, 1}; /* enterprises.cmu.systems.cmuSNMP */

#define DEFAULT_COMMUNITY   "public"
#define DEFAULT_RETRIES	    4
#define DEFAULT_TIMEOUT	    1000000L
#define DEFAULT_REMPORT	    SNMP_PORT
#define DEFAULT_ENTERPRISE  default_enterprise
#define DEFAULT_TIME	    0

extern int snmp_errno;


struct session_list *Sessions = NULL;

/*
 * Get initial request ID for all transactions.
 */
static int Reqid = 0;

static void init_snmp(void) 
{
  struct timeval tv;

  gettimeofday(&tv, (struct timezone *)0);
  squid_srandom(tv.tv_sec ^ tv.tv_usec);
  Reqid = squid_random();
}



/*
 * Free each element in the input request list.
 */
static void free_request_list(rp)
    struct request_list *rp;
{
    struct request_list *orp;

    while(rp){
	orp = rp;
	rp = rp->next_request;
	if (orp->pdu != NULL)
	    snmp_free_pdu(orp->pdu);
	xfree((char *)orp);
    }
}

/**********************************************************************/

/*
 * Sets up the session with the snmp_session information provided
