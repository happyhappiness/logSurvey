        sleep(1);
    }

    /* check if it's already an IP address in text form. */
    ipa = buf;
    if( ipa.IsAnyAddr() ) {
        /* its a domain name. Use the forward-DNS lookup already done */

        if(res == 0) {
#if LIBRESOLV_DNS_TTL_HACK
            /* DNS TTL handling - bne@CareNet.hu
             * for first try it's a dirty hack, by hacking getanswer
             * to place the ttl in a global variable */
            if (_dns_ttl_ > -1)
                ttl = _dns_ttl_;
#endif
            printf("$addr %d", ttl);

            i = 0;
            aiptr = AI;
            while(NULL != aiptr && 32 >= i) {
                memset(ntoabuf, 0, MAX_IPSTRLEN);

                /* getaddrinfo given a host has a nasty tendency to return duplicate addr's */
                /* BUT sorted fortunately, so we can drop most of them easily */
                if( prev_addr &&
                   prev_addr->ai_family==aiptr->ai_family &&
                   memcmp(aiptr->ai_addr, prev_addr->ai_addr, aiptr->ai_addrlen)==0
                  ) {
                    prev_addr = aiptr;
                    aiptr = aiptr->ai_next;
                    continue;
                }
                else {
                    prev_addr = aiptr;
                }

                /* annoying inet_ntop breaks the nice code by requiring the in*_addr */
                switch(aiptr->ai_family) {
                case AF_INET:
                    xinet_ntop(aiptr->ai_family, &((struct sockaddr_in*)aiptr->ai_addr)->sin_addr, ntoabuf, MAX_IPSTRLEN);
                    break;
#if USE_IPV6
                case AF_INET6:
                    xinet_ntop(aiptr->ai_family, &((struct sockaddr_in6*)aiptr->ai_addr)->sin6_addr, ntoabuf, MAX_IPSTRLEN);
                    break;
#endif
                default:
                    aiptr = aiptr->ai_next;
                    continue;
                }
                printf(" %s", ntoabuf);
                i++;
                aiptr = aiptr->ai_next;
            }

            prev_addr=NULL;
            printf("\n");
        }
    }
    else /* its an IPA in text form. perform rDNS */
    {
        /* You'd expect getaddrinfo given AI_CANONNAME would do a lookup on
         * missing FQDN. But no, it only copies the input string to that
         * position regardless of its content.
         */
        if(NULL != AI && NULL != AI->ai_addr) {
            for(;;) {
                if( 0 == (res = xgetnameinfo(AI->ai_addr, AI->ai_addrlen, ntoabuf, MAX_IPSTRLEN, NULL,0,0)) )
                    break;

                if (res != EAI_AGAIN)
                    break;

                if (++retry == 3)
                    break;

                sleep(1);
            }
        }

        if(res == 0) {
#if LIBRESOLV_DNS_TTL_HACK
            /* DNS TTL handling - bne@CareNet.hu
             * for first try it's a dirty hack, by hacking getanswer
             * to place the ttl in a global variable */
            if (_dns_ttl_ > -1)
                ttl = _dns_ttl_;
#endif

            printf("$name %d %s\n", ttl, ntoabuf);
        }
    }

    switch(res) {
        case 0:
            /* no error. */
            break;

        case EAI_AGAIN:
            printf("$fail Name Server for domain '%s' is unavailable.\n", buf);
            break;

        case EAI_FAIL:
            printf("$fail DNS Domain/IP '%s' does not exist: %s.\n", buf, xgai_strerror(res));
            break;

#if defined(EAI_NODATA) || defined(EAI_NONAME)
#ifdef EAI_NODATA
        /* deprecated. obsolete on some OS */
        case EAI_NODATA:
#endif
#ifdef EAI_NONAME
        case EAI_NONAME:
#endif
            printf("$fail DNS Domain/IP '%s' exists without any FQDN/IPs: %s.\n", buf, xgai_strerror(res));
            break;
#endif
       default:
            printf("$fail A system error occured looking up Domain/IP '%s': %s.\n", buf, xgai_strerror(res));
    }

    xfreeaddrinfo(AI);
}

static void
usage(void)
{
    fprintf(stderr, "usage: dnsserver -hv -s nameserver\n"
            "\t-h             Help\n"
            "\t-v             Version\n"
            "\t-s nameserver  Specify alternate name server(s).  'nameserver'\n"
            "\t               must be an IPv4 address, -s option may be repeated\n"
            );
}

#ifdef _SQUID_RES_NSADDR6_LARRAY
#define _SQUID_RES_NSADDR6_LIST(i)	_SQUID_RES_NSADDR6_LARRAY[i].sin6_addr
#endif
#ifdef _SQUID_RES_NSADDR6_LPTR
#define _SQUID_RES_NSADDR6_LIST(i)	_SQUID_RES_NSADDR6_LPTR[i]->sin6_addr
#endif

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

    IPAddress ipa;
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
            if( !(ipa = optarg) ) {
                fprintf(stderr, "%s appears to be a bad nameserver FQDN/IP.\n",optarg);
            }
            else if( ipa.IsIPv4() ) {
                if (_SQUID_RES_NSADDR_COUNT == MAXNS) {
                    fprintf(stderr, "Too many -s options, only %d are allowed\n", MAXNS);
                    break;
                }
                _SQUID_RES_NSADDR_LIST[_SQUID_RES_NSADDR_COUNT] = _SQUID_RES_NSADDR_LIST[0];
                ipa.GetInAddr(_SQUID_RES_NSADDR_LIST[_SQUID_RES_NSADDR_COUNT++].sin_addr);
            }
            else if( ipa.IsIPv6() ) {
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

