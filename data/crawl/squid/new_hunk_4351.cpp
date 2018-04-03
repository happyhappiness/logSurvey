
    virtual const AuthUser *user() const {return _auth_user;}

    virtual void user(AuthUser *aUser) {_auth_user=aUser;}

    static auth_acl_t tryToAuthenticateAndSetAuthUser(AuthUserRequest **, http_hdr_type, HttpRequest *, ConnStateData *, IPAddress &);
    static void addReplyAuthHeader(HttpReply * rep, AuthUserRequest * auth_user_request, HttpRequest * request, int accelerated, int internal);

    AuthUserRequest();

    virtual ~AuthUserRequest();
    void *operator new(size_t byteCount);
    void operator delete(void *address);

    void start( RH * handler, void *data);
    char const * denyMessage(char const * const default_message = NULL);

    /** Possibly overrideable in future */
    void setDenyMessage(char const *);

    /** Possibly overrideable in future */
    char const * getDenyMessage();

    size_t refCount() const;
    void _lock();		// please use AUTHUSERREQUESTLOCK()
    void _unlock();		// please use AUTHUSERREQUESTUNLOCK()

    /**
     * Squid does not make assumptions about where the username is stored.
