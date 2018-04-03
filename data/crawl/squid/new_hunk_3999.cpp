    printf("Actual Text:\n");
    /* TODO: these should really be just [] lookups, but String doesn't have those here yet. */
    for ( int i = 0; i < anEntry->_appended_text.size(); i++) {
        CPPUNIT_ASSERT( expect.unsafeBuf()[i] );
        CPPUNIT_ASSERT( anEntry->_appended_text.unsafeBuf()[i] );

        /* slight hack to make special chars visible */
        switch (anEntry->_appended_text.unsafeBuf()[i]) {
        case '\t':
            printf("\\t");
            break;
        default:
            printf("%c", anEntry->_appended_text.unsafeBuf()[i] );
        }
        /* make this an int comparison, so that we can see the ASCII code at failure */
        CPPUNIT_ASSERT_EQUAL( (int)expect.unsafeBuf()[i], (int)anEntry->_appended_text.unsafeBuf()[i] );
    }
    printf("\n");
    CPPUNIT_ASSERT_EQUAL( expect, anEntry->_appended_text);
