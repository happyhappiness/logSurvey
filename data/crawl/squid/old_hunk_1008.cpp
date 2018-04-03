    /** unfirtunate hack to test if the buffer has been Init()ialized */
    int isNull();

    /**
     * calls snprintf, extends buffer if needed
     \note  we use Printf instead of printf so the compiler won't
     *      think we're calling the libc printf()
     */
    void Printf(const char *fmt,...) PRINTF_FORMAT_ARG2;

    /** vappendf for other printf()'s to use */
    void vappendf(const char *fmt, va_list ap);

    /**
     * freezes the object! and returns function to clear it up.
     *
     \retval free() function to be used.
     */
    FREE *freeFunc();

private:
    /**
     * private copy constructor and assignment operator generates
