    /* display a byte-by-byte hex comparison of the addr cores */
    unsigned int *p;
    p = (unsigned int*)expect;
    printf("\nADDRINFO: %x %x %x %x %x %x ",
		  p[0],p[1],p[2],p[3],p[4],p[5] );

    p = (unsigned int*)ipval;
    printf("\nADDRINFO: %x %x %x %x %x %x ",
		  p[0],p[1],p[2],p[3],p[4],p[5] );
    printf("\n");

    // check the addrinfo object core. (BUT not the two ptrs at the tail)
    CPPUNIT_ASSERT( memcmp( expect, ipval, sizeof(struct addrinfo)-(sizeof(void*)*3) ) == 0 );
    // check the sockaddr it points to.
    CPPUNIT_ASSERT_EQUAL( expect->ai_addrlen, ipval->ai_addrlen );
    CPPUNIT_ASSERT( memcmp( expect, ipval, expect->ai_addrlen ) == 0 );

    xfreeaddrinfo(expect);
}