void
Ip::Intercept::StopTransparency(const char *str)
{
    if (transparent_active) {
        debugs(89, DBG_IMPORTANT, "Stopping full transparency: " << str);
        transparent_active = 0;
    }
}

void
Ip::Intercept::StopInterception(const char *str)
{
    if (intercept_active) {
        debugs(89, DBG_IMPORTANT, "Stopping IP interception: " << str);
        intercept_active = 0;
    }
}

int
Ip::Intercept::NetfilterInterception(int fd, const Ip::Address &me, Ip::Address &dst, int silent)
{
#if LINUX_NETFILTER
    struct addrinfo *lookup = NULL;

    dst.GetAddrInfo(lookup,AF_INET);

    /** \par
     * Try NAT lookup for REDIRECT or DNAT targets. */
    if ( getsockopt(fd, IPPROTO_IP, SO_ORIGINAL_DST, lookup->ai_addr, &lookup->ai_addrlen) != 0) {
        if (!silent) {
            debugs(89, DBG_IMPORTANT, HERE << " NF getsockopt(SO_ORIGINAL_DST) failed on FD " << fd << ": " << xstrerror());
            last_reported = squid_curtime;
        }
    } else {
        dst = *lookup;
    }

    Address::FreeAddrInfo(lookup);

    if (me != dst) {
        debugs(89, 5, HERE << "address NAT: me= " << me << ", dst= " << dst);
        return 0;
    }

    debugs(89, 9, HERE << "address: me= " << me << ", dst= " << dst);
#endif
    return -1;
}

int
Ip::Intercept::NetfilterTransparent(int fd, const Ip::Address &me, Ip::Address &client, int silent)
{
#if LINUX_NETFILTER

    /* Trust the user configured properly. If not no harm done.
     * We will simply attempt a bind outgoing on our own IP.
     */
    if (fd_table[fd].flags.transparent) {
        client.SetPort(0); // allow random outgoing port to prevent address clashes
        debugs(89, 5, HERE << "address TPROXY: me= " << me << ", client= " << client);
        return 0;
    }

    debugs(89, 9, HERE << "address: me= " << me << ", client= " << client);
#endif
    return -1;
}

int
Ip::Intercept::IpfwInterception(int fd, const Ip::Address &me, Ip::Address &dst, int silent)
{
#if IPFW_TRANSPARENT
    struct addrinfo *lookup = NULL;

    dst.GetAddrInfo(lookup,AF_INET);

    /** \par
     * Try lookup for IPFW interception. */
    if ( getsockname(fd, lookup->ai_addr, &lookup->ai_addrlen) != 0 ) {
        if ( !silent ) {
            debugs(89, DBG_IMPORTANT, HERE << " IPFW getsockname(...) failed: " << xstrerror());
            last_reported = squid_curtime;
        }
    } else {
        dst = *lookup;
    }

    Address::FreeAddrInfo(lookup);

    if (me != dst) {
        debugs(89, 5, HERE << "address NAT: me= " << me << ", dst= " << dst);
        return 0;
    }

    debugs(89, 9, HERE << "address: me= " << me << ", dst= " << dst);
#endif
    return -1;
}

int
Ip::Intercept::IpfInterception(int fd, const Ip::Address &me, Ip::Address &client, Ip::Address &dst, int silent)
{
#if IPF_TRANSPARENT  /* --enable-ipf-transparent */

