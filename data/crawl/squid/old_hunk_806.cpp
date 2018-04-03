
    MemBuf lineCtx;
    lineCtx.init();
    lineCtx.Printf("(%s line #%d)", name, lineId);
    lineCtx.terminate();

    Acl::AndNode *line = new AndNode;
