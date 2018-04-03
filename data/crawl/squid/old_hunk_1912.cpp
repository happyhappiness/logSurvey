        exit(1);
    }
#ifdef O_NONBLOCK
    fcntl(sockfd, F_SETFL, fcntl(sockfd, F_GETFL, 0) | O_NONBLOCK);
#endif
    nas_ipaddr = ntohl(salocal.sin_addr.s_addr);
    while (fgets(buf, HELPER_INPUT_BUFFER, stdin) != NULL) {