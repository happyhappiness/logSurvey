        vappendf(fmt, args);
        va_end(args);
    }
#if 0
    /*
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
#endif

    /** Append operation, with vsprintf(3)-style arguments.
     *
