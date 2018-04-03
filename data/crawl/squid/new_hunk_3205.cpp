            }
            gss_release_buffer(&min_stat, &status_string);
        }
        debug("%s| %s: ERROR: %s failed: %s\n", LogTime(), PROGRAM, function, buf);
        fprintf(stdout, "BH %s failed: %s\n", function, buf);
        if (log)
            fprintf(stderr, "%s| %s: INFO: User not authenticated\n", LogTime(),
