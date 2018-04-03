    theFD = shm_open(theName.termedBuf(), O_RDWR, 0);
    if (theFD < 0) {
        debugs(54, 5, "SharedMemory::open: shm_open: " << xstrerror());
        fatal("SharedMemory::open failed");
    }

    {
        struct stat s;
        memset(&s, 0, sizeof(s));
        if (fstat(theFD, &s)) {
            debugs(54, 5, "SharedMemory::open: fstat: " << xstrerror());
            fatal("SharedMemory::open failed");
        }

        theSize = s.st_size;
