    CPPUNIT_ASSERT_EQUAL( expect->ai_addrlen, ipval->ai_addrlen );

#if 0
    printf("sizeof IN(%d), IN6(%d), STORAGE(%d), \n",
           sizeof(struct sockaddr_in), sizeof(struct sockaddr_in6), sizeof(struct sockaddr_storage));

    p = (unsigned int*)(expect->ai_addr);
    printf("\nSYS-ADDR: (%d) {%d} %x %x %x %x %x %x %x %x ...",
           expect->ai_addrlen, sizeof(*p),
           p[0],p[1],p[2],p[3],p[4],p[5],p[6],p[7] );

    p = (unsigned int*)(ipval->ai_addr);
    printf("\nSQD-ADDR: (%d) {%d} %x %x %x %x %x %x %x %x ...",
           ipval->ai_addrlen, sizeof(*p),
           p[0],p[1],p[2],p[3],p[4],p[5],p[6],p[7] );
    printf("\n");
#if HAVE_SS_LEN_IN_SS
