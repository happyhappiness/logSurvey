    /// Appends a c-string to existing packed data.
    virtual void append(const char *buf, int size) = 0;

    /// Append operation with printf-style arguments.
    void appendf(const char *fmt,...) PRINTF_FORMAT_ARG2
    {
        va_list args;
        va_start(args, fmt);
        vappendf(fmt, args);
        va_end(args);
    }
#if 0
    /*
     * \note  we use Printf instead of printf so the compiler won't
     *        think we're calling the libc printf()
     */
