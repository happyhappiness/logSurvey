        mb->Printf("\tswapout: %" PRId64 " bytes written\n",
                   (int64_t) swapout.sio->offset());

    StoreClientStats statsVisitor(mb);

    for_each<StoreClientStats>(clients, statsVisitor);
