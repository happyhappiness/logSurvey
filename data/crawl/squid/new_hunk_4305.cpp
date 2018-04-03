#include <net/if.h>
#include <netinet/in.h>
#include <net/pfvar.h>
#endif /* PF_TRANSPARENT required headers */

#if LINUX_NETFILTER
#include <linux/netfilter_ipv4.h>
#endif

#if LINUX_TPROXY2
#ifdef HAVE_LINUX_NETFILTER_IPV4_IP_TPROXY_H
#include <linux/netfilter_ipv4/ip_tproxy.h>
#else
#error " TPROXY v2 Header file missing: linux/netfilter_ipv4/ip_tproxy.h. Perhapse you meant to use TPROXY v4 ? "
#endif
#endif


// single global instance for access by other components.
IPIntercept IPInterceptor;

void
IPIntercept::StopTransparency(const char *str) {
    if(transparent_active) {
        debugs(89, DBG_IMPORTANT, "Stopping full transparency: " << str);
        transparent_active = 0;
    }
}

void
IPIntercept::StopInterception(const char *str) {
    if(intercept_active) {
        debugs(89, DBG_IMPORTANT, "Stopping IP interception: " << str);
        intercept_active = 0;
    }
}

int
IPIntercept::NetfilterInterception(int fd, const IPAddress &me, IPAddress &dst, int silent)
{
#if LINUX_NETFILTER
    struct addrinfo *lookup = NULL;

    dst.GetAddrInfo(lookup,AF_INET);

    /** \par
     * Try NAT lookup for REDIRECT or DNAT targets. */
    if( getsockopt(fd, SOL_IP, SO_ORIGINAL_DST, lookup->ai_addr, &lookup->ai_addrlen) == 0) {
        if(!silent) {
            debugs(89, DBG_IMPORTANT, HERE << " NF getsockopt(SO_ORIGINAL_DST) failed: " << xstrerror());
            last_reported = squid_curtime;
        }
    }
    else {
        dst = *lookup;
    }

    dst.FreeAddrInfo(lookup);

    if(me != dst) {
        debugs(89, 5, HERE << "address: " << dst);
        return 0;
    }

#endif
    return -1;
}

int
IPIntercept::NetfilterTransparent(int fd, const IPAddress &me, IPAddress &dst, int silent)
{
#if LINUX_NETFILTER
    struct addrinfo *lookup = NULL;

    if( ! fd_table[fd].flags.transparent) return -1;

    dst.GetAddrInfo(lookup,AF_INET);

    /** \par
     * Try lookup for TPROXY targets. BUT, only if the FD is flagged for transparent operations. */
    if(getsockopt(fd, SOL_IP, IP_TRANSPARENT, lookup->ai_addr, &lookup->ai_addrlen) != 0) {
        if(!silent) {
            debugs(89, DBG_IMPORTANT, HERE << " NF getsockopt(IP_TRANSPARENT) failed: " << xstrerror());
            last_reported = squid_curtime;
        }
    }
    else {
        dst = *lookup;
    }

    dst.FreeAddrInfo(lookup);

    if(me != dst) {
        debugs(89, 5, HERE << "address: " << dst);
        return 0;
    }

#endif
    return -1;
}

int
IPIntercept::IPFWInterception(int fd, const IPAddress &me, IPAddress &dst, int silent)
{
#if IPFW_TRANSPARENT
    struct addrinfo *lookup = NULL;

    dst.GetAddrInfo(lookup,AF_INET);

    /** \par
     * Try lookup for IPFW interception. */
    if( getsockname(fd, lookup->ai_addr, &lookup->ai_addrlen) >= 0 ) {
        if( !silent ) {
            debugs(89, DBG_IMPORTANT, HERE << " IPFW getsockname(...) failed: " << xstrerror());
            last_reported = squid_curtime;
        }
    }
    else {
        dst = *lookup;
    }

    dst.FreeAddrInfo(lookup);

    if(me != dst) {
        debugs(89, 5, HERE << "address: " << dst);
        return 0;
    }

#endif
    return -1;
}


// TODO split this one call into one per transparency method
//	with specific switching at run-time ??

int
IPIntercept::NatLookup(int fd, const IPAddress &me, const IPAddress &peer, IPAddress &dst)
{
#if IPF_TRANSPARENT  /* --enable-ipf-transparent */
    dst = me;
    if( !me.IsIPv4() ) return -1;
    if( !peer.IsIPv4() ) return -1;
