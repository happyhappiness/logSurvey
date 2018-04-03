     AsyncJob(const char *aTypeName);
     virtual ~AsyncJob();
 
+    virtual void *toCbdata() = 0;
     void noteStart(); // calls virtual start
-    AsyncCallWrapper(93,3, AsyncJob, noteStart);
 
 protected:
+    // XXX: temporary method to replace "delete this" in jobs-in-transition.
+    // Will be replaced with calls to mustStop() when transition is complete.
+    void deleteThis(const char *aReason);
+
     void mustStop(const char *aReason); // force done() for a reason
 
     bool done() const; // the job is destroyed in callEnd() when done()
 
-    virtual void start() = 0;
-    virtual bool doneAll() const = 0; // return true when done
-    virtual void swanSong() = 0; // perform internal cleanup
-    virtual const char *status() const = 0; // for debugging
+    virtual void start();
+    virtual bool doneAll() const; // return true when done
+    virtual void swanSong() {}; // perform internal cleanup
+    virtual const char *status() const; // for debugging
 
+public:
     // asynchronous call maintenance
-    bool callStart(const char *methodName);
+    bool canBeCalled(AsyncCall &call) const;
+    void callStart(AsyncCall &call);
     virtual void callException(const TextException &e);
     virtual void callEnd();
 
+protected:
     const char *stopReason; // reason for forcing done() to be true
     const char *typeName; // kid (leaf) class name, for debugging
-    const char *inCall; // name of the asynchronous call being executed, if any
+    AsyncCall::Pointer inCall; // the asynchronous call being handled, if any
+    const unsigned int id;
+
+private:
+    static unsigned int TheLastId;
+};
+
+
+/*
+ * This is a base class for all job call dialers. It does all the job
+ * dialing logic (debugging, handling exceptions, etc.) except for calling
+ * the job method. The latter is not possible without templates and we
+ * want to keep this class simple and template-free. Thus, we add a dial()
+ * virtual method that the JobCallT template below will implement for us,
+ * calling the job.
+ */
+class JobDialer: public CallDialer
+{
+public:
+    JobDialer(AsyncJob *aJob);
+    JobDialer(const JobDialer &d);
+    virtual ~JobDialer();
+
+    virtual bool canDial(AsyncCall &call);
+    void dial(AsyncCall &call);
+
+    AsyncJob *job;
+    void *lock; // job's cbdata
+
+protected:
+    virtual void doDial() = 0; // actually calls the job method
+
+private:
+    // not implemented and should not be needed
+    JobDialer &operator =(const JobDialer &); 
 };
 
+#include "AsyncJobCalls.h"
+
+template <class Dialer>
+bool
+CallJob(int debugSection, int debugLevel, const char *fileName, int fileLine,
+    const char *callName, const Dialer &dialer)
+{
+    AsyncCall::Pointer call = asyncCall(debugSection, debugLevel, callName, dialer);
+    return ScheduleCall(fileName, fileLine, call);
+}
+
+
+#define CallJobHere(debugSection, debugLevel, job, method) \
+    CallJob((debugSection), (debugLevel), __FILE__, __LINE__, #method, \
+        MemFun((job), &method))
 
-// call guards for all "asynchronous" note*() methods
-// TODO: Move to core.
-
-// asynchronous call entry:
-// - open the try clause;
-// - call callStart().
-#define AsyncCallEnter(method) \
-    try { \
-        if (!callStart(#method)) \
-            return;
-
-// asynchronous call exit:
-// - close the try clause;
-// - catch exceptions;
-// - let callEnd() handle transaction termination conditions
-#define AsyncCallExit() \
-    } \
-    catch (const TextException &e) { \
-        callException(e); \
-    } \
-    callEnd();
+#define CallJobHere1(debugSection, debugLevel, job, method, arg1) \
+    CallJob((debugSection), (debugLevel), __FILE__, __LINE__, #method, \
+        MemFun((job), &method, (arg1)))
 
 
 #endif /* SQUID_ASYNC_JOB_H */