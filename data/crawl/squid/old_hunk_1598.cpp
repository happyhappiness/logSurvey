    setbuf(stdin, NULL);

    if (!server) {
        fprintf(stderr, "Error: No server name\n");
        return (char *)"ERROR";
    }
    service.value = xmalloc(strlen("HTTP") + strlen(server) + 2);