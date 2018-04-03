    /// Add the appropriate [Proxy-]Authenticate header to the given reply
    static void addReplyAuthHeader(HttpReply * rep, UserRequest::Pointer auth_user_request, HttpRequest * request, int accelerated, int internal);

    /** Start an asynchronous helper lookup to verify the user credentials
     *
     * Uses startHelperLookup() for scheme-specific actions.
     *
     * The given callback will be called when the auth module has performed
     * it's external activities.
     *
     * \param handler	Handler to process the callback when its run
     * \param data	CBDATA for handler
     */
    void start(HttpRequest *request, AccessLogEntry::Pointer &al, AUTHCB *handler, void *data);

    char const * denyMessage(char const * const default_message = NULL);

    /** Possibly overrideable in future */
