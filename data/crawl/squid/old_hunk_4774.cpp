    {
        ++calls;
    }
};

void
testEventLoop::testRunOnce()
{
    EventLoop theLoop;
    RecordDispatcher dispatcher;
    theLoop.registerDispatcher(&dispatcher);
    theLoop.runOnce();
    CPPUNIT_ASSERT_EQUAL(1, dispatcher.calls);
}

/*
 * completion dispatchers registered with the event loop are invoked by the event 
 * loop.
 *
 * This test works by having a customer dispatcher which shuts the loop down once its
 * been invoked twice.
 *
 * It also tests that loop.run() and loop.stop() work, because if they dont work,
 * this test will either hang, or fail.
 */

class ShutdownDispatcher : public CompletionDispatcher
