    // traffic will be redirected to us.
    MemBuf mb;
    mb.init();
    mb.Printf("229 Entering Extended Passive Mode (|||%u|)\r\n", localPort);

    debugs(9, 3, Raw("writing", mb.buf, mb.size));
    writeReply(mb);
