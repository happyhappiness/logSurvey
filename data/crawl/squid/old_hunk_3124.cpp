
    Ip::Address bnIPA = "2000:800::45";

    /* test stored values */
    CPPUNIT_ASSERT( !bnIPA.IsAnyAddr() );
    CPPUNIT_ASSERT( !bnIPA.IsNoAddr() );
