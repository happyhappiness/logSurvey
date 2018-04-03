            token = (char*)xmalloc(ska_base64_encode_len(spnegoTokenLength));
            if (token == NULL) {
                if (debug)
                    fprintf(stderr, "%s| %s: ERROR: Not enough memory\n", LogTime(),
                            PROGRAM);
                fprintf(stdout, "BH Not enough memory\n");
                goto cleanup;
