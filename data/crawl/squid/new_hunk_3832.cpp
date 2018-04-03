        }
    } else {
        if (opt_send_signal != SIGTERM) {
            fprintf(stderr, "%s: ERROR: No running copy\n", APP_SHORTNAME);
            exit(1);
        } else {
            fprintf(stderr, "%s: No running copy\n", APP_SHORTNAME);
            exit(0);
        }
    }