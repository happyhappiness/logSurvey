{

public:
    virtual int checkEvents(int timeout);

private:
    static void StopEventLoop(void *) {
        if (EventLoop::Running)
            EventLoop::Running->stop();
    }

    void doShutdown(time_t wait);
};

int
