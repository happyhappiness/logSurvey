
    if (munmap(theMem, theSize)) {
        debugs(54, 5, HERE << "munmap " << theName << ": " << xstrerror());
        fatal("Ipc::Mem::Segment::detach failed to munmap");
    }
    theMem = 0;
}
