
        MemBuf wholeCtx;
        wholeCtx.init();
        wholeCtx.Printf("(%s lines)", name);
        wholeCtx.terminate();

        Acl::OrNode *newWhole = new Acl::OrNode;
