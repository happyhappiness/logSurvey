        }

        if (strncmp(buf, "YR", 2) && strncmp(buf, "KK", 2)) {
            debug("%s| %s: ERROR: Invalid request [%s]\n", LogTime(), PROGRAM, buf);
            fprintf(stdout, "BH Invalid request\n");
            continue;
        }