    /// Appends a c-string to existing packed data.
    virtual void append(const char *buf, int size) = 0;

    /**
     * Append operation with printf-style arguments.
     *
     * \note  we use Printf instead of printf so the compiler won't
     *        think we're calling the libc printf()
     */
