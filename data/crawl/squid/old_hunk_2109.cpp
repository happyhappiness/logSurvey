    kargs[kend-kstart]=NULL;
    if (debug) {
        fprintf(stderr, "%s| %s: Kerberos command: ", LogTime(), PROGRAM);
        for (i=0; i<kend-kstart; i++)
            fprintf(stderr, "%s ", kargs[i]);
        fprintf(stderr, "\n");
    }
