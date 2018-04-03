class IPIntercept
{
public:
    int NatLookup(int fd, const IPAddress &me, const IPAddress &peer, IPAddress &dst);

#if LINUX_TPROXY2
    // only relevant to TPROXY v2 connections.
    // which require the address be set specifically post-connect.
    int SetTproxy2OutgoingAddr(int fd, const IPAddress &src);
#endif
}

#if !defined(IP_TRANSPARENT)
/// \ingroup IPInterceptAPI
