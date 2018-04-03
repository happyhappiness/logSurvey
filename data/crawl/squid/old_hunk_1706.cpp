    addr = e->e_addr.addr;
    mask = e->e_mask.addr;
    storeAppendPrintf(sentry, "%s/%d\t",
                      addr.NtoA(buf, MAX_IPSTRLEN),
                      mask.GetCIDR() );
    asinfo = e->e_info;
    assert(asinfo->as_number);

