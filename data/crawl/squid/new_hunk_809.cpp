
    MemBuf ctxTree;
    ctxTree.init();
    ctxTree.appendf("%s %s", cfg_directive, label);
    ctxTree.terminate();

    // We want a cbdata-protected Tree (despite giving it only one child node).
