    /* TODO: stop requiring the singleton here */
    mainLoop.registerDispatcher(EventDispatcher::GetInstance());

    for (;;)
    {
        /* Attempt any pending storedir IO
        * Note: the storedir is roughly a reactor of its own.
        */
        Store::Root().callback();

        comm_calliocallback();

        /* and again to deal with indirectly queued events
         * resulting from the first call. These are usually
         * callbacks and should be dealt with immediately.
         */

        if (comm_iocallbackpending())
            comm_calliocallback();

        mainLoop.runOnce();
    }

    /* NOTREACHED */
    return 0;
