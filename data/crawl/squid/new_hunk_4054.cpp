    CPPUNIT_ASSERT_EQUAL( expect->ai_family, ipval->ai_family );
    // check the sockaddr it points to.
    CPPUNIT_ASSERT_EQUAL( expect->ai_addrlen, ipval->ai_addrlen );
    p = (unsigned int*)(expect->ai_addr);
    printf("\nSYS-ADDR: (%d)  %2x %2x %2x %2x %2x %2x %2x %2x",
            expect->ai_addrlen,
           p[0],p[1],p[2],p[3],p[4],p[5],p[6],p[7] );

    p = (unsigned int*)(ipval->ai_addr);
    printf("\nSQD-ADDR: (%d) %2x %2x %2x %2x %2x %2x %2x %2x",
            ipval->ai_addrlen,
           p[0],p[1],p[2],p[3],p[4],p[5],p[6],p[7] );
    printf("\n");

#if USE_IPV6
#if HAVE_SS_LEN_IN_SS
    printf("\nSYS SS_LEN=%d\nSQD SS_LEN=%d\n",((struct sockaddr_storage*)expect->ai_addr)->ss_len,
           ((struct sockaddr_storage*)ipval->ai_addr)->ss_len );
    CPPUNIT_ASSERT_EQUAL( ((struct sockaddr_storage*)expect->ai_addr)->ss_len,
                          ((struct sockaddr_storage*)ipval->ai_addr)->ss_len );
    CPPUNIT_ASSERT_EQUAL( (socklen_t)((struct sockaddr_storage*)ipval->ai_addr)->ss_len, ipval->ai_addrlen );
#endif
#if HAVE_SIN6_LEN_IN_SAI
    CPPUNIT_ASSERT_EQUAL( ((struct sockaddr_in6*)expect->ai_addr)->sin6_len,
                          ((struct sockaddr_in6*)ipval->ai_addr)->sin6_len );
    CPPUNIT_ASSERT_EQUAL( (socklen_t)((struct sockaddr_in6*)ipval->ai_addr)->sin6_len, ipval->ai_addrlen );
#endif
    CPPUNIT_ASSERT_EQUAL( ((struct sockaddr_in6*)expect->ai_addr)->sin6_family,
                          ((struct sockaddr_in6*)ipval->ai_addr)->sin6_family );
    CPPUNIT_ASSERT_EQUAL( ((struct sockaddr_in6*)expect->ai_addr)->sin6_port,
                          ((struct sockaddr_in6*)ipval->ai_addr)->sin6_port );
#else
#if HAVE_SS_LEN_IN_SS
    printf("\nSYS SS_LEN=%d\nSQD SS_LEN=%d\n",((struct sockaddr_storage*)expect->ai_addr)->ss_len,
           ((struct sockaddr_storage*)ipval->ai_addr)->ss_len );
    CPPUNIT_ASSERT_EQUAL( ((struct sockaddr_storage*)expect->ai_addr)->ss_len,
                          ((struct sockaddr_storage*)ipval->ai_addr)->ss_len );
    CPPUNIT_ASSERT_EQUAL( (socklen_t)((struct sockaddr_storage*)ipval->ai_addr)->ss_len, ipval->ai_addrlen );
#endif
#if HAVE_SIN_LEN_IN_SAI
    CPPUNIT_ASSERT_EQUAL( ((struct sockaddr_in*)expect->ai_addr)->sin_len,
                          ((struct sockaddr_in*)ipval->ai_addr)->sin_len );
    CPPUNIT_ASSERT_EQUAL( (socklen_t)((struct sockaddr_in*)ipval->ai_addr)->sin_len, ipval->ai_addrlen );
#endif
    CPPUNIT_ASSERT_EQUAL( ((struct sockaddr_in*)expect->ai_addr)->sin_family,
                          ((struct sockaddr_in*)ipval->ai_addr)->sin_family );
    CPPUNIT_ASSERT_EQUAL( ((struct sockaddr_in*)expect->ai_addr)->sin_port,
                          ((struct sockaddr_in*)ipval->ai_addr)->sin_port );
#endif /* USE_IPV6 */

    CPPUNIT_ASSERT( memcmp( expect->ai_addr, ipval->ai_addr, expect->ai_addrlen ) == 0 );

    xfreeaddrinfo(expect);