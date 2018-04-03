    usermap.clear();
    //TODO: change to c++ streams
    f = fopen(passwdfile, "r");
    if (!f) {
        int xerrno = errno;
        fprintf(stderr, "FATAL: %s: %s\n", passwdfile, xstrerr(xerrno));
        exit(1);
    }
    unsigned int lineCount = 0;
