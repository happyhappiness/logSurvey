    bool reading() const;
    void stopReading(); ///< cancels comm_read if it is scheduled

    /// true if we stopped receiving the request
    const char *stoppedReceiving() const { return stoppedReceiving_; }
    /// true if we stopped sending the response
    const char *stoppedSending() const { return stoppedSending_; }
    /// note request receiving error and close as soon as we write the response
    void stopReceiving(const char *error);
    /// note response sending error and close as soon as we read the request
    void stopSending(const char *error);

    void expectNoForwarding(); ///< cleans up virgin request [body] forwarding state

    BodyPipe::Pointer expectRequestBody(int64_t size);
