        fatal(s.termedBuf());
    }

    {
        struct stat s;
        memset(&s, 0, sizeof(s));
        if (fstat(theFD, &s)) {
            debugs(54, 5, HERE << "fstat: " << xstrerror());
        String s = "Ipc::Mem::Segment::open failed to fstat";
        s.append(theName);
        fatal(s.termedBuf());
        }

        theSize = s.st_size;
    }

    debugs(54, 3, HERE << "opened " << theName << " segment: " << theSize);

