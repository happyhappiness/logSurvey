
    if (ftruncate(theFD, aSize)) {
        debugs(54, 5, HERE << "ftruncate " << theName << ": " << xstrerror());
        fatal("Ipc::Mem::Segment::create failed to ftruncate");
    }

    assert(statSize("Ipc::Mem::Segment::create") == aSize); // paranoid
