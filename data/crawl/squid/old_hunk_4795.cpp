
#endif

    if (0 == nns)
        fatal("Could not find any nameservers.\n"
#ifdef _SQUID_WIN32_
              "       Please check your TCP-IP settings or /etc/resolv.conf file\n"
#else
              "       Please check your /etc/resolv.conf file\n"
#endif
              "       or use the 'dns_nameservers' option in squid.conf.");

    if (!init) {
        memDataInit(MEM_IDNS_QUERY, "idns_query", sizeof(idns_query), 0);