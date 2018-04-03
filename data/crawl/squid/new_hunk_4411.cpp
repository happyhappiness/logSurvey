}

static int
printRadixNode(struct squid_radix_node *rn, void *_sentry)
{
    StoreEntry *sentry = (StoreEntry *)_sentry;
    rtentry_t *e = (rtentry_t *) rn;
    List<int> *q;
    as_info *asinfo;
    char buf[MAX_IPSTRLEN];
    IPAddress addr;
    IPAddress mask;

    assert(e);
    assert(e->e_info);
    (void) get_m_ADDR(addr, e->e_addr);
    (void) get_m_ADDR(mask, e->e_mask);
    storeAppendPrintf(sentry, "%s/%d\t",
                      addr.NtoA(buf, MAX_IPSTRLEN),
                      mask.GetCIDR() );
    asinfo = e->e_info;
    assert(asinfo->as_number);

