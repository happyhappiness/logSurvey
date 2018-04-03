}

void
SharedMemory::open()
{
    assert(theFD < 0);

    theFD = shm_open(theName.termedBuf(), O_RDWR, 0);
    if (theFD < 0) {
        debugs(54, 5, "SharedMemory::open: shm_open: " << xstrerror());
        String s = "SharedMemory::open failed 1 ";
        s.append(theName);
        fatal(s.termedBuf());
    }
