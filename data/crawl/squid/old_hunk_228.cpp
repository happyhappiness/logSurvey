{

public:
    static char *debugOptions;
    static char *cache_log;
    static int rotateNumber;
    static int Levels[MAX_DEBUG_SECTIONS];
    static int level; ///< minimum debugging level required by debugs() call
    static int sectionLevel; ///< maximum debugging level allowed now
    static int override_X;
    static int log_stderr;
    static bool log_syslog;

    static std::ostream &getDebugOut();
    static void finishDebug();
    static void parseOptions(char const *);

private:
    // Hack: replaces global ::xassert() to debug debugging assertions
    static void xassert(const char *msg, const char *file, int line);

    /// Wrapper class to prevent SquidNew.h overrides getting confused
    /// with the libc++6 std::ostringstream definitions
    class OutStream : public std::ostringstream
    {
        MEMPROXY_CLASS(OutStream);
    public:
        void *operator new[] (size_t size) throw(std::bad_alloc) = delete; //{return xmalloc(size);}
        void operator delete[] (void *address) throw() = delete; // {xfree(address);}
    };

    static OutStream *CurrentDebug;
    static int TheDepth; // level of nested debugging calls
};

extern FILE *debug_log;
