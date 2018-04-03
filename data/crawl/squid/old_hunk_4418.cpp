        sleep(1);
    }

    if (NULL == result) {
        if (h_errno == TRY_AGAIN) {
            printf("$fail Name Server for domain '%s' is unavailable.\n", buf);
        } else {
            printf("$fail DNS Domain '%s' is invalid: %s.\n",
                   buf, my_h_msgs(h_errno));
        }

        return;
    }

#if LIBRESOLV_DNS_TTL_HACK
    /* DNS TTL handling - bne@CareNet.hu
     * for first try it's a dirty hack, by hacking getanswer
     * to place the ttl in a global variable */
    if (_dns_ttl_ > -1)
        ttl = _dns_ttl_;

#endif

    if (reverse) {
        printf("$name %d %s\n", ttl, result->h_name);
        return;
    }

    printf("$addr %d", ttl);

    for (i = 0; NULL != result->h_addr_list[i]; i++) {
        if (32 == i)
            break;

        xmemcpy(&addr, result->h_addr_list[i], sizeof(addr));

        printf(" %s", inet_ntoa(addr));
    }

    printf("\n");
}

static void
usage(void)
{
    fprintf(stderr, "usage: dnsserver -Dhv -s nameserver\n"
            "\t-D             Enable resolver RES_DEFNAMES and RES_DNSRCH options\n"
            "\t-h             Help\n"
            "\t-v             Version\n"
            "\t-s nameserver  Specify alternate name server(s).  'nameserver'\n"
            "\t               must be an IP address, -s option may be repeated\n");
}

int
main(int argc, char *argv[])
{
    char request[512];
    char *t = NULL;
    int c;
#if HAVE_RES_INIT

    int opt_s = 0;
#if HAVE_RES_NSADDR_LIST || HAVE_RES_NS_LIST

    extern char *optarg;
#endif
#endif

    safe_inet_addr("255.255.255.255", &no_addr);

#if HAVE_RES_INIT

    res_init();
#ifdef RES_DEFAULT

    _res.options = RES_DEFAULT;
#endif
#ifdef RES_DEFNAMES

    _res.options &= ~RES_DEFNAMES;
#endif
#ifdef RES_DNSRCH

    _res.options &= ~RES_DNSRCH;
#endif
#endif

    while ((c = getopt(argc, argv, "Dhs:v")) != -1) {
        switch (c) {

        case 'D':
#ifdef RES_DEFNAMES

            _res.options |= RES_DEFNAMES;
#endif
#ifdef RES_DNSRCH

            _res.options |= RES_DNSRCH;
#endif

            break;

        case 's':
#if HAVE_RES_INIT

            if (opt_s == 0) {
                _res.nscount = 0;
                /*
                 * Setting RES_INIT here causes coredumps when -s is
                 * used with -D option.  It looks to me like setting
                 * RES_INIT is wrong.  The resolver code sets RES_INIT
                 * after calling res_init().  When we change the _res
                 * structure and set RES_INIT, some internal resolver
                 * structures get confused.             -DW 2.1.p1
                 */
#if SEEMS_WRONG

                _res.options |= RES_INIT;
#endif

                opt_s = 1;
            } else if (_res.nscount == MAXNS) {
                fprintf(stderr, "Too many -s options, only %d are allowed\n",
                        MAXNS);
                break;
            }

#if HAVE_RES_NSADDR_LIST
            _res.nsaddr_list[_res.nscount] = _res.nsaddr_list[0];

            safe_inet_addr(optarg, &_res.nsaddr_list[_res.nscount++].sin_addr);

#elif HAVE_RES_NS_LIST

            _res.ns_list[_res.nscount] = _res.ns_list[0];

            safe_inet_addr(optarg, &_res.ns_list[_res.nscount++].addr.sin_addr);

#else /* Unknown NS list format */

            fprintf(stderr, "-s is not supported on this resolver\n");

#endif
#else /* !HAVE_RES_INIT */

            fprintf(stderr, "-s is not supported on this resolver\n");

