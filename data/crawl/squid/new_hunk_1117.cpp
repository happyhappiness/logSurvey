            struct stat fstat;
            char *ktp;
#endif
            if (optarg)
                keytab_name = xstrdup(optarg);
            else {
                fprintf(stderr, "ERROR: keytab file not given\n");
                exit(1);
            }
            /*
             * Some sanity checks
             */
