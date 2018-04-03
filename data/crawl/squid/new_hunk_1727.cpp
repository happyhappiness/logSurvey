    Ip::Address bnIPA = "2000:800::45";

//char test[256];
//bnIPA.toStr(test, 256);
//printf("bnIPA: %s\n", test);

    /* test stored values */
    CPPUNIT_ASSERT( !bnIPA.isAnyAddr() );
    CPPUNIT_ASSERT( !bnIPA.isNoAddr() );
    CPPUNIT_ASSERT( !bnIPA.isIPv4() );
    CPPUNIT_ASSERT(  bnIPA.isIPv6() );
    CPPUNIT_ASSERT( !bnIPA.isSockAddr() );
    CPPUNIT_ASSERT_EQUAL( (unsigned short) 0 , bnIPA.port() );
    bnIPA.getInAddr(outval6);
    CPPUNIT_ASSERT( memcmp( &expectv6, &outval6, sizeof(struct in6_addr)) == 0 );

    /* test IPv6 as an old netmask format. This is invalid but sometimes use. */
