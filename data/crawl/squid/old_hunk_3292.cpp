
        /* Check for invalid or blank entries */
        if ((username[0] == '\0') || (password[0] == '\0')) {
            fprintf(stderr, "Invalid Request\n");
            puts("ERR");
            fflush(stdout);
            continue;
        }
