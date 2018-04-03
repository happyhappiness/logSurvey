                nbufs * SHMBUF_BLKSZ, 0600 | IPC_CREAT);

    if (id < 0) {
        debugs(50, DBG_CRITICAL, "storeDiskdInit: shmget: " << xstrerror());
        fatal("shmget failed");
    }

    buf = (char *)shmat(id, NULL, 0);

    if (buf == (void *) -1) {
        debugs(50, DBG_CRITICAL, "storeDiskdInit: shmat: " << xstrerror());
        fatal("shmat failed");
    }

