    /* loop over the strings, showing exactly where they differ (if at all) */
    printf("Actual Text:\n");
    /* TODO: these should really be just [] lookups, but String doesn't have those here yet. */
    for ( int i = 0; i < anEntry->_appended_text.size(); i++) {
        CPPUNIT_ASSERT( expect[i] );
        CPPUNIT_ASSERT( anEntry->_appended_text[i] );

