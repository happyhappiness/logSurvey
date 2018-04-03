    /* display a byte-by-byte hex comparison of the addr cores */
    unsigned int *p;
    p = (unsigned int*)expect;
    printf("\nSYS-ADDRINFO: %x %x %x %x %x %x ",
		  p[0],p[1],p[2],p[3],p[4],p[5] );

    p = (unsigned int*)ipval;
    printf("\nSQD-ADDRINFO: %x %x %x %x %x %x ",
		  p[0],p[1],p[2],p[3],p[4],p[5] );
    printf("\n");

    // check the addrinfo object core. (BUT not the two ptrs at the tail)
    // details
    CPPUNIT_ASSERT_EQUAL( expect->ai_flags, ipval->ai_flags );
    CPPUNIT_ASSERT_EQUAL( expect->ai_family, ipval->ai_family );
    // check the sockaddr it points to.
    CPPUNIT_ASSERT_EQUAL( expect->ai_addrlen, ipval->ai_addrlen );
    CPPUNIT_ASSERT( memcmp( expect->ai_addr, ipval->ai_addr, expect->ai_addrlen ) == 0 );

    xfreeaddrinfo(expect);
}