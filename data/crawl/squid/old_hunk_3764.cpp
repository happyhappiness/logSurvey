#endif

/**
 \ingroup dnsserver
 *
 * This is the external dnsserver process.
 */
int
main(int argc, char *argv[])
{
    char request[512];
    char *t = NULL;
    int c;
#if defined(_SQUID_FREEBSD_) && defined(_SQUID_RES_NSADDR6_COUNT)
    /* Only seems to be valid on FreeBSD 5.5 where _res_ext was provided without an ns6addr counter! */
    /* Gone again on FreeBSD 6.2 along with _res_ext itself in any form. */
    int ns6count = 0;
#endif
#if HAVE_RES_INIT

    IpAddress ipa;
    int opt_s = 0;
#ifdef _SQUID_RES_NSADDR_LIST

    extern char *optarg;
#endif
#endif

#if HAVE_RES_INIT
    res_init();
#endif

#if USE_IPV6
    /* perform AAAA lookups *before* A lookups in IPv6 mode. */
    _res.options |= RES_USE_INET6;
#endif

    while ((c = getopt(argc, argv, "Dhs:v")) != -1) {
        switch (c) {

        case 'D':
            fprintf(stderr, "-D is now default behaviour from this tool.\n");
            break;

        case 's':
#if HAVE_RES_INIT && (defined(_SQUID_RES_NSADDR_LIST) || defined(_SQUID_RES_NSADDR6_LIST))

            if (opt_s == 0) {
#if defined(_SQUID_RES_NSADDR_COUNT)
                _SQUID_RES_NSADDR_COUNT = 0;
                /* because I don't trust the nscount super-count entirely, make sure these are ALL invalid */
                memset(_SQUID_RES_NSADDR_LIST, 0, sizeof(struct sockaddr_in)*MAXNS);
#endif
#if defined(_SQUID_RES_NSADDR6_COUNT)
                _SQUID_RES_NSADDR6_COUNT = 0;
#endif
                opt_s = 1;
            }

            /* AYJ:
             *  I experimented with all the permutations of mixed/unmixed nscount/nscount6 IPv4/IPv6/Both/invalid
             *
             *  I'm not sure if splitting them really helps.
             *  I've seen no evidence of IPv4 resolver *ever* being used when some IPv6 are set (or not even)
             *  BUT, have seen segfault when IPv4 is added to NSADDR6 list (_res._u._ext).
             *  It also appears to not do ANY lookup when _res.nscount==0.
             *
             *  BUT, even if _res.nsaddrs is memset to NULL, it resolves IFF IPv6 set in _ext.
             *
             *  SO, am splittig the IPv4/v6 into the seperate _res fields
             *      and making nscount a total of IPv4+IPv6 /w nscount6 the IPv6 sub-counter
             *	ie. nscount = count(NSv4)+count(NSv6) & nscount6 = count(NSv6)
             *
             * If ANYONE knows better please let us know.
             *
             */
            if ( !(ipa = optarg) ) {
                fprintf(stderr, "%s appears to be a bad nameserver FQDN/IP.\n",optarg);
            } else if ( ipa.IsIPv4() ) {
                if (_SQUID_RES_NSADDR_COUNT == MAXNS) {
                    fprintf(stderr, "Too many -s options, only %d are allowed\n", MAXNS);
                    break;
                }
                _SQUID_RES_NSADDR_LIST[_SQUID_RES_NSADDR_COUNT] = _SQUID_RES_NSADDR_LIST[0];
                ipa.GetInAddr(_SQUID_RES_NSADDR_LIST[_SQUID_RES_NSADDR_COUNT++].sin_addr);
            } else if ( ipa.IsIPv6() ) {
#if USE_IPV6 && defined(_SQUID_RES_NSADDR6_LIST)

                /* because things NEVER seem to resolve in tests without _res.nscount being a total. */
                if (_SQUID_RES_NSADDR_COUNT == MAXNS) {
                    fprintf(stderr, "Too many -s options, only %d are allowed\n", MAXNS);
                    break;
                }
                _SQUID_RES_NSADDR_COUNT++;

                ipa.GetInAddr(_SQUID_RES_NSADDR6_LIST(_SQUID_RES_NSADDR6_COUNT++));
#else
                fprintf(stderr, "IPv6 nameservers not supported on this resolver\n");
#endif
            }

#else /* !HAVE_RES_INIT || !defined(_SQUID_RES_NSADDR_LIST) */

            fprintf(stderr, "-s is not supported on this resolver\n");

#endif /* HAVE_RES_INIT */

            break;

        case 'v':