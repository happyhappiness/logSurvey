    {
        ++calls;
    }

    bool dispatch()
    {
        ++calls;
        /* claim we dispatched calls to be useful for the testStopOnIdle test.
         */
        return true;
    }
};

class RecordingEngine : public AsyncEngine
{

public:
    int calls;
    int lasttimeout;
    int return_timeout;
    RecordingEngine(int return_timeout=0): calls(0), lasttimeout(0),
            return_timeout(return_timeout)
          {}

          virtual int checkEvents(int timeout)
          {
              ++calls;
              lasttimeout = timeout;
              return return_timeout;
          }
      };

void
testEventLoop::testRunOnce()
{
    EventLoop theLoop;
    RecordDispatcher dispatcher;
    theLoop.registerDispatcher(&dispatcher);
    RecordingEngine engine;
    theLoop.registerEngine(&engine);
    theLoop.runOnce();
    CPPUNIT_ASSERT_EQUAL(1, dispatcher.calls);
    CPPUNIT_ASSERT_EQUAL(1, engine.calls);
}

/*
 * completion dispatchers registered with the event loop are invoked by the
 * event loop.
 *
 * This test works by having a customer dispatcher which shuts the loop down
 * once its been invoked twice.
 *
 * It also tests that loop.run() and loop.stop() work, because if they dont
 * work, this test will either hang, or fail.
 */

class ShutdownDispatcher : public CompletionDispatcher
