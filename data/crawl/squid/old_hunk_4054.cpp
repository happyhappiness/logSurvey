    CPPUNIT_ASSERT_EQUAL( expect->ai_family, ipval->ai_family );
    // check the sockaddr it points to.
    CPPUNIT_ASSERT_EQUAL( expect->ai_addrlen, ipval->ai_addrlen );
    CPPUNIT_ASSERT( memcmp( expect->ai_addr, ipval->ai_addr, expect->ai_addrlen ) == 0 );

    xfreeaddrinfo(expect);