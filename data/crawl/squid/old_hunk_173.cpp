    smsgid = msgget((key_t) ikey, 0700 | IPC_CREAT);

    if (smsgid < 0) {
        debugs(50, DBG_CRITICAL, "storeDiskdInit: msgget: " << xstrerror());
        fatal("msgget failed");
    }

    rmsgid = msgget((key_t) (ikey + 1), 0700 | IPC_CREAT);

    if (rmsgid < 0) {
        debugs(50, DBG_CRITICAL, "storeDiskdInit: msgget: " << xstrerror());
        fatal("msgget failed");
    }

