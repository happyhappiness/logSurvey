class AccessCheck: public virtual AsyncJob
{
public:
    typedef void AccessCheckCallback(ServicePointer match, void *data);

    // use this to start async ACL checks; returns true if started
    static bool Start(Method method, VectPoint vp, HttpRequest *req,
                      HttpReply *rep, AccessCheckCallback *cb, void *cbdata);

protected:
    // use Start to start adaptation checks
    AccessCheck(Method, VectPoint, HttpRequest *, HttpReply *, AccessCheckCallback *, void *);
    ~AccessCheck();

private:
    Method method;
    VectPoint point;
    HttpRequest *req;
    HttpReply *rep;
    AccessCheckCallback *callback;
    void *callback_data;
    ACLFilledChecklist *acl_checklist;

    typedef int Candidate;
    typedef Vector<Candidate> Candidates;
    Candidates candidates;
    Candidate topCandidate() { return *candidates.begin(); }

    void do_callback();
    ServicePointer findBestService(AccessRule &r, bool preferUp);
    bool done;

public:
    void check();
    void checkCandidates();
    static void AccessCheckCallbackWrapper(int, void*);
#if 0
    static EVH AccessCheckCallbackEvent;
#endif
    void noteAnswer(int answer);

//AsyncJob virtual methods
    virtual bool doneAll() const { return AsyncJob::doneAll() && done;}

private:
    CBDATA_CLASS2(AccessCheck);
