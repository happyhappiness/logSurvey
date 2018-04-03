    // update ICAP header
    icapBuf.Printf("%s=%d, ", section, (int) httpBuf.contentSize());

    // pack HTTP head
    packHead(httpBuf, head);
}

void ICAPModXact::packHead(MemBuf &httpBuf, const HttpMsg *head)
