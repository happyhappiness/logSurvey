
    MemBuf lineCtx;
    lineCtx.init();
    lineCtx.appendf("(%s line #%d)", name, lineId);
    lineCtx.terminate();

    Acl::AndNode *line = new AndNode;
