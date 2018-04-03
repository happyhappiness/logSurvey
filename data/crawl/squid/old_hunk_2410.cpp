    theFD = shm_open(theName.termedBuf(), O_RDWR, 0);
    if (theFD < 0) {
        debugs(54, 5, HERE << "shm_open " << theName << ": " << xstrerror());
        String s = "Ipc::Mem::Segment::open failed to shm_open ";
        s.append(theName);
        fatal(s.termedBuf());
    }

    theSize = statSize("Ipc::Mem::Segment::open");