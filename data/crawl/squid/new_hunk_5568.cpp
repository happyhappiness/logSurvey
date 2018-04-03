{
    MemObject *mem = e->mem_obj;
    int i;
    dlink_node *node;
    storeAppendPrintf(s, "KEY %s\n", storeKeyText(e->hash.key));
    if (mem)
