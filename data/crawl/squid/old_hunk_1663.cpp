{

public:
    SignalEngine(EventLoop &evtLoop) : loop(evtLoop) {}
    virtual int checkEvents(int timeout);

private:
    static void StopEventLoop(void * data) {
        static_cast<SignalEngine *>(data)->loop.stop();
    }

    void doShutdown(time_t wait);

    EventLoop &loop;
};

int
