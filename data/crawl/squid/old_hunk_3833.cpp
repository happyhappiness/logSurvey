            exit(1);
        }
    } else {
        fprintf(stderr, "%s: ERROR: No running copy\n", APP_SHORTNAME);
        exit(1);
    }

    /* signal successfully sent */