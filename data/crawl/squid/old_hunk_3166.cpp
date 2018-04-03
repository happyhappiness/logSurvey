
    if (use_global) {
        if ((machinedomain = GetDomainName()) == NULL) {
            fprintf(stderr, "%s Can't read machine domain\n", myname);
            exit(1);
        }
        strlwr(machinedomain);
