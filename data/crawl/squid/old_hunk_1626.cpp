usage(void)
{
    fprintf(stderr,
#if USE_WIN32_SERVICE
            "Usage: %s [-cdhirvzCFNRVYX] [-s | -l facility] [-f config-file] [-[au] port] [-k signal] [-n name] [-O CommandLine]\n"
#else
            "Usage: %s [-cdhvzCFNRVYX] [-s | -l facility] [-f config-file] [-[au] port] [-k signal]\n"
#endif
            "       -a port   Specify HTTP port number (default: %d).\n"
            "       -d level  Write debugging to stderr also.\n"
            "       -f file   Use given config-file instead of\n"
