
public:
    virtual ~Packer();
    virtual void append(const char *buf, int size);

    /* protected, use interface functions instead */
    append_f append_;
    vprintf_f packer_vprintf;
    void *real_handler;     /* first parameter to real append and vprintf */
};

void packerPrintf(Packer * p, const char *fmt,...) PRINTF_FORMAT_ARG2;

#endif /* SQUID_PACKER_H */

