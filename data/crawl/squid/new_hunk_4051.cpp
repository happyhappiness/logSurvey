    printf("\nSQD-ADDRINFO: %2x %2x %2x %2x %2x %2x",
           p[0],p[1],p[2],p[3],p[4],p[5] );
    printf("\n");
#endif /*0*/

    // check the addrinfo object core. (BUT not the two ptrs at the tail)
    // details
    CPPUNIT_ASSERT_EQUAL( expect->ai_flags, ipval->ai_flags );
    CPPUNIT_ASSERT_EQUAL( expect->ai_family, ipval->ai_family );
    // check the sockaddr it points to.
    CPPUNIT_ASSERT_EQUAL( expect->ai_addrlen, ipval->ai_addrlen );

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
    printf("\nSYS SS_LEN=%d\nSQD SS_LEN=%d\n",((struct sockaddr_storage*)expect->ai_addr)->ss_len,
           ((struct sockaddr_storage*)ipval->ai_addr)->ss_len );
#endif
#endif /*0*/

#if USE_IPV6
#if HAVE_SS_LEN_IN_SS
    CPPUNIT_ASSERT_EQUAL( ((struct sockaddr_storage*)expect->ai_addr)->ss_len,
                          ((struct sockaddr_storage*)ipval->ai_addr)->ss_len );
    CPPUNIT_ASSERT_EQUAL( (socklen_t)((struct sockaddr_storage*)ipval->ai_addr)->ss_len, ipval->ai_addrlen );
