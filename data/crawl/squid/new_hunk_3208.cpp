            err = 1;
        }
        if (err) {
            debug("%s| %s: ERROR: Oversized message\n", LogTime(), PROGRAM);
            fprintf(stdout, "BH Oversized message\n");
            err = 0;
            continue;
        }

        debug("%s| %s: DEBUG: Got '%s' from squid (length: %d).\n", LogTime(), PROGRAM, buf, length);

        if (buf[0] == '\0') {
            debug("%s| %s: ERROR: Invalid request\n", LogTime(), PROGRAM);
            fprintf(stdout, "BH Invalid request\n");
            continue;
        }

        if (strlen(buf) < 2) {
            debug("%s| %s: ERROR: Invalid request [%s]\n", LogTime(), PROGRAM, buf);
            fprintf(stdout, "BH Invalid request\n");
            continue;
        }
