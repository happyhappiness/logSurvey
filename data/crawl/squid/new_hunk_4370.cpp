    };
};

class SignalEngine: public AsyncEngine
{

public:
    SignalEngine(EventLoop &loop) : loop(loop) {}
    virtual int checkEvents(int timeout);

private:
    static void StopEventLoop(void * data)
    {
        static_cast<SignalEngine *>(data)->loop.stop();
    }

    void doShutdown(time_t wait);

    EventLoop &loop;
};

int
SignalEngine::checkEvents(int timeout)
{
    PROF_start(SignalEngine_checkEvents);

    if (do_reconfigure) {
        mainReconfigure();
