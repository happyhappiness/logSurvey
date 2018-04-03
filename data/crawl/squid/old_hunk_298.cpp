    usermap.clear();
    //TODO: change to c++ streams
    f = fopen(passwdfile, "r");
    if (NULL == f) {
        fprintf(stderr, "FATAL: %s: %s\n", passwdfile, xstrerror());
        exit(1);
    }
    unsigned int lineCount = 0;
