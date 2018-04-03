    setbuf(stdin, NULL);

    if (!server) {
        std::cerr << "ERROR: GSSAPI: No server name" << std::endl;
        return (char *)"ERROR";
    }
    service.value = xmalloc(strlen("HTTP") + strlen(server) + 2);