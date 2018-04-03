void
Ip::Intercept::StopTransparency(const char *str)
{
    if (transparentActive_) {
        debugs(89, DBG_IMPORTANT, "Stopping full transparency: " << str);
        transparentActive_ = 0;
    }
}

void
Ip::Intercept::StopInterception(const char *str)
{
    if (interceptActive_) {
        debugs(89, DBG_IMPORTANT, "Stopping IP interception: " << str);
        interceptActive_ = 0;
    }
}

bool
Ip::Intercept::NetfilterInterception(const Comm::ConnectionPointer &newConn, int silent)
{
#if LINUX_NETFILTER
    struct sockaddr_in lookup;
    socklen_t len = sizeof(struct sockaddr_in);
    newConn->local.GetSockAddr(lookup);

    /** \par
     * Try NAT lookup for REDIRECT or DNAT targets. */
    if ( getsockopt(newConn->fd, IPPROTO_IP, SO_ORIGINAL_DST, &lookup, &len) != 0) {
        if (!silent) {
            debugs(89, DBG_IMPORTANT, HERE << " NF getsockopt(SO_ORIGINAL_DST) failed on " << newConn << ": " << xstrerror());
            lastReported_ = squid_curtime;
        }
        debugs(89, 9, HERE << "address: " << newConn);
        return false;
    } else {
        newConn->local = lookup;
        debugs(89, 5, HERE << "address NAT: " << newConn);
        return true;
    }
#endif
    return false;
}

bool
Ip::Intercept::NetfilterTransparent(const Comm::ConnectionPointer &newConn, int silent)
{
#if LINUX_NETFILTER
    /* Trust the user configured properly. If not no harm done.
     * We will simply attempt a bind outgoing on our own IP.
     */
    newConn->remote.SetPort(0); // allow random outgoing port to prevent address clashes
    debugs(89, 5, HERE << "address TPROXY: " << newConn);
    return true;
#else
    return false;
#endif
}

bool
Ip::Intercept::IpfwInterception(const Comm::ConnectionPointer &newConn, int silent)
{
#if IPFW_TRANSPARENT
    struct sockaddr_storage lookup;
    socklen_t len = sizeof(struct sockaddr_storage);
    newConn->local.GetSockAddr(lookup, AF_INET);

    /** \par
     * Try lookup for IPFW interception. */
    if ( getsockname(newConn->fd, (struct sockaddr*)&lookup, &len) != 0 ) {
        if ( !silent ) {
            debugs(89, DBG_IMPORTANT, HERE << " IPFW getsockname(...) failed: " << xstrerror());
            lastReported_ = squid_curtime;
        }
        debugs(89, 9, HERE << "address: " << newConn);
        return false;
    } else {
        newConn->local = lookup;
        debugs(89, 5, HERE << "address NAT: " << newConn);
        return true;
    }
#endif
    return false;
}

bool
Ip::Intercept::IpfInterception(const Comm::ConnectionPointer &newConn, int silent)
{
#if IPF_TRANSPARENT  /* --enable-ipf-transparent */

