}

void
Ipc::Mem::Segment::open()
{
    assert(theFD < 0);

    theFD = shm_open(theName.termedBuf(), O_RDWR, 0);
    if (theFD < 0) {
        debugs(54, 5, HERE << "shm_open: " << xstrerror());
        String s = "Ipc::Mem::Segment::open failed to shm_open";
        s.append(theName);
        fatal(s.termedBuf());
    }
