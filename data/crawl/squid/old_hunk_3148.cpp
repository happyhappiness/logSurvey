        if (use_extension_dn) {
            extension_dn = strtok(NULL, " \n");
            if (!extension_dn) {
                fprintf(stderr, "%s: Invalid request\n", argv[0]);
                goto error;
            }
            rfc1738_unescape(extension_dn);
        }
