     */
    virtual void module_start(RH *handler, void *data) = 0;

    virtual Auth::User::Pointer user() {return _auth_user;}

    virtual const Auth::User::Pointer user() const {return _auth_user;}

    virtual void user(Auth::User::Pointer aUser) {_auth_user=aUser;}

    static AuthAclState tryToAuthenticateAndSetAuthUser(AuthUserRequest::Pointer *, http_hdr_type, HttpRequest *, ConnStateData *, Ip::Address &);
    static void addReplyAuthHeader(HttpReply * rep, AuthUserRequest::Pointer auth_user_request, HttpRequest * request, int accelerated, int internal);

    AuthUserRequest();

    virtual ~AuthUserRequest();
    void *operator new(size_t byteCount);
    void operator delete(void *address);

    void start( RH * handler, void *data);
    char const * denyMessage(char const * const default_message = NULL);
