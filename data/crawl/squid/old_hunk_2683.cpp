        struct stat s;
        memset(&s, 0, sizeof(s));
        if (fstat(theFD, &s)) {
            debugs(54, 5, "SharedMemory::open: fstat: " << xstrerror());
        String s = "SharedMemory::open failed 2 ";
        s.append(theName);
        fatal(s.termedBuf());
        }
