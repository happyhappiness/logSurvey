    Ip::Address bnIPA = "2000:800::45";

//char test[256];
//bnIPA.NtoA(test, 256);
//printf("bnIPA: %s\n", test);

    /* test stored values */
    CPPUNIT_ASSERT( !bnIPA.IsAnyAddr() );
    CPPUNIT_ASSERT( !bnIPA.IsNoAddr() );
    CPPUNIT_ASSERT( !bnIPA.IsIPv4() );
    CPPUNIT_ASSERT(  bnIPA.IsIPv6() );
    CPPUNIT_ASSERT( !bnIPA.IsSockAddr() );
    CPPUNIT_ASSERT_EQUAL( (unsigned short) 0 , bnIPA.GetPort() );
    bnIPA.GetInAddr(outval6);
    CPPUNIT_ASSERT( memcmp( &expectv6, &outval6, sizeof(struct in6_addr)) == 0 );

    /* test IPv6 as an old netmask format. This is invalid but sometimes use. */
