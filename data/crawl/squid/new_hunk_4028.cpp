#if 0
    p = (unsigned int*)(expect->ai_addr);
    printf("\nSYS-ADDR: (%d)  %x %x %x %x %x %x %x %x ...",
           expect->ai_addrlen,
           p[0],p[1],p[2],p[3],p[4],p[5],p[6],p[7] );

    p = (unsigned int*)(ipval->ai_addr);
    printf("\nSQD-ADDR: (%d) %x %x %x %x %x %x %x %x ...",
           ipval->ai_addrlen,
           p[0],p[1],p[2],p[3],p[4],p[5],p[6],p[7] );
    printf("\n");
#if HAVE_SS_LEN_IN_SS
