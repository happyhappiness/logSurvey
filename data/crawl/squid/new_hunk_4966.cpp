void
MemObject::stat (MemBuf * mb) const
{
    mb->Printf("\t%s %s\n",
               RequestMethodStr[method], log_url);
    mb->Printf("\tinmem_lo: %d\n", (int) inmem_lo);
    mb->Printf("\tinmem_hi: %d\n", (int) data_hdr.endOffset());
    mb->Printf("\tswapout: %d bytes queued\n",
               (int) swapout.queue_offset);

    if (swapout.sio.getRaw())
        mb->Printf("\tswapout: %d bytes written\n",
                   (int) swapout.sio->offset());

    StoreClientStats statsVisitor(mb);

