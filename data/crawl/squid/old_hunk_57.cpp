     */
    void start(HttpRequest *request, AccessLogEntry::Pointer &al, AUTHCB *handler, void *data);

    char const * denyMessage(char const * const default_message = NULL);

    /** Possibly overrideable in future */
    void setDenyMessage(char const *);

    /** Possibly overrideable in future */
    char const * getDenyMessage();

    /**
     * Squid does not make assumptions about where the username is stored.
