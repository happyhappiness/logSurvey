        } else
#ifdef _SQUID_MSWIN_
        {
            fprintf(stderr, "%s: ERROR: Could not send ", appname);
            fprintf(stderr, "signal to Squid Service:\n");
            fprintf(stderr, "missing -n command line switch.\n");
            exit(1);
