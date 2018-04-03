    memset(&s, 0, sizeof(s));

    if (fstat(theFD, &s) != 0) {
        int xerrno = errno;
        debugs(54, 5, context << " fstat " << theName << ": " << xstrerr(xerrno));
        fatalf("Ipc::Mem::Segment::statSize: %s failed to fstat(%s): %s\n",
               context, theName.termedBuf(), xstrerr(xerrno));
    }

    return s.st_size;
