    addr = e->e_addr.addr;
    mask = e->e_mask.addr;
    storeAppendPrintf(sentry, "%s/%d\t",
                      addr.toStr(buf, MAX_IPSTRLEN),
                      mask.cidr() );
    asinfo = e->e_info;
    assert(asinfo->as_number);

