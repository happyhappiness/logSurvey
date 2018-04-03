            user = (char*)xmalloc(output_token.length + 1);
            if (user == NULL) {
                if (debug)
                    fprintf(stderr, "%s| %s: ERROR: Not enough memory\n", LogTime(),
                            PROGRAM);
                fprintf(stdout, "BH Not enough memory\n");
                goto cleanup;
