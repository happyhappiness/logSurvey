            gss_release_buffer(&min_stat, &status_string);
        }
        if (debug)
            fprintf(stderr, "%s| %s: %s failed: %s\n", LogTime(), PROGRAM,
                    function, buf);
        fprintf(stdout, "BH %s failed: %s\n", function, buf);
        if (log)
            fprintf(stderr, "%s| %s: User not authenticated\n", LogTime(),
                    PROGRAM);
        return (1);
    }
