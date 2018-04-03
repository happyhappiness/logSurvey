    ShutdownDispatcher(EventLoop & theLoop):theLoop(theLoop), calls(0)
    {}

    void dispatch()
    {
        if (++calls == 2)
            theLoop.stop();
    }

    bool dispatch()
    {
        if (++calls == 2)
