    };
};

class SignalDispatcher : public CompletionDispatcher
{

public:
    SignalDispatcher(EventLoop &loop) : loop(loop), events_dispatched(false) {}

    void addEventLoop(EventLoop * loop);
    virtual bool dispatch();

private:
    static void StopEventLoop(void * data)
    {
        static_cast<SignalDispatcher *>(data)->loop.stop();
    }

    EventLoop &loop;
    bool events_dispatched;
};

bool
SignalDispatcher::dispatch()
{
    PROF_start(SignalDispatcher_dispatch);

    if (do_reconfigure) {
        mainReconfigure();
