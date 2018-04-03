    switch(v)
    {
    case 1:
        storeAppendPrintf(e, "%s gre\n", label);
        break;
    case 2:
        storeAppendPrintf(e, "%s l2\n", label);
        break;
    default:
        debugs(80, DBG_CRITICAL, "FATAL: WCCPv2 confifigured method (" << v << ") is not valid.");
        self_destruct();
    }
}