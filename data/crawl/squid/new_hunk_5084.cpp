
struct StoreClientStats : public unary_function<store_client, void>
{
    StoreClientStats(MemBuf *anEntry):where(anEntry),index(0){}

    void operator()(store_client const &x)
    {
        x.dumpStats(where, index++);
    }

    MemBuf *where;
    size_t index;
};

void
MemObject::stat (MemBuf * mb) const
{
    memBufPrintf(mb, "\t%s %s\n",
                 RequestMethodStr[method], log_url);
    memBufPrintf(mb, "\tinmem_lo: %d\n", (int) inmem_lo);
    memBufPrintf(mb, "\tinmem_hi: %d\n", (int) data_hdr.endOffset());
    memBufPrintf(mb, "\tswapout: %d bytes queued\n",
                 (int) swapout.queue_offset);

    if (swapout.sio.getRaw())
        memBufPrintf(mb, "\tswapout: %d bytes written\n",
                     (int) swapout.sio->offset());

    StoreClientStats statsVisitor(mb);

    for_each<StoreClientStats>(clients, statsVisitor);
}
