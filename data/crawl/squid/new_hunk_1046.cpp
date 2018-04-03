    void start(pid_t cpid);

    /// called when kid terminates, sets exiting status
    void stop(PidStatus const exitStatus);

    /// returns true if tracking of kid is stopped
    bool running() const;
