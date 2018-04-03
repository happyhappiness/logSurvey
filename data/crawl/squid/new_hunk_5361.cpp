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

    for_each(clients, statsVisitor);
}

