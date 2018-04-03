     * \note  we use Printf instead of printf so the compiler won't
     *        think we're calling the libc printf()
     */
    void Printf(const char *fmt,...) PRINTF_FORMAT_ARG2
    {
        va_list args;
        va_start(args, fmt);
        vappendf(fmt, args);
        va_end(args);
    }

    /** Append operation, with vsprintf(3)-style arguments.
     *
     * \note arguments may be evaluated more than once, be careful
     *       of side-effects
     */
    virtual void vappendf(const char *fmt, va_list ap) = 0;
};

#endif /* SQUID_SRC_BASE_PACKABLE_H */