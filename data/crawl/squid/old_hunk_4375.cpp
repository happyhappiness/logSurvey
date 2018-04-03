    AsyncJob(const char *aTypeName);
    virtual ~AsyncJob();

    void noteStart(); // calls virtual start
    AsyncCallWrapper(93,3, AsyncJob, noteStart);

protected:
    void mustStop(const char *aReason); // force done() for a reason

    bool done() const; // the job is destroyed in callEnd() when done()

    virtual void start() = 0;
    virtual bool doneAll() const = 0; // return true when done
    virtual void swanSong() = 0; // perform internal cleanup
    virtual const char *status() const = 0; // for debugging

    // asynchronous call maintenance
    bool callStart(const char *methodName);
    virtual void callException(const TextException &e);
    virtual void callEnd();

    const char *stopReason; // reason for forcing done() to be true
    const char *typeName; // kid (leaf) class name, for debugging
    const char *inCall; // name of the asynchronous call being executed, if any
};


// call guards for all "asynchronous" note*() methods
// TODO: Move to core.

// asynchronous call entry:
// - open the try clause;
// - call callStart().
#define AsyncCallEnter(method) \
    try { \
        if (!callStart(#method)) \
            return;

// asynchronous call exit:
// - close the try clause;
// - catch exceptions;
// - let callEnd() handle transaction termination conditions
#define AsyncCallExit() \
    } \
    catch (const TextException &e) { \
        callException(e); \
    } \
    callEnd();


#endif /* SQUID_ASYNC_JOB_H */