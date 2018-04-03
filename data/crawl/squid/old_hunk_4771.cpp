    EventLoop();
    /* register an event dispatcher to be invoked on each event loop. */
    void registerDispatcher(CompletionDispatcher *dispatcher);
    /* start the event loop running */
    void run();
    /* run the loop once. This may not complete all events! It should therefor
     * be used with care.
     * TODO: signal in runOnce whether or not the loop is over - IDLE vs OK vs
     * TIMEOUT?
     */
    void runOnce();
    /* stop the event loop - it will finish the current loop and then return to the
     * caller of run().
     */
    void stop();

private:
    /* setup state variables prior to running */
    void prepareToRun();
    int errcount;
    bool last_loop;
    typedef Vector<CompletionDispatcher *> dispatcher_vector;
    dispatcher_vector dispatchers;
};


