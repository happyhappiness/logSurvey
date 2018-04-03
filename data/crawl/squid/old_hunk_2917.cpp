#elif HAVE_MALLINFO && HAVE_STRUCT_MALLINFO

    struct mallinfo mp;
    long t;
#endif

    runtime = tvSubDsec(squid_start, current_time);

    if (runtime == 0.0)
        runtime = 1.0;

    storeAppendPrintf(sentry, "Squid Object Cache: Version %s\n",
                      version_string);

