    dispatchers.push_back(dispatcher);
}

void
EventLoop::run()
{
    prepareToRun();

    while (!last_loop)
        runOnce();
}

void
EventLoop::runOnce()
{
    int loop_delay = EventScheduler::GetInstance()->checkEvents();

    for (dispatcher_vector::iterator i = dispatchers.begin();
            i != dispatchers.end(); ++i)
        (*i)->dispatch();

    if (loop_delay < 0)
        loop_delay = 0;

    switch (comm_select(loop_delay)) {

    case COMM_OK:
        errcount = 0;	/* reset if successful */
        break;

    case COMM_IDLE:
        /* TODO: rather than busy loop, if everything has returned IDLE we should
         * wait for a reasonable timeout period, - if everything returned IDLE
         * then not only is there no work to do, there is no work coming in -
         * all the comm loops have no fds registered, and  all the other 
         * async engines have no work active or pending.
         * ... perhaps we can have a query method to say 'when could there be 
         * work' - i.e. the event dispatcher can return the next event in its
         * queue, and everything else can return -1.
         */
        errcount = 0;
        break;

    case COMM_ERROR:
        errcount++;
        debugs(1, 0, "Select loop Error. Retry " << errcount);

        if (errcount == 10)
            fatal_dump("Select Loop failed 10 times.!");

        break;

    case COMM_TIMEOUT:
        break;

    case COMM_SHUTDOWN:
        stop();

        break;

    default:
        fatal_dump("MAIN: Internal error -- this should never happen.");

        break;
    }
}

void
