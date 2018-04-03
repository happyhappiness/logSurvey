#include <net/if.h>
#include <netinet/in.h>
#include <net/pfvar.h>
#endif

#if LINUX_NETFILTER
#include <linux/netfilter_ipv4.h>
#endif

int
clientNatLookup(int fd, const IPAddress &me, const IPAddress &peer, IPAddress &dst)
{

#if IPF_TRANSPARENT  /* --enable-ipf-transparent */

    dst = me;
    if( !me.IsIPv4() ) return -1;
    if( !peer.IsIPv4() ) return -1;
