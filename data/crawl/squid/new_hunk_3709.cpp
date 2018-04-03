class AccessCheck: public virtual AsyncJob
{
public:
    typedef void AccessCheckCallback(ServiceGroupPointer group, void *data);

    // use this to start async ACL checks; returns true if started
    static bool Start(Method method, VectPoint vp, HttpRequest *req,
                      HttpReply *rep, AccessCheckCallback *cb, void *cbdata);

protected:
    // use Start to start adaptation checks
    AccessCheck(const ServiceFilter &aFilter, AccessCheckCallback *, void *);
    ~AccessCheck();

private:
    const ServiceFilter filter;
    AccessCheckCallback *callback;
    void *callback_data;
    ACLFilledChecklist *acl_checklist;

    typedef int Candidate;
    typedef Vector<Candidate> Candidates;
    Candidates candidates;
    Candidate topCandidate() const { return *candidates.begin(); }
    ServiceGroupPointer topGroup() const; // may return nil

    void callBack(const ServiceGroupPointer &g);
    bool isCandidate(AccessRule &r);

public:
    void check();
    void checkCandidates();
    static void AccessCheckCallbackWrapper(int, void*);
    void noteAnswer(int answer);

    // AsyncJob API
    virtual bool doneAll() const { return false; } /// not done until mustStop

private:
    CBDATA_CLASS2(AccessCheck);
