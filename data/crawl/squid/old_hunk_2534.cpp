                          ((struct sockaddr_in*)ipval->ai_addr)->sin_len );
    CPPUNIT_ASSERT_EQUAL( (socklen_t)((struct sockaddr_in*)ipval->ai_addr)->sin_len, ipval->ai_addrlen );
#endif
    CPPUNIT_ASSERT_EQUAL( ((struct sockaddr_in6*)expect->ai_addr)->sin6_family,
                          ((struct sockaddr_in6*)ipval->ai_addr)->sin6_family );
    CPPUNIT_ASSERT_EQUAL( ((struct sockaddr_in6*)expect->ai_addr)->sin6_port,
                          ((struct sockaddr_in6*)ipval->ai_addr)->sin6_port );

    CPPUNIT_ASSERT( memcmp( expect->ai_addr, ipval->ai_addr, expect->ai_addrlen ) == 0 );
