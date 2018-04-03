    bool reading() const;
    void stopReading(); ///< cancels comm_read if it is scheduled

    bool closing() const;
    void startClosing(const char *reason);
    void expectNoForwarding(); ///< cleans up virgin request [body] forwarding state

    BodyPipe::Pointer expectRequestBody(int64_t size);
