    fatal ("ACLIP::operator delete: unused");
}

void
ACLIP::DumpIpListWalkee(acl_ip_data * const & ip, void *state)
{
    char tmpbuf[MAX_IPSTRLEN];
    MemBuf mb;
    wordlist **W = static_cast<wordlist **>(state);
    mb.init();
    mb.Printf("%s", ip->addr1.NtoA(tmpbuf,MAX_IPSTRLEN));

    if (!ip->addr2.IsAnyAddr())
        mb.Printf("-%s", ip->addr2.NtoA(tmpbuf,MAX_IPSTRLEN));

    if (!ip->mask.IsNoAddr())
        mb.Printf("/%s", ip->mask.NtoA(tmpbuf,MAX_IPSTRLEN));

    wordlistAdd(W, mb.buf);

    mb.clean();
}

/*
 * aclIpDataToStr - print/format an acl_ip_data structure for
 * debugging output.
 */
void
acl_ip_data::toStr(char *buf, int len) const
