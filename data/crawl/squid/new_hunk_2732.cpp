    mb.Printf("http://%s", lc_host);

    /* append port if not default */
    if (port && port != urlDefaultPort(AnyP::PROTO_HTTP))
        mb.Printf(":%d", port);

    if (dir)
