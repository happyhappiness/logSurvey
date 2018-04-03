    /* TODO: stop requiring the singleton here */
    mainLoop.registerDispatcher(EventDispatcher::GetInstance());

    /* TODO: stop requiring the singleton here */
    mainLoop.registerEngine(EventScheduler::GetInstance());

    StoreRootEngine store_engine;

    mainLoop.registerEngine(&store_engine);

    CommDispatcher comm_dispatcher;

    mainLoop.registerDispatcher(&comm_dispatcher);

    CommSelectEngine comm_engine;

    /* must be last - its the only engine that implements timeouts properly
     * at the moment.
     */
    mainLoop.registerEngine(&comm_engine);

    /* use the standard time service */
    TimeEngine time_engine;

    mainLoop.setTimeService(&time_engine);

    mainLoop.run();

    if (mainLoop.errcount == 10)
        fatal_dump("Event loop exited with failure.");

    /* shutdown squid now */
    SquidShutdown();

    /* NOTREACHED */
    return 0;
