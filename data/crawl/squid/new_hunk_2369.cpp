     */
    virtual void module_start(RH *handler, void *data) = 0;

    // User credentials object this UserRequest is managing
    virtual User::Pointer user() {return _auth_user;}
    virtual const User::Pointer user() const {return _auth_user;}
    virtual void user(User::Pointer aUser) {_auth_user=aUser;}

    /**
     * Locate user credentials in one of several locations. Begin authentication if needed.
     *
     * Credentials may be found in one of the following locations (listed by order of preference):
     * - the source passed as parameter aUR
     * - cached in the HttpRequest parameter from a previous authentication of this request
     * - cached in the ConnStateData paremeter from a previous authentication of this connection
     *   (only applies to some situations. ie NTLM, Negotiate, Kerberos auth schemes,
     *    or decrypted SSL requests from inside an authenticated CONNECT tunnel)
     * - cached in the user credentials cache from a previous authentication of the same credentials
     *   (only applies to cacheable authentication methods, ie Basic auth)
     * - new credentials created from HTTP headers in this request
     *
     * The found credentials are returned in aUR and if successfully authenticated
     * may now be cached in one or more of the above locations.
     *
     * \return Some AUTH_ACL_* state
     */
    static AuthAclState tryToAuthenticateAndSetAuthUser(UserRequest::Pointer *aUR, http_hdr_type, HttpRequest *, ConnStateData *, Ip::Address &);

    /// Add the appropriate [Proxy-]Authenticate header to the given reply
    static void addReplyAuthHeader(HttpReply * rep, UserRequest::Pointer auth_user_request, HttpRequest * request, int accelerated, int internal);

    void start( RH * handler, void *data);
    char const * denyMessage(char const * const default_message = NULL);
