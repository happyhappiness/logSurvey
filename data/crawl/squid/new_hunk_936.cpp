
    MemBuf ctxLine;
    ctxLine.init();
    ctxLine.appendf("(%s %s line)", cfg_directive, label);
    ctxLine.terminate();

    Acl::AndNode *rule = new Acl::AndNode;
