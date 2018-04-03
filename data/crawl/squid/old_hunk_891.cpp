     * \note  we use Printf instead of printf so the compiler won't
     *        think we're calling the libc printf()
     */
    virtual void Printf(const char *fmt,...) PRINTF_FORMAT_ARG2 = 0;
};

#endif /* SQUID_SRC_BASE_PACKABLE_H */