    CalledEvent event;
    CalledEvent event2;
    CapturingStoreEntry * anEntry = new CapturingStoreEntry();
    String expect =  "Last event to run: last event\n"
                     "\n"
                     "Operation                \tNext Execution \tWeight\tCallback Valid?\n"
                     "test event               \t0.000 sec\t    0\t N/A\n"
                     "test event2              \t0.000 sec\t    0\t N/A\n"
                     ;

    scheduler.schedule("last event", CalledEvent::Handler, &event, 0, 0, false);

    /* schedule and dispatch to set the last run event */
    scheduler.checkEvents(0);
    dispatcher.dispatch();
    scheduler.schedule("test event", CalledEvent::Handler, &event, 0, 0, false);
    scheduler.schedule("test event2", CalledEvent::Handler, &event2, 0, 0, false);
    scheduler.dump(anEntry);

    /* loop over the strings, showing exactly where they differ (if at all) */
    printf("Actual Text:\n");
    /* TODO: these should really be just [] lookups, but String doesn't have those here yet. */
    for( int i = 0; i < anEntry->_appended_text.size(); i++) {
        CPPUNIT_ASSERT( expect.buf()[i] );
        CPPUNIT_ASSERT( anEntry->_appended_text.buf()[i] );

        /* slight hack to make special chars visible */
        switch(anEntry->_appended_text.buf()[i])
        {
        case '\t':
            printf("\\t"); break;
        default:
            printf("%c", anEntry->_appended_text.buf()[i] );
        }
        /* make this an int comparison, so that we can see the ASCII code at failure */
        CPPUNIT_ASSERT_EQUAL( (int)expect.buf()[i], (int)anEntry->_appended_text.buf()[i] );
    }
    printf("\n");
    CPPUNIT_ASSERT_EQUAL( expect, anEntry->_appended_text);

    /* cleanup */
    delete anEntry;
}

