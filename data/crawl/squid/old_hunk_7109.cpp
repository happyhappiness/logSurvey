{
    const char *tod = NULL;
    float f;
#if HAVE_MALLINFO
    int t;
#endif

#if defined(HAVE_GETRUSAGE) && defined(RUSAGE_SELF)
    struct rusage rusage;
#endif

#if HAVE_MALLINFO
    struct mallinfo mp;
#endif

    storeAppendPrintf(sentry, open_bracket);
