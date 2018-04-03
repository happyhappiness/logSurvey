
        MemBuf wholeCtx;
        wholeCtx.init();
        wholeCtx.appendf("(%s lines)", name);
        wholeCtx.terminate();

        Acl::OrNode *newWhole = new Acl::OrNode;
