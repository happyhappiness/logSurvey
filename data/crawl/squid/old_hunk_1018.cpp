
    /* Packable API */
    virtual void append(const char *buf, int size);
    virtual void Printf(const char *fmt,...) PRINTF_FORMAT_ARG2;

    /* protected, use interface functions instead */
    append_f append_;