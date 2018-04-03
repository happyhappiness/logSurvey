    memset(&s, 0, sizeof(s));

    if (fstat(theFD, &s) != 0) {
        debugs(54, 5, HERE << "fstat " << theName << ": " << xstrerror());
        String s = context;
        s.append("failed to fstat(2) ");
        s.append(theName);
        fatal(s.termedBuf());
    }

    return s.st_size;
