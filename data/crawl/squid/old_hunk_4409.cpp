void
ACLIP::DumpIpListWalkee(acl_ip_data * const & ip, void *state)
{
    MemBuf mb;
    wordlist **W = static_cast<wordlist **>(state);
    mb.init();
    mb.Printf("%s", inet_ntoa(ip->addr1));

    if (ip->addr2.s_addr != any_addr.s_addr)
        mb.Printf("-%s", inet_ntoa(ip->addr2));

    if (ip->mask.s_addr != no_addr.s_addr)
        mb.Printf("/%s", inet_ntoa(ip->mask));

    wordlistAdd(W, mb.buf);

