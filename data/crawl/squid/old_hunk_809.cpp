
    MemBuf ctxTree;
    ctxTree.init();
    ctxTree.Printf("%s %s", cfg_directive, label);
    ctxTree.terminate();

    // We want a cbdata-protected Tree (despite giving it only one child node).
