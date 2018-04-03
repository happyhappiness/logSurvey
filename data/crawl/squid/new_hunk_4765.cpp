    ShutdownDispatcher(EventLoop & theLoop):theLoop(theLoop), calls(0)
    {}

    bool dispatch()
    {
        if (++calls == 2)
