
    diskdinfo->smsgid = msgget((key_t) ikey, 0700 | IPC_CREAT);
    if (diskdinfo->smsgid < 0) {
        debug(50, 0) ("storeDiskdInit: msgget: %s\n", xstrerror());
        fatal("msgget failed");
    }
    diskdinfo->rmsgid = msgget((key_t) (ikey + 1), 0700 | IPC_CREAT);
    if (diskdinfo->rmsgid < 0) {
        debug(50, 0) ("storeDiskdInit: msgget: %s\n", xstrerror());
        fatal("msgget failed");
    }
    diskdinfo->shm.id = shmget((key_t) (ikey + 2),
        SHMBUFS * SHMBUF_BLKSZ, 0600 | IPC_CREAT);
    if (diskdinfo->shm.id < 0) {
        debug(50, 0) ("storeDiskdInit: shmget: %s\n", xstrerror());
        fatal("shmget failed");
    }
    diskdinfo->shm.buf = shmat(diskdinfo->shm.id, NULL, 0);
    if (diskdinfo->shm.buf == (void *) -1) {
        debug(50, 0) ("storeDiskdInit: shmat: %s\n", xstrerror());
        fatal("shmat failed");
    }
    diskd_stats.shmbuf_count += SHMBUFS;
    for (i = 0; i < SHMBUFS; i++)
        storeDiskdShmPut(sd, i * SHMBUF_BLKSZ);
    snprintf(skey1, 32, "%d", ikey);
    snprintf(skey2, 32, "%d", ikey + 1);
    snprintf(skey3, 32, "%d", ikey + 2);
