                     S_IRUSR | S_IWUSR);
    if (theFD < 0) {
        debugs(54, 5, HERE << "shm_open " << theName << ": " << xstrerror());
        fatal("Ipc::Mem::Segment::create failed to shm_open");
    }

    if (ftruncate(theFD, aSize)) {
