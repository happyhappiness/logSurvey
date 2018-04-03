    /// note the end of an ICAP processing interval
    void stop(const char *context);

    /// returns the total time of all ICAP processing intervals
    int processingTime() const;

    String rfc931; ///< the username from ident
#if USE_OPENSSL
