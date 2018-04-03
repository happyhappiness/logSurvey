
#endif

    if (0 == nns) {
        debugs(78, 1, "Warning: Could not find any nameservers. Trying to use localhost");
#ifdef _SQUID_WIN32_

        debugs(78, 1, "Please check your TCP-IP settings or /etc/resolv.conf file");
#else

        debugs(78, 1, "Please check your /etc/resolv.conf file");
#endif

        debugs(78, 1, "or use the 'dns_nameservers' option in squid.conf.");
        idnsAddNameserver("127.0.0.1");
    }

    if (!init) {
        memDataInit(MEM_IDNS_QUERY, "idns_query", sizeof(idns_query), 0);