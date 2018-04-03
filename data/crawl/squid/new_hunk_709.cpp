    /** unfirtunate hack to test if the buffer has been Init()ialized */
    int isNull();

    /**
     * freezes the object! and returns function to clear it up.
     *
     \retval free() function to be used.
     */
    FREE *freeFunc();

    /* Packable API */
    virtual void append(const char *c, int sz);
    virtual void vappendf(const char *fmt, va_list ap);

private:
    /**
     * private copy constructor and assignment operator generates
