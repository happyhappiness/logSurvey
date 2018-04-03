    virtual void swanSong();

public:
    void noteAbort() { mustStop("externally aborted"); }

    typedef CbcPointer<ConnOpener> Pointer;

    virtual bool doneAll() const;
