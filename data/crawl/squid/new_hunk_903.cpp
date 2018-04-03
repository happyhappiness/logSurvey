
public:
    virtual ~Packer();

    virtual void append(const char *buf, int size);

    /*
     * \note  we use Printf instead of printf so the compiler won't
     *        think we're calling the libc printf()
     */
    virtual void Printf(const char *fmt,...) PRINTF_FORMAT_ARG2;

    /* protected, use interface functions instead */
    append_f append_;
    vprintf_f packer_vprintf;
    void *real_handler;     /* first parameter to real append and vprintf */
};

#endif /* SQUID_PACKER_H */

