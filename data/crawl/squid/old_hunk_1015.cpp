     */
    void Printf(const char *fmt,...) PRINTF_FORMAT_ARG2;

    /** vPrintf for other printf()'s to use */
    void vPrintf(const char *fmt, va_list ap);

    /**
     * freezes the object! and returns function to clear it up.
