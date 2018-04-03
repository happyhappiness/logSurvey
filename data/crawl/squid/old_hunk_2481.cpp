        if (c) {
            *c = '\0';
            length = c - buf;
        } else {
            err = 1;
        }
        if (err) {
            if (debug)
                fprintf(stderr, "%s| %s: Oversized message\n", LogTime(),
                        PROGRAM);
            fprintf(stdout, "BH Oversized message\n");
            err = 0;
            continue;
        }
        if (debug)
            fprintf(stderr, "%s| %s: Got '%s' from squid (length: %d).\n",
                    LogTime(), PROGRAM, buf, length);

        if (buf[0] == '\0') {
            if (debug)