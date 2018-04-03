    }
#ifdef O_NONBLOCK
    if (fcntl(sockfd, F_SETFL, fcntl(sockfd, F_GETFL, 0) | O_NONBLOCK) < 0) {
        int xerrno = errno;
        fprintf(stderr,"%s| ERROR: fcntl() failure: %s\n", argv[0], xstrerr(xerrno));
        exit(1);
    }
#endif
