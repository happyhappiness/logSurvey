    /* TODO: Make the methods below (at least) non-public when possible. */

    /// stop parsing the request and create context for relaying error info
    Http::Stream *abortRequestParsing(const char *const errUri);

    /// generate a fake CONNECT request with the given payload
    /// at the beginning of the client I/O buffer
