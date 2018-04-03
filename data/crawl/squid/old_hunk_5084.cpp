
struct StoreClientStats : public unary_function<store_client, void>
{
    StoreClientStats(StoreEntry *anEntry):where(anEntry),index(0){}

    void operator()(store_client const &x)
    {
        x.dumpStats(where, index++);
    }

    StoreEntry *where;
    size_t index;
};

void
MemObject::stat (StoreEntry *s) const
{
    storeAppendPrintf(s, "\t%s %s\n",
                      RequestMethodStr[method], log_url);
    storeAppendPrintf(s, "\tinmem_lo: %d\n", (int) inmem_lo);
    storeAppendPrintf(s, "\tinmem_hi: %d\n", (int) data_hdr.endOffset());
    storeAppendPrintf(s, "\tswapout: %d bytes queued\n",
                      (int) swapout.queue_offset);

    if (swapout.sio.getRaw())
        storeAppendPrintf(s, "\tswapout: %d bytes written\n",
                          (int) swapout.sio->offset());

    StoreClientStats statsVisitor(s);

    for_each<StoreClientStats>(clients, statsVisitor);
}
