
    /* Packable API */
    virtual void append(const char *buf, int size);
    virtual void vappendf(const char *fmt, va_list ap);

    /* protected, use interface functions instead */
    append_f append_;
