        if (c) {
            *c = '\0';
            length = c - buf;
            if (debug)
                fprintf(stderr, "%s| %s: Got '%s' from squid (length: %d).\n",
                        LogTime(), PROGRAM, buf, length);
        } else {
            if (debug)
                fprintf(stderr, "%s| %s: Oversized message\n", LogTime(),
                        PROGRAM);
            fprintf(stdout, "BH Oversized message\n");
            continue;
        }

        if (buf[0] == '\0') {
            if (debug)