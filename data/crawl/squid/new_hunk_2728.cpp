        switch (request->protocol) {
#if USE_SSL

        case AnyP::PROTO_HTTPS:
            httpStart(this);
            break;
#endif

        case AnyP::PROTO_HTTP:
            httpStart(this);
            break;

        case AnyP::PROTO_GOPHER:
            gopherStart(this);
            break;

        case AnyP::PROTO_FTP:
            ftpStart(this);
            break;

        case AnyP::PROTO_CACHEOBJ:

        case AnyP::PROTO_INTERNAL:

        case AnyP::PROTO_URN:
            fatal_dump("Should never get here");
            break;

        case AnyP::PROTO_WHOIS:
            whoisStart(this);
            break;

        case AnyP::PROTO_WAIS:	/* Not implemented */

        default:
            debugs(17, 1, "fwdDispatch: Cannot retrieve '" << entry->url() << "'" );
