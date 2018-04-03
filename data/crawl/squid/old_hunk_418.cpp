    StreamContext(uint32_t id, const Comm::ConnectionPointer &, ClientHttpRequest *);
    ~StreamContext();

    bool startOfOutput() const;
    void writeComplete(size_t size);

public:
    // NP: stream ID is relative to the connection, not global.
    uint32_t id; ///< stream ID within the client connection.
