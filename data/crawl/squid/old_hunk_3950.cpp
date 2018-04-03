    printf("Actual Text:\n");
    /* TODO: these should really be just [] lookups, but String doesn't have those here yet. */
    for ( int i = 0; i < anEntry->_appended_text.size(); i++) {
        CPPUNIT_ASSERT( expect.buf()[i] );
        CPPUNIT_ASSERT( anEntry->_appended_text.buf()[i] );

        /* slight hack to make special chars visible */
        switch (anEntry->_appended_text.buf()[i]) {
        case '\t':
            printf("\\t");
            break;
        default:
            printf("%c", anEntry->_appended_text.buf()[i] );
        }
        /* make this an int comparison, so that we can see the ASCII code at failure */
        CPPUNIT_ASSERT_EQUAL( (int)expect.buf()[i], (int)anEntry->_appended_text.buf()[i] );
    }
    printf("\n");
    CPPUNIT_ASSERT_EQUAL( expect, anEntry->_appended_text);
