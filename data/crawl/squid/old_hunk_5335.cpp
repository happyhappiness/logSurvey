#include "squid.h"
#include "ACL.h"
#include "ACLChecklist.h"
#include "splay.h"
#include "HttpRequest.h"
#include "authenticate.h"
#include "fde.h"
#include "ExternalACL.h"
#include "ACLDestinationIP.h"

static void aclParseIntlist(void *curlist);
#if SQUID_SNMP
static void aclParseWordList(void *curlist);
#endif
static void aclParseProtoList(void *curlist);
static void aclParseMethodList(void *curlist);
static void aclParseIntRange(void *curlist);
static void aclDestroyIntRange(intrange *);
static int aclMatchIntegerRange(intrange * data, int i);
#if SQUID_SNMP
static int aclMatchWordList(wordlist *, const char *);
#endif
static void aclParseUserMaxIP(void *data);
static void aclDestroyUserMaxIP(void *data);
static wordlist *aclDumpUserMaxIP(void *data);

static int aclMatchUserMaxIP(void *, auth_user_request_t *, struct in_addr);
static squid_acl aclStrToType(const char *s);
static wordlist *aclDumpIntlistList(intlist * data);
static wordlist *aclDumpIntRangeList(intrange * data);
static wordlist *aclDumpProtoList(intlist * data);
static wordlist *aclDumpMethodList(intlist * data);


#if USE_ARP_ACL
static void aclParseArpList(void *curlist);
static int decode_eth(const char *asc, char *eth);

static int aclMatchArp(void *dataptr, struct in_addr c);
static wordlist *aclDumpArpList(void *);
static splayNode::SPLAYCMP aclArpCompare;
static splayNode::SPLAYWALKEE aclDumpArpListWalkee;
#endif

MemPool *ACL::Pool(NULL);
void *
ACL::operator new (size_t byteCount)
{
    /* derived classes with different sizes must implement their own new */
    assert (byteCount == sizeof (ACL));

    if (!Pool)
        Pool = memPoolCreate("ACL", sizeof (ACL));

    return memPoolAlloc(Pool);
}

void
ACL::operator delete (void *address)
{
    memPoolFree (Pool, address);
}

void
ACL::deleteSelf() const
{
    delete this;
}

template<class T>
inline void
xRefFree(T &thing)
{
    xfree (thing);
}

template<class T>
inline int
splaystrcmp (T&l, T&r)
{
    return strcmp ((char *)l,(char *)r);
}


static squid_acl
aclStrToType(const char *s)
{
    if (!strcmp(s, "port"))
        return ACL_URL_PORT;

    if (!strcmp(s, "myport"))
        return ACL_MY_PORT;

    if (!strcmp(s, "maxconn"))
        return ACL_MAXCONN;

    if (!strncmp(s, "proto", 5))
        return ACL_PROTO;

    if (!strcmp(s, "method"))
        return ACL_METHOD;

    if (!strcmp(s, "src_as"))
        return ACL_SRC_ASN;

    if (!strcmp(s, "dst_as"))
        return ACL_DST_ASN;

#if SQUID_SNMP

    if (!strcmp(s, "snmp_community"))
        return ACL_SNMP_COMMUNITY;

#endif
#if SRC_RTT_NOT_YET_FINISHED

    if (!strcmp(s, "src_rtt"))
        return ACL_NETDB_SRC_RTT;

#endif
#if USE_ARP_ACL

    if (!strcmp(s, "arp"))
        return ACL_SRC_ARP;

#endif

    if (!strcmp(s, "rep_mime_type"))
        return ACL_REP_MIME_TYPE;

    if (!strcmp(s, "max_user_ip"))
        return ACL_MAX_USER_IP;

    if (!strcmp(s, "external"))
        return ACL_EXTERNAL;

    return ACL_NONE;
}

static const char *aclTypeToStr(squid_acl);
const char *
aclTypeToStr(squid_acl type)
{
    if (type == ACL_URL_PORT)
        return "port";

    if (type == ACL_MY_PORT)
        return "myport";

    if (type == ACL_MAXCONN)
        return "maxconn";

    if (type == ACL_PROTO)
        return "proto";

    if (type == ACL_METHOD)
        return "method";

    if (type == ACL_SRC_ASN)
        return "src_as";

    if (type == ACL_DST_ASN)
        return "dst_as";

#if SQUID_SNMP

    if (type == ACL_SNMP_COMMUNITY)
        return "snmp_community";

#endif
#if SRC_RTT_NOT_YET_FINISHED

    if (type == ACL_NETDB_SRC_RTT)
        return "src_rtt";

#endif
#if USE_ARP_ACL

    if (type == ACL_SRC_ARP)
        return "arp";

#endif

    if (type == ACL_REP_MIME_TYPE)
        return "rep_mime_type";

    if (type == ACL_MAX_USER_IP)
        return "max_user_ip";

    if (type == ACL_EXTERNAL)
        return "external";

    return "ERROR";
}

acl *
