    EventLoop();
    /* register an event dispatcher to be invoked on each event loop. */
    void registerDispatcher(CompletionDispatcher *dispatcher);
    /* register an async engine which will be given the opportunity to perform
     * in-main-thread tasks each event loop.
     */
    void registerEngine(AsyncEngine *engine);
    /* start the event loop running. The loop will run until it is stopped by
     * calling stop(), or when the loop is completely idle - nothing 
     * dispatched in a loop, and all engines idle.
     */
    void run();
    /* run the loop once. This may not complete all events! It should therefor
     * be used with care.
     * TODO: signal in runOnce whether or not the loop is over - IDLE vs OK vs
     * TIMEOUT?
     */
    bool runOnce();
    /* set the time service. There can be only one time service set at any
     * time. The time service is invoked on each loop 
     */
    void setTimeService(TimeEngine *engine);
    /* stop the event loop - it will finish the current loop and then return to the
     * caller of run().
     */
    void stop();

    int errcount;

private:
    /* setup state variables prior to running */
    void prepareToRun();
    bool last_loop;
    typedef Vector<CompletionDispatcher *> dispatcher_vector;
    dispatcher_vector dispatchers;
    typedef Vector<AsyncEngine *> engine_vector;
    engine_vector engines;
    TimeEngine * timeService;
};


