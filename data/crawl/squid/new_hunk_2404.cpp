
    if (ftruncate(theFD, aSize)) {
        debugs(54, 5, HERE << "ftruncate " << theName << ": " << xstrerror());
        fatalf("Ipc::Mem::Segment::create failed to ftruncate(%s): %s\n",
               theName.termedBuf(), xstrerror());
    }

    assert(statSize("Ipc::Mem::Segment::create") == aSize); // paranoid
