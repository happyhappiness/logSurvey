        exit(1);
    }
#ifdef O_NONBLOCK
    if (fcntl(sockfd, F_SETFL, fcntl(sockfd, F_GETFL, 0) | O_NONBLOCK) < 0) {
        fprintf(stderr,"%s| ERROR: fcntl() failure: %s\n", argv[0], xstrerror());
        exit(1);
    }
#endif
    nas_ipaddr = ntohl(salocal.sin_addr.s_addr);
    while (fgets(buf, HELPER_INPUT_BUFFER, stdin) != NULL) {