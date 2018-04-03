    CalledEvent event;
    CalledEvent event2;
    CapturingStoreEntry * anEntry = new CapturingStoreEntry();
    scheduler.schedule("last event", CalledEvent::Handler, &event, 0, 0, false);
    /* schedule and dispatch to set the last run event */
    scheduler.checkEvents(0);
    dispatcher.dispatch();
    scheduler.schedule("test event", CalledEvent::Handler, &event, 0, 0, false);
    scheduler.schedule("test event2", CalledEvent::Handler, &event2, 0, 0, false);
    scheduler.dump(anEntry);
    CPPUNIT_ASSERT_EQUAL(String(
                             "Last event to run: last event\n"
                             "\n"
                             "Operation\tNext Execution\tWeight\tCallback Valid?\n"
                             "test event\t0.000000 seconds\t0\tN/A\n"
                             "test event2\t0.000000 seconds\t0\tN/A\n"
                         ), anEntry->_appended_text);
    delete anEntry;
}

