                goto cleanup;
            if (major_status & GSS_S_CONTINUE_NEEDED) {
                if (debug)
                    fprintf(stderr, "%s| %s: INFO: continuation needed\n", LogTime(),
                            PROGRAM);
                fprintf(stdout, "NA %s\n", token);
                goto cleanup;