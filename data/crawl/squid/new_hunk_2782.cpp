    theFD = shm_open(theName.termedBuf(), O_RDWR, 0);
    if (theFD < 0) {
        debugs(54, 5, "SharedMemory::open: shm_open: " << xstrerror());
        String s = "SharedMemory::open failed 1 ";
        s.append(theName);
        fatal(s.termedBuf());
    }

    {
        struct stat s;
        memset(&s, 0, sizeof(s));
        if (fstat(theFD, &s)) {
            debugs(54, 5, "SharedMemory::open: fstat: " << xstrerror());
        String s = "SharedMemory::open failed 2 ";
        s.append(theName);
        fatal(s.termedBuf());
        }

        theSize = s.st_size;
