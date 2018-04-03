accessLogInit(void)
{
    assert(sizeof(log_tags) == (LOG_TYPE_MAX + 1) * sizeof(char *));

    if (strcasecmp(Config.Log.access, "none") == 0)
        return;

    logfile = logfileOpen(Config.Log.access, MAX_URL << 1, 1);

    LogfileStatus = LOG_ENABLE;

#if HEADERS_LOG

    headerslog = logfileOpen("/usr/local/squid/logs/headers.log", 512);

    assert(NULL != headerslog);

#endif
#if FORW_VIA_DB

    fvdbInit();

#endif
#if MULTICAST_MISS_STREAM

    if (Config.mcast_miss.addr.s_addr != no_addr.s_addr) {
        memset(&mcast_miss_to, '\0', sizeof(mcast_miss_to));
        mcast_miss_to.sin_family = AF_INET;
        mcast_miss_to.sin_port = htons(Config.mcast_miss.port);
        mcast_miss_to.sin_addr.s_addr = Config.mcast_miss.addr.s_addr;
        mcast_miss_fd = comm_open(SOCK_DGRAM,
                                  0,
                                  Config.Addrs.udp_incoming,
                                  Config.mcast_miss.port,
                                  COMM_NONBLOCKING,
                                  "Multicast Miss Stream");

        if (mcast_miss_fd < 0)
            fatal("Cannot open Multicast Miss Stream Socket");

        debug(46, 1) ("Multicast Miss Stream Socket opened on FD %d\n",
                      mcast_miss_fd);

        mcastSetTtl(mcast_miss_fd, Config.mcast_miss.ttl);

        if (strlen(Config.mcast_miss.encode_key) < 16)
            fatal("mcast_encode_key is too short, must be 16 characters");
    }

#endif
}

const char *
accessLogTime(time_t t)
{

    struct tm *tm;
    static char buf[128];
    static time_t last_t = 0;

    if (t != last_t) {
        tm = localtime(&t);
        strftime(buf, 127, "%Y/%m/%d %H:%M:%S", tm);
        last_t = t;
    }

    return buf;
}

