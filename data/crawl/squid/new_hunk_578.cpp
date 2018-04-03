        execv(kargs[0], kargs);
        fprintf(stderr, "%s| %s: Failed execv for %s: %s\n", LogTime(), PROGRAM, kargs[0], strerror(errno));
        return 1;
    }

    close(pkin[0]);
