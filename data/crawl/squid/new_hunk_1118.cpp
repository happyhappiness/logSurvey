#if HAVE_SYS_STAT_H
            struct stat dstat;
#endif
            if (optarg)
                rcache_dir = xstrdup(optarg);
            else {
                fprintf(stderr, "ERROR: replay cache directory not given\n");
                exit(1);
            }
            /*
             * Some sanity checks
             */
