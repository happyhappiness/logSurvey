bool
EventLoop::runOnce()
{
    runOnceResult = true;
    error = false;
    loop_delay = 10; /* 10 ms default delay */

    for (engine_vector::iterator i = engines.begin();
            i != engines.end(); ++i) {
        /* check the primary outside the loop */

        if (*i == primaryEngine)
            continue;

        /* special case the last engine to be primary */
        checkEngine(*i, primaryEngine == NULL && (i - engines.end() == -1));
    }

    if (primaryEngine != NULL)
        checkEngine(primaryEngine, true);

    if (timeService != NULL)
        timeService->tick();

    for (dispatcher_vector::iterator i = dispatchers.begin();
            i != dispatchers.end(); ++i)
        if ((*i)->dispatch())
            runOnceResult = false;

    if (error) {
        ++errcount;
