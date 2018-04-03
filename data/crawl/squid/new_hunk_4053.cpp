    /* display a byte-by-byte hex comparison of the addr cores */
    unsigned int *p;
    p = (unsigned int*)expect;
    printf("\nSYS-ADDRINFO: %2x %2x %2x %2x %2x %2x",
           p[0],p[1],p[2],p[3],p[4],p[5]);

    p = (unsigned int*)ipval;
    printf("\nSQD-ADDRINFO: %2x %2x %2x %2x %2x %2x",
           p[0],p[1],p[2],p[3],p[4],p[5] );
    printf("\n");

